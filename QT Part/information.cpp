#include "information.h"
#include "ui_information.h"
#include <QPixmap>
#include <QDesktopServices>
#include <QUrl>
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

void Information::on_pushButton_clicked()
{
    if(pornCount == 2){
        QString link = "https://www.google.com/search?q=gayporno&newwindow=1&tbm=isch&sxsrf=ALeKk02SqQO-bCBXSPYsGJHLjzdqb-pLxA:1608041330834&source=lnms&sa=X&ved=0ahUKEwjYmbvilNDtAhVdAhAIHdXnBScQ_AUIDCgC&biw=1038&bih=1322&dpr=1";
        QDesktopServices::openUrl(QUrl(link));
    }else{
        QString link = "https://github.com/Geridok/StatisticsOfElectronicHoles/blob/main/about.pdf";
        QDesktopServices::openUrl(QUrl(link));
    }
    pornCount++;
}
