#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    uint32_t row_col_size = qSqrt(kDiskSize);
    uint32_t block_width  = this->rect().width()  / row_col_size;
    uint32_t block_height = this->rect().height() / row_col_size;

    // Creating Vector
    for(uint32_t index = 0; index < kDiskSize; index++)
    {
        bit_block_vector_.push_back(new BitBlock(this));
        bit_block_vector_.at(index)->setFixedWidth(block_width);
        bit_block_vector_.at(index)->setFixedHeight(block_height);
    }

    // Moving items in vector
    for(uint32_t row = 0; row < row_col_size; row++)
    {
        for(uint32_t column = 0; column < row_col_size; column++)
        {
            bit_block_vector_.at(row * row_col_size + column)->move(column * block_width, row * block_height);
            bit_block_vector_.at(row * row_col_size + column)->show();
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
