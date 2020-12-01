#include "application.h"
#include "ui_application.h"
#include <QPixmap>
#include <QDebug>
Application::Application(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Application)
{
    ui->setupUi(this);
    QPixmap first (":/graphics/f_from_t.png");
    int wFirst =  first.width();
    int hFirst = first.height();
    QPixmap sec (":/graphics/n_from_t.png");
    int wSec = sec.width();
    int hSec = sec.height();
    ui->f_from_tIMG->setMinimumHeight(hFirst);
    ui->n_from_tIMG->setMinimumHeight(hSec);
    ui->f_from_tIMG->setPixmap(first.scaled(wFirst,hFirst,Qt::KeepAspectRatio));
    ui->n_from_tIMG->setPixmap(sec.scaled(wSec,hSec,Qt::KeepAspectRatio));
}

Application::~Application()
{
    delete ui;
}
