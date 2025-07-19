#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <vector>

#include "Bit-Block.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);

    virtual ~MainWindow();

private:
    Ui::MainWindow* ui;

    const uint32_t kDiskSize = 16;

    std::vector<BitBlock*> bit_block_vector_;

};
#endif // MAINWINDOW_H
