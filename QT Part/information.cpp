#include "information.h"
#include "ui_information.h"
#include <QPixmap>
Information::Information(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Information)
{
    ui->setupUi(this);
    auto img = QPixmap(":/Photos/Photos/62591927_120273162557623_7382008311468754349_n.jpg");

    ui->ImageLabel->setPixmap(img.scaled(300,300));
}

Information::~Information()
{
    delete ui;
}

void Information::on_OkButton_clicked()
{
    close();
}
