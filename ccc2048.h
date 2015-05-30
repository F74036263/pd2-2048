#ifndef CCC2048
#define CCC2048

#include <QLabel>


class ccc2048
{

public:
    explicit ccc2048();
    ~ccc2048();

    int getNumber();
    QLabel *getLabel();
    void setNumber(int number);
    void setPixmap();
    void setLabel(QLabel *label);

private:
    int num;
    QLabel *cccLabel;
    QPixmap jordan1,jordan2,jordan3,jordan4,jordan5,jordan6,jordan7,jordan8,jordan9,jordan10,jorda11;

};

#endif // CCC2048

