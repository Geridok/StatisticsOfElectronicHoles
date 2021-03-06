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
    QIcon icon;
    icon.addFile(QStringLiteral(":/icons/Icons/NotChecked.png"), QSize(), QIcon::Normal, QIcon::Off);
    icon.addFile(QStringLiteral(":/icons/Icons/Checked.png"), QSize(), QIcon::Normal, QIcon::On);
    ui->logScaleButton->setIcon(icon);

    ui->F_TWidget->addGraph();
    ui->F_TWidget->setInteraction(QCP::iRangeDrag,true);
    ui->F_TWidget->setInteraction(QCP::iRangeZoom,true);
    ui->F_TWidget->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc,5));
    ui->F_TWidget->graph(0)->setName("F");
    ui->F_TWidget->xAxis->setLabel("Temperature");
    ui->F_TWidget->yAxis->setLabel("Fermi level");

    ui->F_TWidget->addGraph();
    ui->F_TWidget->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc,5));
    ui->F_TWidget->graph(1)->setPen(QPen(Qt::red));
    ui->F_TWidget->graph(1)->setName("E_g");

    ui->F_TWidget->addGraph();
    ui->F_TWidget->graph(2)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc,5));
    ui->F_TWidget->graph(2)->setPen(QPen(Qt::green));
    ui->F_TWidget->graph(2)->setName("E_d");
    ui->F_TWidget->legend->setVisible(true);

    ui->N_TWidget->addGraph();
    ui->N_TWidget->setInteraction(QCP::iRangeDrag,true);
    ui->N_TWidget->setInteraction(QCP::iRangeZoom,true);
    ui->N_TWidget->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc,5));
    ui->N_TWidget->graph(0)->setName("n");
    ui->N_TWidget->xAxis->setLabel("Temperature");
    ui->N_TWidget->yAxis->setLabel("Number");
    ui->N_TWidget->legend->setVisible(true);

    reculculate();
    updateGraph();

    setSlidersLimit();
    setInitialValue();
    E_g = 1.7942e-12;
    E_d = E_g - 0.045 * eV;
    N_d0 = 1.0e15;
    setInitialValue();
    ui->E_dSlider->setValue((E_g - E_d)/eV);
    ui->N_d0Slider->setValue(1600);
    reculculate();
    updateGraph();
}

void Application::setInitialValue(){
    ui->E_gLineEdit->setText(QString::number((E_g - E_d)/eV));
    ui->N_d0LineEdit->setText(QString::number(N_d0));
    ui->T_0LineEdit->setText(QString::number(T_0));
    ui->T_1LineEdit->setText(QString::number(T_1));
    ui->T_1Slider->setValue(T_1);
}

void Application::setSlidersLimit(){

    ui->E_dSlider->setMinimum(1);
    ui->E_dSlider->setMaximum(1500);

    ui->N_d0Slider->setMinimum(1500);
    ui->N_d0Slider->setMaximum(2500);

    ui->T_0Slider->setMinimum(0);
    ui->T_0Slider->setMaximum(1000);
    ui->T_0Slider->setValue(T_0);

    ui->T_1Slider->setMinimum(0);
    ui->T_1Slider->setMaximum(1200);
    ui->T_1Slider->setValue(T_1);
}

void Application::updateGraph()
{
        ui->F_TWidget->graph(0)->setData(T,F);
        ui->F_TWidget->graph(1)->setData(TP,E_gP);
        ui->F_TWidget->graph(2)->setData(TP,E_dP);

            F.push_back(E_d/eV + 0.10);
            F.push_back(E_g/eV + 0.10);
            F.push_back(E_d/eV - 0.10);
            F.push_back(E_g/eV - 0.10);

        ui->F_TWidget->xAxis->setRange(*std::min_element(T.begin(),T.end()),*std::max_element(T.begin(),T.end()));
        ui->F_TWidget->yAxis->setRange(*std::min_element(F.begin(),F.end()),*std::max_element(F.begin(),F.end()));
        ui->F_TWidget->replot();
        ui->F_TWidget->update();

        ui->N_TWidget->graph(0)->setData(T,n);
        ui->N_TWidget->xAxis->setRange(*std::min_element(T.begin(),T.end()),*std::max_element(T.begin(),T.end()));
        ui->N_TWidget->yAxis->setRange(*std::min_element(n.begin(),n.end()),*std::max_element(n.begin(),n.end()));
        ui->N_TWidget->replot();
        ui->N_TWidget->update();
}

void Application::reculculate()
{
    double me = 9.109e-28;
    double me_eff = 0.36 * me;

    QVector<double> T_point;
    QVector<double> E_dPoint;
    QVector<double> E_gPoint;


    solver->setParameters(T_0,T_1, E_d,E_g,me_eff,N_d0);
    if(ui->logScaleButton->isChecked()){
        auto F = solver->get_F();
        auto T = solver->get_T();
        auto n = solver->get_n_log();
        this->F = QVector<double>::fromStdVector(F);
        this->T = QVector<double>::fromStdVector(T);
        this->n = QVector<double>::fromStdVector(n);

        T_point.push_back(this->T[0]);
        T_point.push_back(this->T[this->T.size() - 1]);

        E_gPoint.push_back(E_g/eV);
        E_gPoint.push_back(E_g/eV);

        E_dPoint.push_back(E_d/eV);
        E_dPoint.push_back(E_d/eV);
    }else{
        auto F = solver->get_F();
        auto T = solver->get_T();
        auto n = solver->get_n();
        this->F = QVector<double>::fromStdVector(F);
        this->T = QVector<double>::fromStdVector(T);
        this->n = QVector<double>::fromStdVector(n);

        T_point.push_back(this->T[0]);
        T_point.push_back(this->T[this->T.size() - 1]);

        E_gPoint.push_back((E_g)/eV);
        E_gPoint.push_back((E_g)/eV);

        E_dPoint.push_back((E_d)/eV);
        E_dPoint.push_back((E_d)/eV);
    }
    TP = T_point;
    E_dP = E_dPoint;
    E_gP = E_gPoint;
}

Application::~Application()
{
    delete ui;
}


void Application::on_E_dSlider_valueChanged(int value)
{
    double cor = double(value)/1000.0;
    E_d = E_g - cor*eV;
    ui->E_gLineEdit->setText(QString::number(cor));

    reculculate();
    updateGraph();
}

void Application::on_N_d0Slider_valueChanged(int value)
{
    double cor = double(value)/100.0;
    N_d0 = pow(10,cor);
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


void Application::on_actionSave_triggered()
{

    SaveWindow saver(ui->F_TWidget,ui->N_TWidget,F,T,n);
    saver.setModal(true);
    saver.exec();
}

void Application::on_actionAbout_triggered()
{
    Information inf;
    inf.setModal(true);
    inf.exec();
}



void Application::on_logScaleButton_clicked()
{
    reculculate();
    updateGraph();
}
