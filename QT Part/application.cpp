#include "application.h"
#include "ui_application.h"
#include <QPixmap>
#include <QDebug>
Application::Application(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Application)
{
    ui->setupUi(this);
    solver = std::make_shared<Silicon>( Silicon());

    ui->F_TWidget->addGraph();
    ui->F_TWidget->setInteraction(QCP::iRangeDrag,true);
    ui->F_TWidget->setInteraction(QCP::iRangeZoom,true);

    ui->N_TWidget->addGraph();
    ui->N_TWidget->setInteraction(QCP::iRangeDrag,true);
    ui->N_TWidget->setInteraction(QCP::iRangeZoom,true);
    reculculate();
    updateGraph();

    setSlidersLimit();
    setInitialValue();
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

void Application::updateGraph()
{
    //if(Time::deltaTime() > 0.3){
        ui->F_TWidget->graph(0)->setData(T,F);
        ui->F_TWidget->xAxis->setRange(*std::min_element(T.begin(),T.end()),*std::max_element(T.begin(),T.end()));
        ui->F_TWidget->yAxis->setRange(*std::min_element(F.begin(),F.end()),*std::max_element(F.begin(),F.end()));
        auto a = *std::min_element(F.begin(),F.end());
        auto b = *std::max_element(F.begin(),F.end());
        ui->F_TWidget->replot();
        ui->F_TWidget->update();

        ui->N_TWidget->graph(0)->setData(T,n);
        ui->N_TWidget->xAxis->setRange(*std::min_element(T.begin(),T.end()),*std::max_element(T.begin(),T.end()));
        ui->N_TWidget->yAxis->setRange(*std::min_element(n.begin(),n.end()),*std::max_element(n.begin(),n.end()));
        auto c = *std::min_element(n.begin(),n.end());
        auto d = *std::max_element(n.begin(),n.end());
        ui->N_TWidget->replot();
        ui->N_TWidget->update();
    //}
    //Time::update();
}

void Application::reculculate()
{
    solver->setParameters(T_0,T_1, E_d,E_g,E_c,m,N_d0);
    auto F = solver->get_F();
    auto T = solver->get_T();
    auto n = solver->get_n();
    this->F = QVector<double>(F.begin(),F.end());
    this->T = QVector<double>(T.begin(),T.end());
    this->n = QVector<double>(n.begin(),n.end());
}

Application::~Application()
{
    delete ui;
}


void Application::on_E_gSlider_valueChanged(int value)
{
    E_g = double(value) * multiplier_E_g;
    ui->E_gLineEdit->setText(QString::number(E_g));

    reculculate();
    updateGraph();
}

void Application::on_E_dSlider_valueChanged(int value)
{
    E_d = double(value) * multiplier_E_d;
    ui->E_dLineEdit->setText(QString::number(E_d));

    reculculate();
    updateGraph();
}

void Application::on_E_cSlider_valueChanged(int value)
{
    E_c = double(value) * multiplier_E_c;
    ui->E_cLineEdit->setText(QString::number(E_c));

    reculculate();
    updateGraph();
}

void Application::on_mSlider_valueChanged(int value)
{
    m = double(value) * multiplier_m;
    ui->mLineEdit->setText(QString::number(m));

    reculculate();
    updateGraph();
}

void Application::on_N_d0Slider_valueChanged(int value)
{
    N_d0Pow = double(value);
    N_d0 = pow(10,N_d0Pow);
    ui->N_d0LineEdit->setText(QString::number(N_d0));

    reculculate();
    updateGraph();
}

void Application::on_T_0Slider_valueChanged(int value)
{
    T_0 = value;
    ui->T_0LineEdit->setText(QString::number(T_0));
    if(T_1 < T_0){
        this->on_T_1Slider_valueChanged(T_0);
    }
    reculculate();
    updateGraph();
}

void Application::on_T_1Slider_valueChanged(int value)
{
    T_1 = value;
    if(T_1 <= T_0){
        ui->T_1Slider->setValue(T_0);
        T_1 = T_0;
    }else{
        reculculate();
        updateGraph();
    }
    ui->T_1LineEdit->setText(QString::number(T_1));
}

