#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <QString>

// 全局单例，存储当前登录用户信息
class UserManager
{
public:

    // 仅声明单例方法，实现放在cpp中
    static UserManager& instance();

    // 禁止拷贝/赋值（依然保留，单例的核心要求）
    UserManager(const UserManager&) = delete;
    UserManager& operator=(const UserManager&) = delete;

    // 对外暴露的接口（仅声明）
    void setCurrentUser(const QString& userName, const QString& studentId, const QString& schoolName, int userStatus);
    QString getUserName() const;
    QString getStudentId() const;
    QString getSchoolName() const;
    int getUserStatus() const;
    bool isLogin() const;
    void logout();
private:
    // 私有构造（单例）
    UserManager();

    // 成员变量（依然是私有，封装不变）
    QString m_userName;
    QString m_studentId;
    QString m_schoolName;
    int m_userStatus;
    bool m_isLogin;
};

#endif // USERMANAGER_H
