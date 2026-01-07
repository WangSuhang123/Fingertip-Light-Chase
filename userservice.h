#ifndef USERSERVICE_H
#define USERSERVICE_H
// 引入DAO层，Service层依赖DAO层
#include "userdao.h"

class UserService
{
public:
    UserService();

    //用户登录验证（业务逻辑入口），return 登录是否成功
    bool login(const QString &userName, const QString &password, const QString &studentId, const QString &schoolName);

    //判断用户是否存在（业务层封装） @return 用户是否存在
    bool isUserExists(const QString &userName, const QString &studentId, const QString &schoolName);
    //用户注册   return是否成功
    bool registerUser(const QString &UserName, const QString &Password, const QString &StudentID, const QString &SchoolName, const QString EMail,const QString VerCode);
    //判断邮箱唯一性
    bool isEMailExists(const QString& EMail);

    //判断是否修改密码成功  return是否成功
    bool retrievePassword(const QString &UserName, const QString &Password, const QString &StudentID, const QString &SchoolName, const QString EMail,const QString VerCode);

private:
    //密码加密（业务逻辑示例，比如MD5加密） return 加密后的密码字符串
    QString encryptPassword(const QString &rawPwd);

    // 持有DAO层对象，Service层通过DAO层操作数据库
    UserDao m_userDao;

};

#endif // USERSERVICE_H
