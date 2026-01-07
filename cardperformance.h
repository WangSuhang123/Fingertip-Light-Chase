// #ifndef CARDPERFORMANCE_H
// #define CARDPERFORMANCE_H

// #include <QWidget>
// #include <QLabel>
// #include <QPropertyAnimation>

// namespace Ui {
// class CardPerformance;
// }

// class CardPerformance : public QWidget
// {
//     Q_OBJECT
//     Q_PROPERTY(qreal scale READ scale WRITE setScale)   //支持缩放宏

// public:
//     explicit CardPerformance(QWidget *parent = nullptr);
//     ~CardPerformance();

//     //对外接口
//     void setTitle(const QString &text);
//     void setValue(const QString &value);   // 设置核心数据（如 85）
//     void setDescription(const QString &text);  // 设置描述文本
//     void setIcon(const QPixmap &pix);      // 设置图标

// signals:
//     void clicked(); //按下信号

// protected:
// //     //触发事件
//     void enterEvent(QEnterEvent *event) override;
//     void leaveEvent(QEvent *event) override;
//     void mousePressEvent(QMouseEvent *event) override;
//     void mouseReleaseEvent(QMouseEvent *event) override;
//     //void paintEvent(QPaintEvent *event) override;

// private:

//     void animateScale(qreal target);
//     void initUiShadow();
//     //Hover 上浮动画,成员变量
//     qreal m_scale = 1.0;
//     QPropertyAnimation *m_anim;
//     qreal scale() const { return m_scale; }
//     void setScale(qreal s);



//     Ui::CardPerformance *ui;
// };

// #endif // CARDPERFORMANCE_H
#ifndef CARDPERFORMANCE_H
#define CARDPERFORMANCE_H

#include <QWidget>
#include <QPropertyAnimation>

namespace Ui {
class CardPerformance;
}

class CardPerformance : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(qreal scale READ scale WRITE setScale)

public:
    explicit CardPerformance(QWidget *parent = nullptr);
    ~CardPerformance();

    // 对外接口
    void setTitle(const QString &text);
    void setValue(const QString &value);
    void setDescription(const QString &text);
    void setIcon(const QPixmap &pixmap);

signals:
    void clicked();  // 点击信号

protected:
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;

private:
    void animateScale(qreal target);
    void initUiShadow();

    qreal scale() const { return m_scale; }
    void setScale(qreal s);

    Ui::CardPerformance *ui;
    QPropertyAnimation *m_anim;
    qreal m_scale = 1.0;
};

#endif // CARDPERFORMANCE_H
