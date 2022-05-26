#include "specsymbols_editor.h"
#include <QRegularExpression>

#include <QDebug>


SpecsymbolsEditor::SpecsymbolsEditor( QPlainTextEdit* textEdit)
    : edit{textEdit}, currentOffsetStart{0}
{
    QString str = edit->toPlainText();
    qDebug() << str;
    bool hasSpecsymbol = indexSpecsymbolBorder(str, currentOffsetStart);
    while(hasSpecsymbol) {
        if(isNeedChange){
            str = changeSpecsymbol(str);
            edit->setPlainText(str);
        }
        ++currentOffsetStart;
        hasSpecsymbol = indexSpecsymbolBorder(str, currentOffsetStart);
    }
}

bool SpecsymbolsEditor::indexSpecsymbolBorder(const QString & str, int offset) {
    QRegularExpression re(QString("(#@)(.*)(@)"));
    QRegularExpressionMatch match = re.match(str, offset);
    if(match.hasMatch()){
       if(specsymbols.contains(match.captured(2))) {
           currentOffsetStart = match.capturedStart(1);
           currentOffsetEnd = match.capturedEnd(3);
           currentSymbol = specsymbols.take(match.captured(2));
           isNeedChange = true;
           return true;
       } else {
           isNeedChange = false;
           return true;
       }
    }

    return false;
}

QString SpecsymbolsEditor::changeSpecsymbol(QString& str) {
    return str.replace(currentOffsetStart, (currentOffsetEnd - currentOffsetStart), currentSymbol);
}



