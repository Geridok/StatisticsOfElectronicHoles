#include "information.h"
#include "ui_information.h"
#include <QPixmap>
Information::Information(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Information)
{
    ui->setupUi(this);
    auto img = QPixmap(":/Photos/Photos/IMG_5766.jpg");

    ui->ImageLabel->setPixmap(img.scaled(300,300, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

Information::~Information()
{
    delete ui;
}

void Information::on_OkButton_clicked()
{
    close();
}
