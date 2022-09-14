#pragma once
#ifndef CHANGETEXT_H
#define CHANGETEXT_H
#include <QString>

class ChangeText
{
public:
    ChangeText();
    bool change(QString);
    QString getText();
private:
    QString text;
    QString preText;
    qint32 pos;
};



#endif // CHANGETEXT_H
