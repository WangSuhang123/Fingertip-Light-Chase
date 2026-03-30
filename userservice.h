#ifndef USERSERVICE_H
#define USERSERVICE_H
#include <QObject>
// 引入DAO层，Service层依赖DAO层
#include "userdao.h"

class UserService : public QObject
{
    Q_OBJECT

public:
    UserService(QObject* parent = nullptr);
    ~UserService();

    // 登录验证（只查询一次数据库）
// 返回是否登录成功，同时返回 userId 和 userStatus
    bool login(const QString& userName,const QString& password, const QString& studentId,const QString& schoolName,int& userId,int& userStatus);

    //判断用户是否存在（业务层封装） @return 用户是否存在
    bool isUserExists(const QString &userName, const QString &studentId, const QString &schoolName);
    //用户注册   return是否成功
    bool registerUser(const QString &UserName, const QString &Password, const QString &StudentID, const QString &SchoolName, const QString EMail,const QString VerCode);
    //判断邮箱唯一性
    bool isEMailExists(const QString& EMail);

    //判断是否修改密码成功  return是否成功
    bool retrievePassword(const QString &UserName, const QString &Password, const QString &StudentID, const QString &SchoolName, const QString EMail,const QString VerCode);

    //获取用户的权限和id号
    int getUserStatus(const QString& UserName, const QString& StudentID, const QString& SchoolName);

    //获取用户id
    int getUserID(const QString& UserName, const QString& StudentID, const QString& SchoolName);


    //管理系统操作
    //查询登录管理员学校内的所有成员
    QSqlQueryModel* selectAllInfoFromUserInfo(const QString& schoolName);
    //条件查询
    QSqlQueryModel* queryUserByDynamicField(const QString& schoolName,const QString& fieldName,const QString& keyword);
    //修改
    bool updateUserField(int userId, const QString& fieldName, const QString& newValue);
    //删除
    bool deleteUser(int userId);


private:
    //密码加密（业务逻辑示例，比如MD5加密） return 加密后的密码字符串
    QString encryptPassword(const QString &rawPwd);

    // 持有DAO层对象，Service层通过DAO层操作数据库
    UserDao m_userDao;

};

#endif // USERSERVICE_H
