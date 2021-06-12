#include "projectcard.h"
#include "ui_projectcard.h"

Projectcard::Projectcard(QSharedPointer<Entity> entity, DataSetPar *data, QWidget *parent) : QDialog(parent), ui(new Ui::Projectcard), datasetpar(data) {
    ui->setupUi(this);

    QPixmap pixmap;
    pixmap.loadFromData(datasetpar->item()->logo);

    QLabel *label_image = ui->label_image;
    label_image->setPixmap(pixmap);
    QRegion *region = new QRegion(0,0,label_image->width(),label_image->height(),QRegion::Ellipse);
    label_image->setScaledContents(true);
    label_image->setMask(*region);
    ui->lineEdit_name->setText(datasetpar->item()->name);
}

Projectcard::~Projectcard() { delete ui; }


void Projectcard::on_pushButton_released() {
    hide();
    Project project = *datasetpar->item();
    project.name = ui->lineEdit_name->text();

//    if(qspe->upgradeProject(project).id == project.id){
        datasetpar->item()->name = project.name;
//    }
    close();
}

void Projectcard::on_pushButton_2_released()
{
    hide();

    Project project = *datasetpar->item();
    project.name = ui->lineEdit_name->text();

    close();
}
