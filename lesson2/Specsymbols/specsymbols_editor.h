#ifndef SPECSYMBOLSEDITOR_H
#define SPECSYMBOLSEDITOR_H

#include <QString>
#include <QHash>
#include <QPlainTextEdit>


class SpecsymbolsEditor
{
public:
    SpecsymbolsEditor(QPlainTextEdit* textEdit);
    bool indexSpecsymbolBorder(const QString & str, int offset);
private:
    QPlainTextEdit* edit;
    QHash<QString, QString> specsymbols
        {{QString("RUB"), QString("₽")},
         {QString("EUR"), QString("€")},
         {QString("ROP"), QString("®")},
         {QString("COP"), QString("©")},
         {QString("PROM"), QString("‰")}};
    QString currentSymbol;
    int currentOffsetStart;
    int currentOffsetEnd;
    bool isNeedChange;
    QString changeSpecsymbol(QString& str);
};

#endif // SPECSYMBOLSEDITOR_H
