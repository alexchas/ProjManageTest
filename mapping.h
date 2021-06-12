#ifndef MAPPING_H
#define MAPPING_H

#include <QDialog>
#include <QSharedPointer>

#include "projectcard.h"
#include "entity.h"
#include "model.h"
#include "dataset.h"


namespace Ui {
class Mapping;
}

class Mapping : public QDialog
{
    Q_OBJECT

public:
    explicit Mapping(QWidget *parent = 0) = delete;
    explicit Mapping(QSharedPointer<Entity> entity, QWidget *parent = 0);
    ~Mapping();

private slots:
    void on_pushButton_projects_released();
    void on_pushButton_logout_released();

    void on_listView_clicked(const QModelIndex &index);
private:
    Ui::Mapping *ui;
    QSharedPointer<Entity> qspe;
    DataSet *m_dataset;
    ItemListModel *m_itemListModel;
    Model *m_model;
};

#endif // MAPPING_H
