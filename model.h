#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QStyledItemDelegate>
#include <QPainter>
#include <QStandardItemModel>
#include <QAbstractItemModel>
#include <QListView>
#include <QUuid>

#include "entity.h"
#include "datasetpar.h"
#include "dataset.h"

class ItemListModel : public QAbstractItemModel
{
    Q_OBJECT
public:

    ItemListModel(QListView *view, DataSet *dataset);

    void loadFromDatabase();

    void refresh(int row);
    void clear();
    DataSetPar *appendItem(Item *item);

    bool insertRows(int position, int rows, const QModelIndex &parent = QModelIndex()) override;
    bool removeRows(int position, int rows, const QModelIndex &parent = QModelIndex()) override;

    QVariant data(const QModelIndex &index, int role) const override;

    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &child) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    Item *itemFromIndex(QModelIndex index);

private:

    QListView *m_view;
    QVector<DataSetPar*> m_items;
    DataSet *m_dataset;

};

class Model : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit Model(QSharedPointer<Entity> entity, QObject *parent = 0);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;

private:
    QSharedPointer<Entity> m_entity;
};

#endif // MODEL_H
