#ifndef MYTEXTEDIT_H
#define MYTEXTEDIT_H

#include "main.h"

class MyTextEdit : public QTextEdit
{
    Q_OBJECT

public:
    explicit MyTextEdit(QWidget* parent = 0) : QTextEdit(parent){}
protected:
    void keyPressEvent(QKeyEvent* r_key);

signals:
    void PressEnter();
public slots:
};

#endif // MYTEXTEDIT_H
