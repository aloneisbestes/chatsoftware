#include "mmlogindata.h"

UserInfoData *UserInfoData::__ins=nullptr;

MMLoginData::MMLoginData(MMUInt32 mainCmd, MMUInt32 subCmd)
    : MMDataJsonBase(mainCmd, subCmd)
{

}

MMLoginData::~MMLoginData()
{

}

void MMLoginData::parseData()
{

}

void MMLoginData::createData()
{

}

UserInfoData *MMLoginData::userInfoData() const
{
    return m_userInfoData;
}

void MMLoginData::setUserInfoData(UserInfoData *newUserInfoData)
{
    m_userInfoData = newUserInfoData;
}

UserInfoData::UserInfoData()
{

}

UserInfoData::~UserInfoData()
{

}

const QString &UserInfoData::account() const
{
    return m_account;
}

void UserInfoData::setAccount(const QString &newAccount)
{
    m_account = newAccount;
}

const QString &UserInfoData::password() const
{
    return m_password;
}

void UserInfoData::setPassword(const QString &newPassword)
{
    m_password = newPassword;
}

bool UserInfoData::isOnline() const
{
    return m_isOnline;
}

void UserInfoData::setIsOnline(bool newIsOnline)
{
    m_isOnline = newIsOnline;
}

UserInfoData *UserInfoData::instance()
{
    if (UserInfoData::__ins == nullptr) {
        UserInfoData::__ins=new UserInfoData;
    }
    return UserInfoData::__ins;
}

void UserInfoData::disInstance()
{
    if (UserInfoData::__ins)
        delete UserInfoData::__ins;
}
