#ifndef MMDISTROYSYSTEM_H
#define MMDISTROYSYSTEM_H

class MMDistroySystem
{
public:
    ~MMDistroySystem();

    static MMDistroySystem *instance();
    static void disInstanc();
    static void disAllInstance();

private:
    static MMDistroySystem *__ins;

private:
    MMDistroySystem();
};

#endif // MMDISTROYSYSTEM_H
