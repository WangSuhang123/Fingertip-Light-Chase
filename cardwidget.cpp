#include "cardwidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPainter>
#include <QMouseEvent>
#include <QStyle>

CardWidget::CardWidget(QWidget *parent)
    : QFrame(parent)
{
    // 第一步：清空Designer可能自动设置的布局（避免冲突）
    if (layout()) {
        delete layout();
    }

    initUi();

    setAttribute(Qt::WA_StyledBackground);
    setAttribute(Qt::WA_Hover);
    setCursor(Qt::PointingHandCursor);
    setProperty("state", "normal");

    //动画初始化
    m_anim = new QPropertyAnimation(this, "scale", this);
    m_anim->setDuration(160);
    m_anim->setEasingCurve(QEasingCurve::OutCubic);
}

void CardWidget::initUi()
{

    iconLabel  = new QLabel(this);
    titleLabel = new QLabel(this);
    descLabel  = new QLabel(this);

    iconLabel->setFixedSize(40, 40);
    iconLabel->setScaledContents(true);

    titleLabel->setStyleSheet("font-size:16px; font-weight:600;padding-top: 18px;");
    descLabel->setStyleSheet("color:#666666;margin-top:5px;");


    auto textLayout = new QVBoxLayout;
    textLayout->addWidget(titleLabel);
    textLayout->addWidget(descLabel);
    textLayout->setSpacing(4);
    textLayout->setContentsMargins(0, 0, 0, 0);
    // 可选：设置文本垂直对齐，避免标签因文本基线问题显得间距大
    textLayout->setAlignment(Qt::AlignTop);

    auto mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(iconLabel);
    mainLayout->addLayout(textLayout);
    mainLayout->setSpacing(12);
    mainLayout->setContentsMargins(16, 16, 16, 16);

    // 强制设置布局（覆盖UI设计师的默认布局）
    // 强制重置布局（确保完全覆盖Designer的默认布局）
    QLayout *oldLayout = layout();
    if (oldLayout) {
        oldLayout->deleteLater();
    }
    setLayout(mainLayout);
}

void CardWidget::setIcon(const QPixmap &pix)
{
    iconLabel->setPixmap(pix);
}

void CardWidget::setTitle(const QString &text)
{
    titleLabel->setText(text);
}

void CardWidget::setDescription(const QString &text)
{
    descLabel->setText(text);
}

void CardWidget::setScale(qreal s)
{
    m_scale = s;
    update();
}

void CardWidget::animateScale(qreal target)
{
    m_anim->stop();
    m_anim->setStartValue(m_scale);
    m_anim->setEndValue(target);
    m_anim->start();
}

void CardWidget::enterEvent(QEnterEvent *)
{
    setProperty("state", "hover");
    style()->polish(this);
    animateScale(1.03);
}

void CardWidget::leaveEvent(QEvent *)
{
    setProperty("state", "normal");
    style()->polish(this);
    animateScale(1.0);
}

void CardWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        setProperty("state", "pressed");
        style()->polish(this);
    }
    QFrame::mousePressEvent(event);
}

void CardWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (rect().contains(event->pos())) {
        emit clicked();
        setProperty("state", "hover");
    } else {
        setProperty("state", "normal");
    }
    style()->polish(this);
    QFrame::mouseReleaseEvent(event);
}

void CardWidget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);

    p.translate(width() / 2, height() / 2);
    p.scale(m_scale, m_scale);
    p.translate(-width() / 2, -height() / 2);

    QFrame::paintEvent(event);
}
