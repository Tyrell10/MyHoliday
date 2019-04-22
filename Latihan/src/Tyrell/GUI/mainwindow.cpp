#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
    //ui(new Ui::MainWindow)
{
    ui = new Ui::MainWindow();
    ui->setupUi(this);

    connect(ui->Submit, SIGNAL(clicked(bool)),this,SLOT(tampil_data()));
}

void MainWindow::tampil_data(){
    auto input_pesan = ui->kotakpesan->text();
    std::stringstream ss;
    ss << "Chat 2:" << input_pesan.toStdString();
    std::string data = ss.str();
    ui->pesan->append(QString(data.c_str()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
