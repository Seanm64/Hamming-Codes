#ifndef DATASUBMISSIONAREA_H
#define DATASUBMISSIONAREA_H

#include <vector>

#include <QWidget>

class BitBlock;

class DataSubmissionArea : public QWidget
{
    Q_OBJECT

public:
    explicit DataSubmissionArea(QWidget* parent = nullptr);


protected:
    void resizeEvent(QResizeEvent* event);


private:
    const uint32_t kDiskSize = 16;

    std::vector<BitBlock*> bit_block_vector_;


};

#endif // DATASUBMISSIONAREA_H
