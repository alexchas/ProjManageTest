#ifndef DATASETPAR_H
#define DATASETPAR_H

#include "entity.h"

class Item: public Project, public QObject {

public:
    Item(Project project);
    Project operator=(Project&& other);
};

namespace Ui {
    class DataSetPar;
}

class DataSetPar: public QObject
{
    Q_OBJECT
public:
    DataSetPar(Item * project);
    ~DataSetPar();

    Item *item() const;
    void setItem(Item *project);

private:
    Item *m_item;
};

#endif // DATASETPAR_H
