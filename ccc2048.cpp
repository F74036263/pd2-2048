#include "ccc2048.h"


ccc2048::ccc2048()
{
}

ccc2048::~ccc2048()
{
}

QLabel *ccc2048::getLabel()
{
    return cccLabel;
}

void ccc2048::setLabel(QLabel *label)
{
    cccLabel = label;
}

int ccc2048::getNumber()
{
    return num;
}

void ccc2048::setNumber(int number)
{
    num = number;
    cccLabel->setText("");
    switch(num)
    {
        case 0:
            cccLabel->setStyleSheet("background-color: rgb(250,225,255)");

        break;
        case 2:
            cccLabel->setStyleSheet("image: url(:/pic/jordan1.jpg)");


        break;
        case 4:
            cccLabel->setStyleSheet("image: url(:/pic/jordan2.jpg)");
        break;
        case 8:
            cccLabel->setStyleSheet("image: url(:/pic/jordan3.jpg)");
        break;
        case 16:
            cccLabel->setStyleSheet("image: url(:/pic/jordan4.jpg)");
        break;
        case 32:
            cccLabel->setStyleSheet("image: url(:/pic/jordan5.jpg)");
        break;
        case 64:
            cccLabel->setStyleSheet("image: url(:/pic/jordan6.jpg)");
        break;
        case 128:
            cccLabel->setStyleSheet("image: url(:/pic/jordan7.jpg)");
        break;
        case 256:
            cccLabel->setStyleSheet("image: url(:/pic/jordan8.jpg)");
        break;
        case 512:
            cccLabel->setStyleSheet("image: url(:/pic/jordan9.jpg)");
        break;
        case 1024:
            cccLabel->setStyleSheet("image: url(:/pic/jordan10.jpg)");
        break;
        case 2048:
            cccLabel->setStyleSheet("image: url(:/pic/jordan11.jpg)");
        break;
    }
}
