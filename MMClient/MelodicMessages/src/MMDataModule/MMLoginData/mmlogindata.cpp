#include "mmlogindata.h"

MMLoginData::MMLoginData()
    : MMDataBase()
{

}

MMLoginData::~MMLoginData()
{

}

QString MMLoginData::account() const
{
    return m_account;
}

void MMLoginData::setAccount(const QString &newAccount)
{
    m_account = newAccount;
}

QString MMLoginData::password() const
{
    return m_password;
}

void MMLoginData::setPassword(const QString &newPassword)
{
    m_password = newPassword;
}

void MMLoginData::parseData()
{

}

void MMLoginData::createData()
{

}

bool MMLoginData::isQuit() const
{
    return m_isQuit;
}

void MMLoginData::setIsQuit(bool newIsQuit)
{
    m_isQuit = newIsQuit;
}
