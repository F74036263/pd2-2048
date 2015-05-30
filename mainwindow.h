#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QVector>
#include <QMainWindow>
#include <QLabel>
#include <time.h>
#include "ccc2048.h"
#include <QKeyEvent>
#include <QPoint>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void init();
    void setupccc2048();
    void Gamestart();
    void rndaddNum();
    void leftslide();// 向左移動tile.
    void rightslide();// 向右移動tile.
    void upslide();// 向上移動tile.
    void downslide();// 向下移動tile.
    void addtemptscore(int i);
    void addscore();
    void yousuck();



private slots:
    void on_pushButton_clicked();

private:
    void showEvent(QShowEvent*);
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
    QLabel *GAMEOVER;
    int Best,score,temptscore,wide,height;
    bool first;
    QVector< QVector<ccc2048*> > ccc2048Map;
    QList<QPoint> fucklist;

};

#endif // MAINWINDOW_H
