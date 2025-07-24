#include "mainwindow.h"

#include "ui_mainwindow.h"

#include "datasubmissionarea.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->setFixedSize(1800, 2500);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_NewButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->insertWidget(0, new DataSubmissionArea(ui->stackedWidget));
}

