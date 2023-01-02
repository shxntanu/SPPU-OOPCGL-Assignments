#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QCoreApplication>

QImage image(700,700,QImage::Format_RGB888);

QRgb green(qRgb(0,255,0)), white(qRgb(255,255,255));

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    image.fill(qRgb(0,0,0));
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::delay(int n)
{
    QTime dieTime = QTime::currentTime().addMSecs(n);
    while(QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, n);
}

void MainWindow::on_pushButton_clicked()
{
    image.fill(qRgb(0,0,0));
    bresenham(350,322,58,white);

    dda(300,350,400,350,green);
    dda(300,350,350,264,green);
    dda(350,264,400,350,green);

    bresenham(350,322,29,white);
}

void MainWindow::on_pushButton_2_clicked()
{
    image.fill(qRgb(0,0,0));
    dda(150,250,550,250,white);
    dda(550,250,550,450,white);
    dda(550,450,150,450,white);
    dda(150,450,150,250,white);
    bresenham(350,350,87,green);
    dda(150,350,350,250,white);
    dda(350,250,550,350,white);
    dda(550,350,350,450,white);
    dda(350,450,150,350,white);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dda(double x1, double y1, double x2, double y2, QRgb color)
{
    double dx = x2 - x1, dy = y2 - y1, steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    double x = x1, y = y1;
    double xinc = dx/steps, yinc = dy/steps;
    for(int i=1; i<=steps;i++)
    {
        image.setPixel(x,y,color);
        x+=xinc;
        y+=yinc;
        ui->label->setPixmap(QPixmap::fromImage(image));
        delay(5);
    }
}

void MainWindow::bresenham(int x, int y, int r, QRgb color)
{
    int x3=0, y3=r;
    int d = 3 - 2*r;
    while(x3<=y3)
    {
        image.setPixel(x + x3, y + y3, color);
        image.setPixel(x - x3, y + y3, color);
        image.setPixel(x + x3, y - y3, color);
        image.setPixel(x - x3, y - y3, color);
        image.setPixel(x + y3, y + x3, color);
        image.setPixel(x - y3, y + x3, color);
        image.setPixel(x + y3, y - x3, color);
        image.setPixel(x - y3, y - x3, color);
        ui->label->setPixmap(QPixmap::fromImage(image));
        delay(5);

        if(d<0)
            d += 4*x3 + 6;
        else
        {
            d += 4*(x3 - y3) + 10;
            y3--;
        }
        x3++;
    }
}
