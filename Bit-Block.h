#ifndef BIT_BLOCK_H
#define BIT_BLOCK_H

#include <QWidget>

enum BlockType : uint32_t {
    eDataBlock = 0,
    eParityBlock = 1,
    eFirstBlock = 2,
    eDisabledBlock = 3
};

class BitBlock : public QWidget
{

public:
    BitBlock(QWidget* parent = nullptr);

    BitBlock(const BitBlock& block);

    virtual ~BitBlock() = default;

    BitBlock& operator=(const BitBlock& other);

    BitBlock(BitBlock&& other) noexcept;

    BitBlock& operator=(BitBlock&& other) noexcept;

    void SetBlockType(BlockType block_type);

    bool SetBlock(bool block);

    bool GetData() { return data_; };

private:
    void paintEvent(QPaintEvent* event);

    void mousePressEvent(QMouseEvent* event);

    BlockType block_type_;

    bool data_;

};

#endif // BIT_BLOCK_H
