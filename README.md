# 指尖逐光 (Fingertip-Light-Chase)

![指尖逐光](res/banner.png)

## 📌 项目介绍

**指尖逐光**是一个基于 Qt 开发的跨平台打字测速与比赛系统，致力于为用户提供高效、专业、有趣的打字训练环境。本系统集打字练习、赛事发布、在线比赛、成绩统计、数据可视化于一体，帮助用户提升打字速度和准确性。

## 🔧 核心功能

### 1. 打字练习模块
- 标准打字练习与实时速度检测
- 多种练习模式和难度选择
- 实时反馈和错误提示
- 练习成绩记录与分析

### 2. 比赛系统
- 赛事发布与管理
- 比赛大厅与在线参赛
- 实时比赛排名
- 比赛成绩记录与统计

### 3. 排行榜系统
- 个人成绩记录
- 全局排行榜
- 历史最佳成绩展示

### 4. 后台管理系统
- 用户管理
- 比赛管理
- 文章管理
- 数据统计与分析

### 5. 数据可视化
- 个人打字数据统计图表
- 历史成绩趋势分析
- 比赛数据可视化展示

## 🛠️ 技术架构

### 技术栈
- **前端框架**：Qt 6.10.1
- **UI 设计**：Qt Designer
- **数据库**：MYSQL
- **网络通信**：Qt Network
- **数据可视化**：Qt Charts

### 项目结构

```
Fingertip-Light-Chase/
├── res/             # 资源文件
│   ├── icon/        # 图标
│   └── ...          # 其他资源
├── *.cpp            # 源文件
├── *.h              # 头文件
├── *.ui             # UI 设计文件
├── Fingertip-Light-Chase.pro  # Qt 项目文件
└── README.md        # 项目说明文档
```

### 核心模块

| 模块 | 主要职责 | 文件位置 |
|------|---------|----------|
| 用户管理 | 登录、注册、找回密码 | loginwidget.cpp, registerwidget.cpp, retrievewidget.cpp |
| 练习系统 | 打字练习、速度检测 | practicewidget.cpp, practicesetupdialog.cpp |
| 比赛系统 | 赛事发布、在线比赛 | CompetitionPublish.cpp, CompetitionLobbyWidget.cpp |
| 排行榜 | 成绩排名、历史记录 | LeaderboardFeature.cpp |
| 数据可视化 | 数据统计、图表展示 | DataVisualization.cpp, ChartService.cpp |
| 后台管理 | 系统管理功能 | ComprehensiveManagement.cpp |
| 文章管理 | 文章上传、管理 | uploadArticle.cpp, articledao.cpp |
| 数据库 | 数据存储、管理 | databasemanager.cpp, *.dao.cpp |

## 📦 安装与使用

### 环境要求
- Qt 5.15+ 开发环境
- C++11 兼容编译器
- Windows 10+ / macOS / Linux

### 构建步骤
1. 克隆项目到本地
   ```bash
   git clone https://github.com/WangSuhang123/Fingertip-Light-Chase.git
   ```

2. 使用 Qt Creator 打开项目
   - 打开 `Fingertip-Light-Chase.pro` 文件
   - 配置构建套件
   - 构建项目

3. 运行应用
   - 构建完成后，运行生成的可执行文件

### 使用说明
1. **注册/登录**：首次使用需要注册账号，然后登录系统
2. **打字练习**：在练习界面选择文章和难度，开始练习
3. **参加比赛**：在比赛大厅查看并参加正在进行的比赛
4. **查看排行榜**：查看个人和全局排名
5. **数据统计**：查看个人打字数据和历史趋势
6. **后台管理**：管理员可以管理用户、比赛和文章

## 🤝 贡献

欢迎提交 Issue 和 Pull Request 来帮助改进这个项目！

## 📞 联系我们

- **GitHub**：[WangSuhang123](https://github.com/WangSuhang123)
- **邮箱**：wangsuhang7984@foxmail.com

## 💡 寄语

指尖生花，逐光而行；
愿每一次敲击，都成为你进步的力量。

## 📄 许可证

本项目采用 MIT 许可证，详情请查看 LICENSE 文件。

## 📄 项目展示

![登录页面](:/res/login.png)


![操作主页面](:/res/main.png)