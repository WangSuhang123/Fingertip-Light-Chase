#include "usermanager.h"

// 实现单例方法（静态局部变量模式，C++11后线程安全）
UserManager& UserManager::instance()
{
    static UserManager manager; // 静态局部变量，程序运行时只初始化一次
    return manager;
}

// 实现构造函数
UserManager::UserManager() : m_isLogin(false)
{
    // 这里可以添加复杂的初始化逻辑，比如：
    // 1. 从配置文件读取上次登录的用户信息
    // 2. 初始化用户权限列表
    // 3. 连接数据库查询用户默认设置
}

// 实现设置用户信息的方法
void UserManager::setCurrentUser(const QString& userName, const QString& studentId, const QString& schoolName)
{
    m_userName = userName;
    m_studentId = studentId;
    m_schoolName = schoolName;
    m_isLogin = true;

    // 这里可以添加复杂逻辑，比如：
    // 1. 记录用户登录时间到日志
    // 2. 缓存用户的权限信息
    // 3. 保存登录状态到配置文件（记住登录）
}

// 实现获取用户信息的方法
QString UserManager::getUserName() const
{
    return m_userName;
}

QString UserManager::getStudentId() const
{
    return m_studentId;
}

QString UserManager::getSchoolName() const
{
    return m_schoolName;
}

bool UserManager::isLogin() const
{
    return m_isLogin;
}

// 实现退出登录的方法
void UserManager::logout()
{
    m_userName.clear();
    m_studentId.clear();
    m_schoolName.clear();
    m_isLogin = false;

    // 这里可以添加复杂逻辑，比如：
    // 1. 清除用户权限缓存
    // 2. 记录用户退出时间到日志
    // 3. 清空配置文件中的登录状态
}
