#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sstream>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
    //ui(new Ui::MainWindow)
{
    ui = new Ui::MainWindow();
    ui->setupUi(this);

    connect(ui->Submit, SIGNAL(clicked(bool)),this,SLOT(tampil_data2()));
}
void MainWindow::tampil_data2(){
    auto input_balas = ui->kotakbalas->text();
    std::stringstream ss;
    ss << "Chat 1:" << input_balas.toStdString();
    std::string data = ss.str();
    ui->balas->append(QString(data.c_str()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

