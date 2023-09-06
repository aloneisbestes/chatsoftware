#ifndef MMLOGINDATA_H
#define MMLOGINDATA_H

#include "MMBaseDataJson.h"

struct MMUserData
{
    int m_userId;   // 用户id
    bool m_isDelete;    // 是否被注销
    bool m_isOnline;    // 是否在线
    std::string m_account;  // 用户名
    std::string m_password; // 密码
    std::string m_userAvatar;   // 用户头像
    std::string m_nickname; // 用户昵称
    std::string m_phone; // 用户电话
    std::string m_email;   // 用户邮箱
    std::string m_lastTime; // 最后登录时间
    MMUserData()
        : m_userId(-1), m_isDelete(false), m_isOnline(false)
    {}
};

class MMLoginData : public MMBaseDataJson
{
public:
    MMLoginData(MMUInt32 mainCmd=MMMainCmd_None, MMUInt32 subCmd=MMMainCmd_None);
    ~MMLoginData();

    // 获取和设置用户
    void setMMUserData(const MMUserData &userData) { m_userData= userData; }
    const MMUserData& getMMUserData() const { return m_userData; }
    // 获取用户数据的const引用
    MMUserData &getMMUserData_cite() { return m_userData; }

protected:
    // 将子类对象序列化为json数据
    virtual void serializedData()override;

    // 将json数据序列化为子类对象中的数据
    virtual void deserializedData()override;

private:
    MMUserData m_userData;
};

#endif // MMLOGINDATA_H
