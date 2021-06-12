#ifndef DATASET_H
#define DATASET_H

#include <QSharedPointer>
#include <QList>

#include "entity.h"
#include "datasetpar.h"

class DataSet : public QObject
{
    Q_OBJECT
public:
    DataSet(QSharedPointer<Entity> entity);

    QList<Item*> list() const;
    int size() const;

    Item *addItem(Item *item);
    void removeItem(int index);
    void removeItem(Item *item);

    void loadItems();

private:
    QSharedPointer<Entity> entity_ex;
    QList<Item*> list_ex;
};

#endif // DATASET_H
