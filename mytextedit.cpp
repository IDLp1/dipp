#include "mytextedit.h"

void MyTextEdit::keyPressEvent(QKeyEvent *r_key)
{
    if(r_key->key() == 16777220) //кнопка enter
    {
        if(r_key->modifiers() & Qt::ShiftModifier)
        {
            QTextEdit::keyPressEvent(r_key);
        }
        else
            emit PressEnter();
    }
    else
        QTextEdit::keyPressEvent(r_key);
}

