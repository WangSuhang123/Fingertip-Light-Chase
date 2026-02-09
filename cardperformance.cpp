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





