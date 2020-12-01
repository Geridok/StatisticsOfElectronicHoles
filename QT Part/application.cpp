#include "application.h"
#include "ui_application.h"
#include <QPixmap>
#include <QDebug>
Application::Application(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Application)
{
    ui->setupUi(this);
//    QPixmap first (":/graphics/f_from_t.png");
//    int wFirst =  first.width();
//    int hFirst = first.height();
//    QPixmap sec (":/graphics/n_from_t.png");
//    int wSec = sec.width();
//    int hSec = sec.height();
//    ui->f_from_tIMG->setMinimumHeight(hFirst);
//    ui->n_from_tIMG->setMinimumHeight(hSec);
//    ui->f_from_tIMG->setPixmap(first.scaled(wFirst,hFirst,Qt::KeepAspectRatio));
//    ui->n_from_tIMG->setPixmap(sec.scaled(wSec,hSec,Qt::KeepAspectRatio));
    solver = std::make_shared<Silicon>( Silicon(E_d,E_g,E_c,m,N_d0));
    solver->calcilate_F_from_T(T_0,T_1, tol,NT,Nn);
    solver->saveData();
    Silicon::plotPNGData();
    Silicon::plotData();
    setSlidersLimit();
    setInitialValue();
    ui->cancelButton->setEnabled(false);
    ui->ApplyButton->setEnabled(false);
}

void Application::setInitialValue(){
    ui->E_dLineEdit->setText(QString::number(E_d));
    ui->E_gLineEdit->setText(QString::number(E_g));
    ui->E_cLineEdit->setText(QString::number(E_c));
    ui->mLineEdit->setText(QString::number(m));
    ui->N_d0LineEdit->setText(QString::number(N_d0));
    ui->T_0LineEdit->setText(QString::number(T_0));
    ui->T_1LineEdit->setText(QString::number(T_1));
    ui->T_1Slider->setValue(T_1);
}

void Application::setSlidersLimit(){
    ui->E_cSlider->setMinimum(1);
    ui->E_cSlider->setMaximum(10);

    ui->E_dSlider->setMinimum(1);
    ui->E_dSlider->setMaximum(10);

    ui->E_gSlider->setMinimum(1);
    ui->E_gSlider->setMaximum(10);

    ui->mSlider->setMinimum(1);
    ui->mSlider->setMaximum(10);

    ui->N_d0Slider->setMinimum(15);
    ui->N_d0Slider->setMaximum(22);

    ui->T_0Slider->setMinimum(0);
    ui->T_0Slider->setMaximum(100);

    ui->T_1Slider->setMinimum(0);
    ui->T_1Slider->setMaximum(100);
    ui->T_1Slider->setValue(T_1);
}

Application::~Application()
{
    delete ui;
}


void Application::on_E_gSlider_valueChanged(int value)
{
    ui->E_gLineEdit->setText(QString::number((double(value)) * multiplier_E_g));
    ui->cancelButton->setEnabled(true);
    ui->ApplyButton->setEnabled(true);
}

void Application::on_E_dSlider_valueChanged(int value)
{ 
    ui->E_dLineEdit->setText(QString::number((double(value)) * multiplier_E_d));
    ui->cancelButton->setEnabled(true);
    ui->ApplyButton->setEnabled(true);
}

void Application::on_E_cSlider_valueChanged(int value)
{
    ui->E_cLineEdit->setText(QString::number((double(value)) * multiplier_E_c));
    ui->cancelButton->setEnabled(true);
    ui->ApplyButton->setEnabled(true);
}

void Application::on_mSlider_valueChanged(int value)
{
    ui->mLineEdit->setText(QString::number((double(value)) * multiplier_m));
    ui->cancelButton->setEnabled(true);
    ui->ApplyButton->setEnabled(true);
}

void Application::on_N_d0Slider_valueChanged(int value)
{
    N_d0Pow = double(value);
    ui->N_d0LineEdit->setText(QString::number(pow(10,N_d0Pow)));
    ui->cancelButton->setEnabled(true);
    ui->ApplyButton->setEnabled(true);
}

void Application::on_T_0Slider_valueChanged(int value)
{
    ui->T_0LineEdit->setText(QString::number(value));
    if(T_1 < value){
        ui->T_1Slider->setValue(value);
        this->on_T_1Slider_valueChanged(value);
    }
    ui->cancelButton->setEnabled(true);
    ui->ApplyButton->setEnabled(true);
}

void Application::on_T_1Slider_valueChanged(int value)
{
    if(value < T_0){
        ui->T_1Slider->setValue(value);
    }
    ui->T_1LineEdit->setText(QString::number(value));
    ui->cancelButton->setEnabled(true);
    ui->ApplyButton->setEnabled(true);
}



void Application::on_cancelButton_clicked()
{
    ui->E_dLineEdit->setText(QString::number(E_d));
    ui->E_gLineEdit->setText(QString::number(E_g));
    ui->E_cLineEdit->setText(QString::number(E_c));
    ui->mLineEdit->setText(QString::number(m));
    ui->N_d0LineEdit->setText(QString::number(N_d0));
    ui->T_0LineEdit->setText(QString::number(T_0));
    ui->T_1LineEdit->setText(QString::number(T_1));

    ui->E_dSlider->setValue(int(E_d/multiplier_E_d));
    ui->E_gSlider->setValue(int(E_g/multiplier_E_g));
    ui->E_cSlider->setValue(int(E_c/multiplier_E_c ));
    ui->mSlider->setValue(int(m/multiplier_m));
    ui->N_d0Slider->setValue(N_d0Pow);
    ui->T_0Slider->setValue(T_0);
    ui->T_1Slider->setValue(T_1);
    ui->cancelButton->setEnabled(false);
    ui->ApplyButton->setEnabled(false);
}

void Application::on_ApplyButton_clicked()
{
    E_g = ui->E_gLineEdit->text().toDouble();
    E_g = ui->E_gLineEdit->text().toDouble();
    E_c = ui->E_cLineEdit->text().toDouble();
    m = ui->mLineEdit->text().toDouble();
    N_d0 = ui->N_d0LineEdit->text().toDouble();
    T_0 = ui->T_0LineEdit->text().toInt();
    T_1 = ui->T_1LineEdit->text().toInt();
    solver->setValue(E_d,E_g,E_c,m,N_d0);
    solver->calcilate_F_from_T(T_0,T_1, tol,NT,Nn);
    solver->saveData();
    Silicon::plotPNGData();
    Silicon::plotData();
    ui->cancelButton->setEnabled(false);
    ui->ApplyButton->setEnabled(false);
}
