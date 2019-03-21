#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // rendermethod = new VideoWindowRender();
    /*
    renderobject= new VWW
    render->

    */
   // rendermethod->Render(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}
