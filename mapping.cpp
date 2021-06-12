#include "mapping.h"
#include "ui_mapping.h"

#include "model.h"

Mapping::Mapping(QSharedPointer<Entity> entity, QWidget *parent):
    qspe(entity),
    QDialog(parent),
    ui(new Ui::Mapping)
{

    ui->setupUi(this);
    m_dataset = new DataSet(entity);
    m_itemListModel = new ItemListModel(ui->listView, m_dataset);
    m_model = new Model(entity);
    ui->listView->setModel(m_itemListModel);
    ui->listView->setItemDelegate(m_model);
}

void Mapping::on_pushButton_projects_released()
{
    m_itemListModel->clear();
    int size = m_dataset->size();

    for(int i = 0; i < size; ++i){
        m_dataset->removeItem(0);
    }

    m_dataset->loadItems();

    m_itemListModel->loadFromDatabase();

}

void Mapping::on_pushButton_logout_released()
{
    qspe->logout();
    close();
}

void Mapping::on_listView_clicked(const QModelIndex &index)
{
    Projectcard projectcard(qspe, static_cast<DataSetPar*>( index.internalPointer() ));
    projectcard.setModal(true);
    projectcard.exec();
    ui->listView->repaint();
}

Mapping::~Mapping()
{
    delete m_model;
    delete m_itemListModel;
    delete m_dataset;

    delete ui;
}
