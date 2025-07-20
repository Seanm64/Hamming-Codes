#include "Bit-Block.h"

#include "QPainter"

BitBlock::BitBlock(QWidget* parent)
    : QWidget(parent),
    block_type_(BlockType::eDisabledBlock),
    data_(false)
{
    resize(40, 40);
}

BitBlock::BitBlock(const BitBlock& block)
{
    this->block_type_ = block.block_type_;
    this->data_   = block.data_;
}


BitBlock::BitBlock(BitBlock&& other) noexcept
  : QWidget(other.parentWidget()),
    block_type_(other.block_type_),
    data_(other.data_)
{
    other.setParent(nullptr);
}

BitBlock& BitBlock::operator=(BitBlock &&other) noexcept
{
    this->setParent(other.parentWidget());
    block_type_     = other.block_type_;
    data_   = other.data_;

    other.setParent(nullptr);

    return *this;
}

void BitBlock::SetBlockType(BlockType block_type)
{
    block_type_ = block_type;
    update();
}

bool BitBlock::SetBlock(bool block)
{
    data_ = block;

    update();

    return block;
}

void BitBlock::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    painter.setBrush(Qt::NoBrush);
    painter.setPen(Qt::white);

    if(block_type_ == eParityBlock)
    {
        painter.setBrush(Qt::red);
    }
    else
    {
        if(data_)
        {
            painter.setBrush(Qt::green);
            painter.setPen(Qt::black);
        }
    }

    painter.drawRect(this->rect());

    if(data_)
    {
        painter.drawText(this->rect(), Qt::AlignCenter, "1");
    }
    else
    {
        painter.drawText(this->rect(), Qt::AlignCenter, "0");
    }

}

void BitBlock::mousePressEvent(QMouseEvent *event)
{
    data_ = ! data_;

    update();
}
