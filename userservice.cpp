#include "userservice.h"
#include <QCryptographicHash> // Qt的加密库，用于MD5加密
#include <QDebug>
#include <QMessageBox>
UserService::UserService() {}


// 登录业务逻辑的核心实现
bool UserService::login(const QString &userName, const QString &password, const QString &studentId, const QString &schoolName)
{
    // 【业务逻辑1：参数非空校验】（可以把UI层的非空校验移到这里，让UI层更轻）
    if (userName.trimmed().isEmpty() || password.trimmed().isEmpty() ||
        studentId.trimmed().isEmpty() || schoolName.trimmed().isEmpty()) {
        qWarning() << "登录参数为空，校验失败";
        return false;
    }

    // 【业务逻辑2：密码加密】（比如MD5加密，假设数据库中存的是加密后的密码）
    QString encryptedPwd = encryptPassword(password);

    // 【业务逻辑3：调用DAO层查询数据库，验证用户】
    // 注意：这里调用的是DAO的verifyUser方法，//暂时没有实现 传入的是加密后的密码
    bool verifySuccess = m_userDao.verifyUserInfo(userName, encryptedPwd, studentId, schoolName);

    return verifySuccess;

}

// 封装用户存在性判断的业务逻辑
bool UserService::isUserExists(const QString &userName, const QString &studentId, const QString &schoolName)
{
    // 这里可以添加额外的业务逻辑，比如：只有特定学校的用户才允许查询
    if (schoolName.trimmed().isEmpty()) {
        qWarning() << "学校名称为空，无法判断用户是否存在";
        return false;
    }

    // 调用DAO层的方法
    return m_userDao.existsUserInfo(userName, studentId, schoolName);


}

bool UserService::registerUser(const QString &UserName, const QString &Password, const QString &StudentID, const QString &SchoolName, const QString EMail,const QString VerCode)
{
    //参数非空校验
    // 【业务逻辑1：参数非空校验】（可以把UI层的非空校验移到这里，让UI层更轻）
    if (UserName.trimmed().isEmpty() || Password.trimmed().isEmpty() ||
        StudentID.trimmed().isEmpty() || SchoolName.trimmed().isEmpty() || VerCode.trimmed().isEmpty()) {
        qWarning() << "登录参数为空，校验失败";
        return false;
    }else if(EMail.isEmpty()){
        qWarning() << "请输入有效的邮箱地址！";
        return false;
    }else if(VerCode.isEmpty()){
        qWarning() << "请输入有效的验证码！";
        return false;
    }
    // 【业务逻辑2：密码加密】（比如MD5加密，假设数据库中存的是加密后的密码）
    QString encryptedPwd = encryptPassword(Password);

    // 【业务逻辑3：调用DAO层插入数据库，验证用户】
    bool registerSuccess = m_userDao.registerUserInfo(UserName, encryptedPwd, StudentID, SchoolName,EMail);

    return registerSuccess;

}
//判断邮箱唯一性
bool UserService::isEMailExists(const QString &EMail)
{
    // 调用DAO层的方法
    return m_userDao.emailIsExist(EMail);

}
//判断是否修改密码成功  return是否成功
bool UserService::retrievePassword(const QString &UserName, const QString &Password, const QString &StudentID, const QString &SchoolName, const QString EMail, const QString VerCode)
{
    //参数非空校验
    // 【业务逻辑1：参数非空校验】（可以把UI层的非空校验移到这里，让UI层更轻）
    if (UserName.trimmed().isEmpty() || Password.trimmed().isEmpty() ||
        StudentID.trimmed().isEmpty() || SchoolName.trimmed().isEmpty() || VerCode.trimmed().isEmpty()) {
        qWarning() << "登录参数为空，校验失败";
        return false;
    }else if(EMail.isEmpty()){
        qWarning() << "请输入有效的邮箱地址！";
        return false;
    }else if(VerCode.isEmpty()){
        qWarning() << "请输入有效的验证码！";
        return false;
    }

    // 【业务逻辑2：密码加密】（比如MD5加密，假设数据库中存的是加密后的密码）
    QString encryptedPwd = encryptPassword(Password);

    bool retrieveSuccess = m_userDao.retrieveUserPassword(UserName,encryptedPwd,StudentID,SchoolName,EMail);

    return retrieveSuccess;
}


// 密码加密：MD5加密（Qt自带的QCryptographicHash实现）
QString UserService::encryptPassword(const QString &rawPwd)
{
    // 1. 将字符串转换为字节数组
    QByteArray byteArray = rawPwd.toUtf8();
    // 2. 计算MD5哈希值
    QByteArray hashArray = QCryptographicHash::hash(byteArray, QCryptographicHash::Md5);
    // 3. 转换为十六进制字符串（数据库中存的就是这个字符串）
    return hashArray.toHex();
}


