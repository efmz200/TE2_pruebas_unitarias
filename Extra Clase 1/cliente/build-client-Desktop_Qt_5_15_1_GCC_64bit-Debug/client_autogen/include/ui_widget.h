/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *VertBut;
    QPushButton *AristaBut;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(505, 322);
        VertBut = new QPushButton(Widget);
        VertBut->setObjectName(QString::fromUtf8("VertBut"));
        VertBut->setGeometry(QRect(40, 240, 111, 31));
        AristaBut = new QPushButton(Widget);
        AristaBut->setObjectName(QString::fromUtf8("AristaBut"));
        AristaBut->setGeometry(QRect(160, 240, 111, 31));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        VertBut->setText(QCoreApplication::translate("Widget", "A\303\261adir Vertice", nullptr));
        AristaBut->setText(QCoreApplication::translate("Widget", "A\303\261adir Arista", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
