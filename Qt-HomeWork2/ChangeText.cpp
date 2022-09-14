#include "ChangeText.h"

#define MIN(a,b) (a<b) ? a : b

ChangeText::ChangeText()
{
    text = "";
    preText = "";
    pos = 0;
}

bool ChangeText::change(QString istr)
{
    qint32 length = MIN(MIN(text.length(),istr.length()),pos);
    preText = "";
    for(qint32 i=0;i<length;i++)
    {
        if(text[i] != istr[i])
        {
            pos = i;
            break;
        }
    }
    const QChar * arStr = istr.constData();
    qint32 ppos = 0,lastp=-1;
    bool chg = false;
    for(qint32 fnd = istr.indexOf("#@",pos); fnd != -1 && lastp != pos;fnd=istr.indexOf("#@",pos))
    {

        preText.insert(preText.length(), &arStr[ppos],fnd);
        lastp = pos;
        pos = fnd;
        int r = istr.indexOf("@",fnd+3);
        if(r!=-1){
            if(arStr[fnd+2] == 'R' && arStr[fnd+3] == 'U' && arStr[fnd+4] == 'B'){
                preText+="₽";
                pos=r+1;
                chg=true;
            }
            else if(arStr[fnd+2] == 'C' && arStr[fnd+3] == 'P' && arStr[fnd+4] == 'Y'){
                preText+="©";
                pos=r+1;
                chg=true;
            }
            else if(arStr[fnd+2] == 'E' && arStr[fnd+3] == 'U' && arStr[fnd+4] == 'R'){
                preText+="€";
                pos=r+1;
                chg=true;
            }
            else if(arStr[fnd+2] == 'P' && arStr[fnd+3] == 'R' && arStr[fnd+4] == 'M'){
                preText+="‰";
                pos=r+1;
                chg=true;
            }
            else if(arStr[fnd+2] == 'R' && arStr[fnd+3] == 'E' && arStr[fnd+4] == 'G'){
                preText+="®";
                pos=r+1;
                chg=true;
            }
        }
        preText.insert(preText.length(), &arStr[pos], istr.length() - pos);
    }
    return chg;
}

QString ChangeText::getText(){
    text = preText;
    return text;
}
