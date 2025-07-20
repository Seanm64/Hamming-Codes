#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    uint32_t row_col_size = qSqrt(kDiskSize);

    for(uint32_t row = 0; row < kDiskSize; row++)
    {
        bit_block_vector_.push_back(new BitBlock(this));
    }

    bit_block_vector_[0]->show();
    bit_block_vector_[0]->move(20, 20);
}

MainWindow::~MainWindow()
{
    delete ui;
}
