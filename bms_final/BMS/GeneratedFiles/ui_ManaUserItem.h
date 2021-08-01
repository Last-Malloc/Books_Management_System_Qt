/********************************************************************************
** Form generated from reading UI file 'ManaUserItem.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAUSERITEM_H
#define UI_MANAUSERITEM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <headpor.h>

QT_BEGIN_NAMESPACE

class Ui_ManaUserItem
{
public:
    HeadPor *frameHead;
    QToolButton *toolButton;
    QLabel *ID;
    QLabel *power;
    QLabel *name;
    QLabel *sex;
    QLabel *institute;
    QLabel *className;
    QFrame *line;

    void setupUi(QWidget *ManaUserItem)
    {
        if (ManaUserItem->objectName().isEmpty())
            ManaUserItem->setObjectName(QStringLiteral("ManaUserItem"));
        ManaUserItem->resize(1100, 120);
        ManaUserItem->setStyleSheet(QString::fromUtf8("#ManaUserItem{background-color: rgb(255, 255, 0);}\n"
"QLabel{\n"
"font: 16pt \"Adobe \351\273\221\344\275\223 Std R\";}\n"
"\n"
"QLabel,QToolButton{\n"
"background-color: rgba(255, 255, 255, 0);}"));
        frameHead = new HeadPor(ManaUserItem);
        frameHead->setObjectName(QStringLiteral("frameHead"));
        frameHead->setGeometry(QRect(40, 10, 100, 100));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frameHead->sizePolicy().hasHeightForWidth());
        frameHead->setSizePolicy(sizePolicy);
        frameHead->setFrameShape(QFrame::StyledPanel);
        frameHead->setFrameShadow(QFrame::Raised);
        toolButton = new QToolButton(ManaUserItem);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(958, 40, 50, 50));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/\347\224\250\346\210\267\347\225\214\351\235\242\345\260\217\346\214\211\351\222\256/Resources/\345\260\217\346\214\211\351\222\256/\346\234\252\351\200\211\344\270\255.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(40, 40));
        toolButton->setCheckable(true);
        toolButton->setPopupMode(QToolButton::DelayedPopup);
        toolButton->setAutoRaise(true);
        ID = new QLabel(ManaUserItem);
        ID->setObjectName(QStringLiteral("ID"));
        ID->setGeometry(QRect(180, 20, 151, 30));
        ID->setAlignment(Qt::AlignCenter);
        power = new QLabel(ManaUserItem);
        power->setObjectName(QStringLiteral("power"));
        power->setGeometry(QRect(185, 70, 141, 30));
        power->setAlignment(Qt::AlignCenter);
        name = new QLabel(ManaUserItem);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(437, 20, 81, 30));
        sex = new QLabel(ManaUserItem);
        sex->setObjectName(QStringLiteral("sex"));
        sex->setGeometry(QRect(463, 70, 31, 30));
        sex->setAlignment(Qt::AlignCenter);
        institute = new QLabel(ManaUserItem);
        institute->setObjectName(QStringLiteral("institute"));
        institute->setGeometry(QRect(650, 20, 111, 30));
        institute->setAlignment(Qt::AlignCenter);
        className = new QLabel(ManaUserItem);
        className->setObjectName(QStringLiteral("className"));
        className->setGeometry(QRect(660, 70, 101, 30));
        className->setAlignment(Qt::AlignCenter);
        line = new QFrame(ManaUserItem);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 117, 1100, 3));
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(3);
        line->setFrameShape(QFrame::HLine);

        retranslateUi(ManaUserItem);

        QMetaObject::connectSlotsByName(ManaUserItem);
    } // setupUi

    void retranslateUi(QWidget *ManaUserItem)
    {
        ManaUserItem->setWindowTitle(QApplication::translate("ManaUserItem", "ManaUserItem", nullptr));
        toolButton->setText(QApplication::translate("ManaUserItem", "...", nullptr));
        ID->setText(QString());
        power->setText(QString());
        name->setText(QString());
        sex->setText(QString());
        institute->setText(QString());
        className->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ManaUserItem: public Ui_ManaUserItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAUSERITEM_H
