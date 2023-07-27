#ifndef MMLOGINDATA_H
#define MMLOGINDATA_H

#include "MMDataJsonBase.h"

class UserInfoData
{
public:
    UserInfoData();
    ~UserInfoData();

    const QString & account() const;
    void setAccount(const QString &newAccount);

    const QString &password() const;
    void setPassword(const QString &newPassword);

    bool isOnline() const;
    void setIsOnline(bool newIsOnline);

public:
    static UserInfoData *instance();
    static void disInstance();

private:
    static UserInfoData *__ins;

private:
    QString m_account;
    QString m_password;
    bool m_isOnline;
};

class MMLoginData : public MMDataJsonBase
{
public:
    MMLoginData(MMUInt32 mainCmd=MMMainCmd_None, MMUInt32 subCmd=MMMainCmd_None);
    ~MMLoginData();



    UserInfoData *userInfoData() const;
    void setUserInfoData(UserInfoData *newUserInfoData);

protected:
    virtual void parseData()override;
    virtual void createData()override;

private:
    UserInfoData *m_userInfoData;
};


#endif // MMLOGINDATA_H
