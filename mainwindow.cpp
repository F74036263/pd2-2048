#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "time.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::init()
{
    GAMEOVER = new QLabel(ui->centralWidget);
    GAMEOVER->hide();
    QFont font = GAMEOVER->font();
    font.setBold(true);
    font.setFamily("Small Font");
    font.setPointSize(48);
    GAMEOVER->setFont(font);
    GAMEOVER->setGeometry(QRect(100,150,400,300));
    GAMEOVER->setStyleSheet("QLabel{color: rgb(250, 225, 255)}");
    GAMEOVER->setAttribute(Qt::WA_TranslucentBackground, true);
    GAMEOVER->setText("you suck");

    srand(time(NULL));

    first = true;

    setupccc2048();
    Best=0;

    ui-> lcdNumber_2 -> display(Best);



}

void MainWindow::setupccc2048()
{
    QWidget *ggg;
    ccc2048 *ccc;
    QLabel *xxx;

    ccc2048Map.resize(4);
    for (int x=0; x<4;x++)
    {
        ccc2048Map[x].resize(4);
    }
    for(int z=0;z<4;z++)
    {
        for (int s=0;s<4;s++)
        {
            ggg=ui->gridLayout->itemAtPosition(z,s)->widget();
            xxx=static_cast<QLabel*>(ggg);

            ccc=new ccc2048;
            ccc->setLabel(xxx);
            ccc2048Map[s][z]=ccc;

        }
    }

}

void MainWindow::Gamestart()
{
    score=0;
    temptscore=0;
    ui-> lcdNumber -> display(score);
    GAMEOVER->hide();

    for (int a=0;a<4;a++)
    {
        for (int b=0;b<4;b++)
        {
            ccc2048Map[b][a]->setNumber(0);
        }
    }
    rndaddNum();
    rndaddNum();
}

void MainWindow::rndaddNum()
{
    QPoint q;
    int x1,y1;
    fucklist.clear();
    for(int x=0;x<4;x++)
    {
        for(int y=0;y<4;y++)
        {
            if(ccc2048Map[x][y]->getNumber()==0)
            {
                q.ry()=y;
                q.rx()=x;
                fucklist.append(q);
            }

        }
    }
    if(fucklist.size()>0)
    {
        x1=rand()%fucklist.size();
        q=fucklist.takeAt(x1);
        y1=(rand()%100)>19?2:4;
        ccc2048Map[q.rx()][q.ry()]->setNumber(y1);


    }

}

void MainWindow::left()
{
    bool merge=false;
    QPoint begin, over, combine;
    for(int x=0;x<4;x++)
    {
        for(int y=0;y<4;y++)
        {
            for(int z=y+1;z<4;z++)
            {
                if(ccc2048Map[z][x]->getNumber()>0)
                {
                    if(ccc2048Map[y][x]->getNumber()==0)
                    {
                        begin.setX(z);
                        begin.setY(x);
                        over.setX(y);
                        over.setY(x);

                        ccc2048Map[y][x]->setNumber(ccc2048Map[z][x]->getNumber());
                        ccc2048Map[z][x]->setNumber(0);
                        y--;
                    }
                  else if(ccc2048Map[y][x]->getNumber()==ccc2048Map[z][x]->getNumber())
                  {
                        begin.setX(z);
                        begin.setY(x);
                        over.setX(y);
                        over.setY(x);
                        combine.setX(y);
                        combine.setY(x);
                        ccc2048Map[y][x]->setNumber(ccc2048Map[y][x]->getNumber()*2);
                        ccc2048Map[z][x]->setNumber(0);
                        addtemptscore(ccc2048Map[y][x]->getNumber());
                        merge=true;

                  }
                  break;

                }
            }
        }
    }
    if(merge)addscore();
    rndaddNum();
    yousuck();
}

void MainWindow::right()
{
    bool merge = false;
    QPoint begin, over, combine;
    for(int x=0; x<4; x++)
    {
        for(int y=3; y>=0; y--)
        {
            for (int z=y-1; z>=0; z--)
            {
                if(ccc2048Map[z][x]->getNumber()>0){
                    if(ccc2048Map[y][x]->getNumber()==0)
                    {
                        begin.setX(z);
                        begin.setY(x);
                        over.setX(y);
                        over.setY(x);
                        ccc2048Map[y][x]->setNumber(ccc2048Map[z][x]->getNumber());
                        ccc2048Map[z][x]->setNumber(0);
                        y++;
                    }
                    else if(ccc2048Map[y][x]->getNumber()==ccc2048Map[z][x]->getNumber())
                    {
                        begin.setX(z);
                        begin.setY(x);
                        over.setX(y);
                        over.setY(x);
                        combine.setX(y);
                        combine.setY(x);
                        ccc2048Map[y][x]->setNumber(ccc2048Map[y][x]->getNumber()*2);
                        ccc2048Map[z][x]->setNumber(0);
                        addtemptscore(ccc2048Map[y][x]->getNumber());
                        merge = true;
                    }

                    break;
                }
            }
        }
    }

    if(merge)addscore();
    rndaddNum();
    yousuck();
}



void MainWindow::up()
{
    bool merge = false;
    QPoint begin, over, combine;
    for(int x=0; x<4; x++)
    {
        for(int y=0; y<4; y++)
        {
            for (int z=y+1; z<4; z++)
            {
                if(ccc2048Map[x][z]->getNumber()>0)
                {
                    if(ccc2048Map[x][y]->getNumber()==0)
                    {
                        begin.setX(x);
                        begin.setY(z);
                        over.setX(x);
                        over.setY(y);

                        ccc2048Map[x][y]->setNumber(ccc2048Map[x][z]->getNumber());
                        ccc2048Map[x][z]->setNumber(0);
                        y--;
                    }
                    else if(ccc2048Map[x][y]->getNumber()==ccc2048Map[x][z]->getNumber())
                    {
                        begin.setX(x);
                        begin.setY(z);
                        over.setX(x);
                        over.setY(y);
                        combine.setX(x);
                        combine.setY(y);

                        ccc2048Map[x][y]->setNumber(ccc2048Map[x][y]->getNumber()*2);
                        ccc2048Map[x][z]->setNumber(0);
                        addtemptscore(ccc2048Map[x][y]->getNumber());
                        merge = true;
                    }

                    break;
                }
            }
        }
    }

    if(merge)addscore();
    rndaddNum();
    yousuck();
}

void MainWindow::down()
{
    bool merge = false;
    QPoint begin, over, combine;
    for(int x=0; x<4; x++)
    {
        for(int y=3; y>=0; y--)
        {
            for (int z=y-1; z>=0; z--)
            {
                if(ccc2048Map[x][z]->getNumber()>0)
                {
                    if(ccc2048Map[x][y]->getNumber()==0)
                    {
                        begin.setX(x);
                        begin.setY(z);
                        over.setX(x);
                        over.setY(y);

                        ccc2048Map[x][y]->setNumber(ccc2048Map[x][z]->getNumber());
                        ccc2048Map[x][z]->setNumber(0);
                        y++;
                    }
                    else if(ccc2048Map[x][y]->getNumber()==ccc2048Map[x][z]->getNumber())
                    {
                        begin.setX(x);
                        begin.setY(z);
                        over.setX(x);
                        over.setY(y);
                        combine.setX(x);
                        combine.setY(y);

                        ccc2048Map[x][y]->setNumber(ccc2048Map[x][y]->getNumber()*2);
                        ccc2048Map[x][z]->setNumber(0);
                        addtemptscore(ccc2048Map[x][y]->getNumber());
                        merge = true;
                    }

                    break;
                }
            }
        }
    }

    if(merge)addscore();
    rndaddNum();
    yousuck();
}

void MainWindow::addtemptscore(int i)
{
    temptscore+=i;
}

void MainWindow::addscore()
{
    score+=temptscore;

    ui-> lcdNumber -> display(score);
    if(score>Best)
    {
        Best= score;
        ui-> lcdNumber_2 -> display(Best);
    }

    temptscore = 0;
}

void MainWindow::yousuck()
{
    bool youlose=true;
    for(int j=0;j<4;j++)
    {
        for(int k=0;k<4;k++)
        {
            if(ccc2048Map[j][k]->getNumber()==0||
                (j>0&&(ccc2048Map[j][k]->getNumber()==ccc2048Map[j-1][k]->getNumber()))||
                (j<3&&(ccc2048Map[j][k]->getNumber()==ccc2048Map[j+1][k]->getNumber()))||
                (k>0&&(ccc2048Map[j][k]->getNumber()==ccc2048Map[j][k-1]->getNumber()))||
                (k<3&&(ccc2048Map[j][k]->getNumber()==ccc2048Map[j][k+1]->getNumber())))
            {
                youlose=false;
                break;
            }
        }
        if(youlose==false)break;

    }
    if(youlose)
    {
        GAMEOVER->show();
    }
}


void MainWindow::showEvent(QShowEvent*)
{
    if(first)
    {

        first=false;
        Gamestart();
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_Left:
        left();
        break;

        case Qt::Key_Right:
        right();
        break;

        case Qt::Key_Up:
        up();
        break;

        case Qt::Key_Down:
        down();
        break;

    }
}


void MainWindow::on_pushButton_clicked()
{
    Gamestart();
}
