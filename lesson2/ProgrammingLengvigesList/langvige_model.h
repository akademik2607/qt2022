#ifndef LANGVIGEMODEL_H
#define LANGVIGEMODEL_H
#include <QStringList>
#include <QAbstractTableModel>


class LangvigeModel : public QAbstractTableModel
{


public:
    LangvigeModel();
    int columnCount(const QModelIndex &parent = QModelIndex())const  override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    Qt::ItemFlags	flags(const QModelIndex &index) const override;
    Qt::DropActions supportedDropActions() const override;
    QStringList mimeTypes() const override;
    QMimeData* mimeData(const QModelIndexList &indexes) const override;
    bool canDropMimeData(const QMimeData *data,
        Qt::DropAction action, int row, int column, const QModelIndex &parent) const override;
    bool dropMimeData(const QMimeData *data,
        Qt::DropAction action, int row, int column, const QModelIndex &parent) override;

    bool addData(const QVariant &value);
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    ~LangvigeModel(){};
private:
    QVector<QString*> langviges;
    QVector<QIcon*> icons;
    void swapIcons(size_t icon_1, size_t icon_2);


};

#endif // LANGVIGEMODEL_H
