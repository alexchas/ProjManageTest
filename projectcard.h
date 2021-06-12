#ifndef PROJECTCARD_H
#define PROJECTCARD_H

#include <QDialog>
#include <datasetpar.h>
#include <entity.h>

namespace Ui {
class Projectcard;
}

class Projectcard : public QDialog
{
    Q_OBJECT

public:
    explicit Projectcard(QSharedPointer<Entity> entity, DataSetPar* datasetpar,  QWidget *parent = nullptr);
    ~Projectcard();

private slots:
    void on_pushButton_released();

    void on_pushButton_2_released();

private:
    Ui::Projectcard *ui;
    DataSetPar *datasetpar;
    QSharedPointer<Entity> qspe;
};

#endif // PROJECTCARD_H
