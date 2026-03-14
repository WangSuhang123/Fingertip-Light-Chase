#ifndef USERDAO_H
#define USERDAO_H

#include <QString>

class UserDao
{
public:
    UserDao();

    ////验证用户信息，登录
    //bool verifyUserInfo(const QString& UserName, const QString& Password,const QString& StudentID, const QString& SchoolName);
    // // 登录验证，同时返回 userID 和 userStatus
    bool verifyUserInfo(const QString& UserName, const QString& Password,const QString& StudentID, const QString& SchoolName,int& userId,int& userStatus);

    //判断用户是否存在，通过姓名，学号，学校名称
    bool existsUserInfo(const QString& UserName,const QString& StudentID, const QString& SchoolName);

    //注册用户逻辑
    bool registerUserInfo(const QString& UserName, const QString& Password,const QString& StudentID, const QString& SchoolName,const QString EMail);
    //检测邮箱是否是唯一值，是否已经被注册了
    bool emailIsExist(const QString& EMail);

    //忘记-找回密码逻辑
    bool retrieveUserPassword(const QString& UserName, const QString& Password,const QString& StudentID, const QString& SchoolName,const QString& EMail);

    //获取用户的权限
    int getUserStatus(const QString &UserName, const QString &StudentID, const QString &SchoolName);

    
    //获取用的id号
    int getUserID(const QString& UserName, const QString& StudentID, const QString& SchoolName);

};

#endif // USERDAO_H
