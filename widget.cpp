#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{

    delete ui;
}

void Widget::changeEnabled(){
    ui->pbReset->setEnabled(money>0);
    ui->pbCoffee->setEnabled(money>=100);
    ui->pbTea->setEnabled(money>=200);
    ui->pbTang->setEnabled(money>=300);
}

void Widget::changeMoney (int diff)
{
    money+=diff;
    ui->lcdNumber->display(money);

    changeEnabled();
};

void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);

}


void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}


void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbTang_clicked()
{
    changeMoney(-300);
}



void Widget::on_pbReset_clicked()
{
    QMessageBox mb;

    //algorithm
    int coin500,coin100,coin50,coin10;

    coin500 = money /500;
    money %= 500;
    coin100 = money/100;
    money %= 100;
    coin50 = money/50;
    money %= 50;
    coin10 = money/10;
    money =0;

    QString message = QString("500won: %1\n100won: %2\n50won: %3\n10won: %4").arg(QString::number(coin500)).arg(QString::number(coin100)).arg(QString::number(coin50)).arg(QString::number(coin10));

    mb.information(nullptr, "remain Coin", message );
    changeMoney(0);
}


void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
}

