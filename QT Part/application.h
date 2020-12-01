#ifndef APPLICATION_H
#define APPLICATION_H

#include <QMainWindow>
#include <QPixmap>
#include "adapterforvectozavr.h"
namespace Ui {
class Application;
}

class Application : public QMainWindow
{
    Q_OBJECT

public:
    explicit Application(QWidget *parent = nullptr);
    ~Application();

private:
    Ui::Application *ui;
    adapterForVectozavr *adapter;
};

#endif // APPLICATION_H
