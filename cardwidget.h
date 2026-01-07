#ifndef CARDWIDGET_H
#define CARDWIDGET_H

#include <QFrame>
#include <QLabel>
#include <QPropertyAnimation>

class CardWidget : public QFrame
{
    Q_OBJECT
    Q_PROPERTY(qreal scale READ scale WRITE setScale)

public:
    explicit CardWidget(QWidget *parent = nullptr);

    void setIcon(const QPixmap &pix);
    void setTitle(const QString &text);
    void setDescription(const QString &text);

    qreal scale() const { return m_scale; }
    void setScale(qreal s);

signals:
    void clicked();

protected:
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    void animateScale(qreal target);
    void initUi();

private:
    QLabel *iconLabel;
    QLabel *titleLabel;
    QLabel *descLabel;

    qreal m_scale = 1.0;
    QPropertyAnimation *m_anim;
};

#endif // CARDWIDGET_H
