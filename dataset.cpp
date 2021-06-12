#include "dataset.h"

DataSet::DataSet(QSharedPointer<Entity> entity) : entity_ex(entity) {

    loadItems();
}

QList<Item*> DataSet::list() const {

    return list_ex;
}

int DataSet::size() const {

    return list_ex.size();
}

Item *DataSet::addItem(Item *item) {
    list_ex.prepend(item);
    return item;
}

void DataSet::removeItem(int index)
{

    Item *item = list_ex[index];
    list_ex.removeAt(index);
    delete item;

}

void DataSet::removeItem(Item *item)
{

    int index = list_ex.indexOf(item);
    if(index >= 0)
        removeItem(index);
    else
        qDebug() << "Tried to remove item, ID == -1";

}

void DataSet::loadItems()
{
    QMap<qint32, Project> projects = entity_ex->getProjects();
    for(auto project: projects){
        Item *item = new Item(project);
        addItem(item);
    }

}
