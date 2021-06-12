#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "mapping.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    entity = QSharedPointer<Entity>(new Entity);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_clicked() {
    hide();
    QString login = ui->lineEdit_login->text();
    QString password = ui->lineEdit_password->text();
    if(entity->auth(login, password)){
        Mapping mapping(entity);
        mapping.setModal(true);
        mapping.exec();
        entity->logout();
    }
    show();
}
