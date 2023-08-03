#ifndef __MM_THREADPOOL_H__
#define __MM_THREADPOOL_H__

/**
 *  线程池
 */

#include <cassert>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <functional>
#include "MMCommon.h"

#define MM_THREADPOOL_SIZE  8

class MMThreadPool {
public:
    MMThreadPool(int poolSize=MM_THREADPOOL_SIZE/2) {
        if (poolSize < MM_THREADPOOL_SIZE) {
            for (size_t i = 0; i < poolSize; ++i) {
                m_workers.emplace_back(std::bind(&MMThreadPool::workerFunction, this));
            }
        }
        else {
            MMError("create thread number: %d error", poolSize);
        }
    }
    ~MMThreadPool() {
        {
            std::unique_lock<std::mutex> lock(m_queue_mutex);
            m_stop = true;
        }

        m_condition.notify_all();
        for (std::thread &worker : m_workers) {
            worker.join();
        }
    }

    virtual void workerFunction() {
        while (true) {
            std::function<void()> task;
            {
                std::unique_lock<std::mutex> lock(m_queue_mutex);
                m_condition.wait(lock, [this] { return m_stop || !m_tasks.empty(); });

                if (m_stop && m_tasks.empty()) {
                    return;
                }

                task = std::move(m_tasks.front());
                m_tasks.pop();
            }
            task(); // Execute the task with the stored parameter
        }
    }
    
    template <class F, class... Args>
    void enqueue(F&& f, Args&&... args) {
        {
            std::unique_lock<std::mutex> lock(m_queue_mutex);

            // Store the task with the parameter in the task queue
            m_tasks.emplace([f, args...]() { f(args...); });
        }
        m_condition.notify_one();
    }


public:
    static MMThreadPool *instance() {
        static MMThreadPool *__threadpool = new MMThreadPool;
        return __threadpool;
    }

private:
    std::vector<std::thread> m_workers;
    std::queue<std::function<void()>> m_tasks;
    std::mutex m_queue_mutex;
    std::condition_variable m_condition;
    std::atomic<bool> m_stop;

private:
    /* 不允许拷贝构造、赋值、移动构造以及移动赋值 */
    MMThreadPool(const MMThreadPool &) = delete;
    MMThreadPool(MMThreadPool &&) = delete;
    MMThreadPool &operator=(const MMThreadPool &) = delete;
    MMThreadPool &operator=(MMThreadPool &&) = delete;
};

#endif // __MM_THREADPOOL_H__