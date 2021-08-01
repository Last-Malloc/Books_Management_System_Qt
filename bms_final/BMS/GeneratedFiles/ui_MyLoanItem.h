/********************************************************************************
** Form generated from reading UI file 'MyLoanItem.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYLOANITEM_H
#define UI_MYLOANITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <headpor.h>

QT_BEGIN_NAMESPACE

class Ui_MyLoanItem
{
public:
    QPushButton *btnXuJie;
    QLabel *labelName;
    QLabel *labelISBN;
    QLabel *labelJie;
    QLabel *labelHuan;
    QLabel *labelXuJie;
    HeadPor *frameHead;

    void setupUi(QWidget *MyLoanItem)
    {
        if (MyLoanItem->objectName().isEmpty())
            MyLoanItem->setObjectName(QStringLiteral("MyLoanItem"));
        MyLoanItem->resize(1100, 150);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MyLoanItem->sizePolicy().hasHeightForWidth());
        MyLoanItem->setSizePolicy(sizePolicy);
        MyLoanItem->setStyleSheet(QString::fromUtf8("QLabel{font: 14pt \"Adobe \351\273\221\344\275\223 Std R\";}"));
        btnXuJie = new QPushButton(MyLoanItem);
        btnXuJie->setObjectName(QStringLiteral("btnXuJie"));
        btnXuJie->setGeometry(QRect(880, 50, 191, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font.setPointSize(20);
        btnXuJie->setFont(font);
        btnXuJie->setStyleSheet(QString::fromUtf8("background-image: url(:/\345\233\272\345\256\232/Resources/\345\233\272\345\256\232/\347\231\273\345\275\225\346\214\211\351\222\256tip.jpg);"));
        labelName = new QLabel(MyLoanItem);
        labelName->setObjectName(QStringLiteral("labelName"));
        labelName->setGeometry(QRect(190, 30, 191, 51));
        labelISBN = new QLabel(MyLoanItem);
        labelISBN->setObjectName(QStringLiteral("labelISBN"));
        labelISBN->setGeometry(QRect(170, 90, 211, 41));
        labelJie = new QLabel(MyLoanItem);
        labelJie->setObjectName(QStringLiteral("labelJie"));
        labelJie->setGeometry(QRect(430, 60, 131, 41));
        labelHuan = new QLabel(MyLoanItem);
        labelHuan->setObjectName(QStringLiteral("labelHuan"));
        labelHuan->setGeometry(QRect(610, 60, 131, 41));
        labelXuJie = new QLabel(MyLoanItem);
        labelXuJie->setObjectName(QStringLiteral("labelXuJie"));
        labelXuJie->setGeometry(QRect(760, 60, 71, 41));
        frameHead = new HeadPor(MyLoanItem);
        frameHead->setObjectName(QStringLiteral("frameHead"));
        frameHead->setGeometry(QRect(30, 10, 101, 131));
        frameHead->setFrameShape(QFrame::StyledPanel);
        frameHead->setFrameShadow(QFrame::Raised);

        retranslateUi(MyLoanItem);

        QMetaObject::connectSlotsByName(MyLoanItem);
    } // setupUi

    void retranslateUi(QWidget *MyLoanItem)
    {
        MyLoanItem->setWindowTitle(QApplication::translate("MyLoanItem", "MyLoanItem", nullptr));
        btnXuJie->setText(QApplication::translate("MyLoanItem", "\347\273\255 \345\200\237", nullptr));
        labelName->setText(QString());
        labelISBN->setText(QString());
        labelJie->setText(QString());
        labelHuan->setText(QString());
        labelXuJie->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MyLoanItem: public Ui_MyLoanItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYLOANITEM_H
