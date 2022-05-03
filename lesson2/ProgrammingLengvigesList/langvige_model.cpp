#include "langvige_model.h"
#include <QColor>
#include <QMimeData>
#include <QIODevice>
#include <QIcon>

LangvigeModel::LangvigeModel()
{
    langviges.append(new QString{"C++"});
    langviges.append(new QString{"Python"});
    langviges.append(new QString{"Java"});
    langviges.append(new QString{"C#"});
    langviges.append(new QString{"PHP"});
    langviges.append(new QString{"JavaScript"});

    icons.append(new QIcon("../c++.png"));
    icons.append(new QIcon("../python.png"));
    icons.append(new QIcon("../java.png"));
    icons.append(new QIcon("../c-sharp.png"));
    icons.append(new QIcon("../php.png"));
    icons.append(new QIcon("../JavaScript.png"));
}

int LangvigeModel::columnCount(const QModelIndex &parent)const  {
    Q_UNUSED(parent);
    return 2;
}

int LangvigeModel::rowCount(const QModelIndex &parent)const  {
    Q_UNUSED(parent);
    return langviges.size();
}

QVariant LangvigeModel::data(const QModelIndex &index, int role) const {
        if(role == Qt::DisplayRole){
            return *(langviges.at(index.row()));

        }
        if(role == Qt::DecorationRole) {
            return *(icons.at(index.row()));
        }
        return QVariant{};
}

bool LangvigeModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(role == Qt::EditRole) {
        langviges[index.row()] = new QString{ value.toString()};
        return true;
    }

    return true;

}

Qt::ItemFlags LangvigeModel::flags(const QModelIndex &index) const
{
    return Qt::ItemIsEditable | Qt::ItemIsDragEnabled | Qt:: ItemIsDropEnabled | QAbstractItemModel::flags(index);
}

Qt::DropActions LangvigeModel::supportedDropActions() const
{
    return Qt::CopyAction | Qt::MoveAction;
}

QStringList LangvigeModel::mimeTypes() const
{
    QStringList types;
    types << "application/vnd.text.list";
    types << "text/plain";
    return types;
}

QMimeData *LangvigeModel::mimeData(const QModelIndexList &indexes) const
{
    QMimeData *mimeData = new QMimeData;
    QByteArray encodedData;

    QDataStream stream(&encodedData, QIODevice::WriteOnly);

    int startIndex {-1};
    for (const QModelIndex &index : indexes) {
        if (index.isValid()) {
            QString text = data(index, Qt::DisplayRole).toString();
            stream << text;

            startIndex = index.row();
        }
    }


    mimeData->setData("application/vnd.text.list", encodedData);

    mimeData->setText(QString{QString::number(startIndex)});



    return mimeData;
}

bool LangvigeModel::canDropMimeData(const QMimeData *data,
    Qt::DropAction action, int row, int column, const QModelIndex &parent) const
{
    Q_UNUSED(action);
    Q_UNUSED(row);
    Q_UNUSED(parent);

    if (!data->hasFormat("application/vnd.text.list"))
        return false;

    if (column > 0)
        return false;

    return true;
}


bool LangvigeModel::dropMimeData(const QMimeData *data,
    Qt::DropAction action, int row, int column, const QModelIndex &parent)
{
    if (!canDropMimeData(data, action, row, column, parent))
        return false;

    if (action == Qt::IgnoreAction)
        return true;

    int beginRow;

        if (row != -1)
            beginRow = row;
        else if (parent.isValid())
            beginRow = parent.row();
        else
            beginRow = rowCount(QModelIndex());

        if(beginRow >= langviges.size()) return false;

        QByteArray encodedData = data->data("application/vnd.text.list");
        int dropStart = data->text().toInt();
        QDataStream stream(&encodedData, QIODevice::ReadOnly);
        QStringList newItems;
        int rows = 0;

        while (!stream.atEnd()) {
            QString text;
            stream >> text;

            newItems << text;
            ++rows;
        }

        insertRows(beginRow, rows, QModelIndex());
            for (const QString &text : qAsConst(newItems)) {
                QModelIndex idx_s = index(beginRow, 0, QModelIndex());
                QModelIndex idx_e = index(dropStart, 0, QModelIndex());

                QString* result = langviges.at(beginRow);
                setData(idx_e, *result);
                setData(idx_s, text);
                swapIcons(beginRow, dropStart);
                beginRow++;
            }

            return true;
}

bool LangvigeModel::addData(const QVariant &value)
{
    beginInsertRows(QModelIndex(), langviges.size() - 1, langviges.size() - 1 );
    langviges.append(new QString{value.toString()});
    icons.append(new QIcon{"../c++.png"});

    endInsertRows();


    return true;
}

bool LangvigeModel::removeRows(int row, int count, const QModelIndex &parent)
{
    if(row == -1) return false;
    beginRemoveRows(parent, row, row);
    langviges.remove(row);
    icons.removeAt(row);
    endRemoveRows();
    return true;
}

void LangvigeModel::swapIcons(size_t icon_1, size_t icon_2)
{
    icons.swapItemsAt(icon_1, icon_2);
}


