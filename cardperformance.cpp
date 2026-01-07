// #include "cardperformance.h"
// #include "ui_cardperformance.h"
// #include <QGraphicsDropShadowEffect>
// #include <QStyle>
// #include <QMouseEvent>
// #include <QTransform>

// CardPerformance::CardPerformance(QWidget *parent)
//     : QWidget(parent)
//     , ui(new Ui::CardPerformance)
// {
//     ui->setupUi(this);

//     // 关键：必须设置这三个属性，才能让 QSS 正确绘制背景
//     setAttribute(Qt::WA_StyledBackground);  // 允许 QSS 绘制 background/border
//     setAttribute(Qt::WA_Hover);             // 启用 hover 事件

//     // 设置动态类属性，让 QSS 能匹配（推荐方式）
//     setProperty("class", "CardPerformance");

//     // 默认主题
//     setProperty("theme", "blue");

//     //动画初始化
//     m_anim->setTargetObject(this);
//     m_anim->setPropertyName("scale");  // 需要 Q_PROPERTY
//     m_anim->setDuration(200);
//     m_anim->setEasingCurve(QEasingCurve::OutCubic);

//     initUiShadow();
//     // 初始状态刷新样式
//     style()->polish(this);
// }

// CardPerformance::~CardPerformance()
// {
//     delete ui;
// }

// //ui阴影样式定义
// void CardPerformance::initUiShadow()
// {
//     auto *shadow = new QGraphicsDropShadowEffect(this);
//     shadow->setBlurRadius(20);
//     shadow->setOffset(0, 6);
//     shadow->setColor(QColor(0, 0, 0, 60));
//     setGraphicsEffect(shadow);
// }

// void CardPerformance::setScale(qreal s)
// {
//     m_scale = s;
//     // 使用 transform 实现缩放（比 resize 更好，不会破坏布局）
//     QTransform()setTransform(QTransform().scale(s, s));

// }


// //内容定义接口
// //设置题目
// void CardPerformance::setTitle(const QString &text)
// {
//     ui->TitleLabel->setText(text);
// }


// //设置内容
// void CardPerformance::setValue(const QString &value)
// {
//     ui->dataLabel->setText(value);
// }


// //设置描述
// void CardPerformance::setDescription(const QString &text)
// {
//     ui->describeLabel->setText(text);
// }

// //设置图标
// void CardPerformance::setIcon(const QPixmap &pix)
// {
//     ui->iconLabel->setPixmap(pix);
// }

// void CardPerformance::enterEvent(QEnterEvent *event)
// {
//     setProperty("state", "hover");
//     style()->polish(this);
//     animateScale(1.03);  // 轻微放大
//     QWidget::enterEvent(event);
// }

// void CardPerformance::leaveEvent(QEvent *event)
// {
//     setProperty("state", "normal");
//     style()->polish(this);
//     animateScale(1.0);
//     QWidget::leaveEvent(event);
// }

// void CardPerformance::mousePressEvent(QMouseEvent *event)
// {
//     if (event->button() == Qt::LeftButton) {
//         setProperty("state", "pressed");
//         style()->polish(this);
//         animateScale(0.97);  // 按下缩小
//     }
//     QWidget::mousePressEvent(event);
// }

// void CardPerformance::mouseReleaseEvent(QMouseEvent *event)
// {
//     animateScale(1.03);  // 恢复 hover 状态
//     if (rect().contains(event->pos())) {
//         emit clicked();
//     }

//     // 如果鼠标释放时还在控件内，保持 hover，否则恢复 normal
//     if (rect().contains(mapFromGlobal(QCursor::pos()))) {
//         setProperty("state", "hover");
//     } else {
//         setProperty("state", "normal");
//         animateScale(1.0);
//     }
//     style()->polish(this);

//     QWidget::mouseReleaseEvent(event);
// }

// void CardPerformance::animateScale(qreal target)
// {
//     m_anim->stop();
//     m_anim->setStartValue(m_scale);
//     m_anim->setEndValue(target);
//     m_anim->start();
// }

#include "cardperformance.h"
#include "ui_cardperformance.h"
#include <QGraphicsDropShadowEffect>
#include <QMouseEvent>
#include <QTransform>
#include <QStyle>

CardPerformance::CardPerformance(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CardPerformance)
    , m_anim(new QPropertyAnimation(this))
{
    ui->setupUi(this);

    // 关键：让 QSS 能正确绘制背景、边框、圆角
    setAttribute(Qt::WA_StyledBackground);
    setAttribute(Qt::WA_Hover);

    // 让 QSS 的类选择器生效（CardPerformance {...}）
    setProperty("class", "CardPerformance");

    // 默认主题
    setProperty("theme", "white");
    setProperty("state", "normal");

    // 动画配置
    m_anim->setTargetObject(this);
    m_anim->setPropertyName("scale");
    m_anim->setDuration(200);
    m_anim->setEasingCurve(QEasingCurve::OutCubic);

    // 阴影效果
    initUiShadow();

    // 初始刷新样式
    style()->polish(this);
}

CardPerformance::~CardPerformance()
{
    delete ui;
}

void CardPerformance::initUiShadow()
{
    auto *shadow = new QGraphicsDropShadowEffect(this);
    shadow->setBlurRadius(20);
    shadow->setOffset(0, 6);
    shadow->setColor(QColor(0, 0, 0, 60));
    setGraphicsEffect(shadow);
}

void CardPerformance::setScale(qreal s)
{
    if (qFuzzyCompare(m_scale, s))
        return;

    m_scale = s;
    updateGeometry();  // 通知父布局重新计算大小
}

// ========== 对外接口 ==========
void CardPerformance::setTitle(const QString &text)
{
    ui->TitleLabel->setText(text);
}

void CardPerformance::setValue(const QString &value)
{
    ui->dataLabel->setText(value);
}

void CardPerformance::setDescription(const QString &text)
{
    ui->describeLabel->setText(text);
}

void CardPerformance::setIcon(const QPixmap &pixmap)
{
    ui->iconLabel->setPixmap(pixmap);
}

// ========== 鼠标事件 ==========
void CardPerformance::enterEvent(QEnterEvent *event)
{
    setProperty("state", "hover");
    style()->polish(this);
    animateScale(1.03);
    QWidget::enterEvent(event);
}

void CardPerformance::leaveEvent(QEvent *event)
{
    setProperty("state", "normal");
    style()->polish(this);
    animateScale(1.0);
    QWidget::leaveEvent(event);
}

void CardPerformance::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        setProperty("state", "pressed");
        style()->polish(this);
        animateScale(0.97);
    }
    QWidget::mousePressEvent(event);
}

void CardPerformance::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        animateScale(1.03);  // 先恢复到 hover 状态

        if (rect().contains(event->pos())) {
            emit clicked();
        }

        // 判断释放时鼠标是否还在控件内
        if (underMouse()) {
            setProperty("state", "hover");
        } else {
            setProperty("state", "normal");
            animateScale(1.0);
        }
        style()->polish(this);
    }
    QWidget::mouseReleaseEvent(event);
}

QSize CardPerformance::sizeHint() const
{
    QSize base = QWidget::sizeHint();
    return QSize(static_cast<int>(base.width() * m_scale),
                 static_cast<int>(base.height() * m_scale));
}

QSize CardPerformance::minimumSizeHint() const
{
    return sizeHint();
}

void CardPerformance::animateScale(qreal target)
{
    m_anim->stop();
    m_anim->setStartValue(m_scale);
    m_anim->setEndValue(target);
    m_anim->start();
}





