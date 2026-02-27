#ifndef NOCOPYPASTELINEEDIT_H
#define NOCOPYPASTELINEEDIT_H

#include <QLineEdit>
#include <QKeyEvent>


class NoCopyPasteLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit NoCopyPasteLineEdit(QWidget *parent = nullptr) : QLineEdit(parent) {
        // 禁用右键菜单
        setContextMenuPolicy(Qt::NoContextMenu);
    }

protected:
    void keyPressEvent(QKeyEvent *event) override {
        // 拦截 Ctrl+C, Ctrl+V, Ctrl+X, Ctrl+A (全选通常也建议禁用，视需求而定)
        if (event->modifiers() == Qt::ControlModifier) {
            switch (event->key()) {
            case Qt::Key_C: // 复制
            case Qt::Key_V: // 粘贴
            case Qt::Key_X: // 剪切
                event->ignore(); // 忽略事件，不执行默认操作
                return;
            default:
                break;
            }
        }
        // 其他按键正常处理
        QLineEdit::keyPressEvent(event);
    }
};


#endif // NOCOPYPASTELINEEDIT_H
