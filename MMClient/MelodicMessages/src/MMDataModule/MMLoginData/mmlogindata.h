#ifndef MMLOGINDATA_H
#define MMLOGINDATA_H

#include "MMDataBase.h"

class MMLoginData : public MMDataBase
{
public:
    MMLoginData();
    ~MMLoginData();

    QString account() const;
    void setAccount(const QString &newAccount);

    QString password() const;
    void setPassword(const QString &newPassword);

    virtual void parseData()override;
    virtual void createData()override;
    bool isQuit() const;
    void setIsQuit(bool newIsQuit);

private:
    QString m_account;
    QString m_password;
    bool m_isQuit;
};


#endif // MMLOGINDATA_H
