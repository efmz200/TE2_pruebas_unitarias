#include "widget.h"
#include "./ui_widget.h"
#include "Serv_client.cpp"
#include <QDebug>
#include <QMessageBox>
#include <iostream>
using namespace std;

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


void Widget::on_VertBut_clicked()
{
    QMessageBox::information(this,"Error","Función no disponible");

}

void Widget::on_AristaBut_clicked()
{
    QMessageBox::information(this,"Error","Función no disponible");
}

void Widget::on_GrafBut_clicked()
{
    QMessageBox::information(this,"Floyd Warshall",QString::fromStdString(cliente_serv()));
}
