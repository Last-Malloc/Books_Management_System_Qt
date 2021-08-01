/********************************************************************************
** Form generated from reading UI file 'ManaBookItem.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANABOOKITEM_H
#define UI_MANABOOKITEM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <headpor.h>

QT_BEGIN_NAMESPACE

class Ui_ManaBookItem
{
public:
    HeadPor *frameHead;
    QLabel *introduction;
    QToolButton *toolButton;
    QLabel *pubCompany;
    QLabel *pubDate;
    QLabel *ISBN;
    QLabel *name;
    QLabel *author;
    QLabel *category;
    QLabel *tableNumber;
    QLabel *storageRate;
    QFrame *line;

    void setupUi(QWidget *ManaBookItem)
    {
        if (ManaBookItem->objectName().isEmpty())
            ManaBookItem->setObjectName(QStringLiteral("ManaBookItem"));
        ManaBookItem->resize(1100, 150);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ManaBookItem->sizePolicy().hasHeightForWidth());
        ManaBookItem->setSizePolicy(sizePolicy);
        ManaBookItem->setStyleSheet(QString::fromUtf8("#ManaBookItem{background-color: rgb(255, 255, 0);}\n"
"QLabel{\n"
"font: 16pt \"Adobe \351\273\221\344\275\223 Std R\";}"));
        frameHead = new HeadPor(ManaBookItem);
        frameHead->setObjectName(QStringLiteral("frameHead"));
        frameHead->setGeometry(QRect(20, 10, 100, 130));
        sizePolicy.setHeightForWidth(frameHead->sizePolicy().hasHeightForWidth());
        frameHead->setSizePolicy(sizePolicy);
        frameHead->setFrameShape(QFrame::StyledPanel);
        frameHead->setFrameShadow(QFrame::Raised);
        introduction = new QLabel(ManaBookItem);
        introduction->setObjectName(QStringLiteral("introduction"));
        introduction->setGeometry(QRect(740, 10, 231, 131));
        introduction->setStyleSheet(QStringLiteral("font: 12pt \"Adobe Arabic\";"));
        introduction->setTextFormat(Qt::AutoText);
        introduction->setWordWrap(true);
        toolButton = new QToolButton(ManaBookItem);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(1000, 50, 50, 50));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/\347\224\250\346\210\267\347\225\214\351\235\242\345\260\217\346\214\211\351\222\256/Resources/\345\260\217\346\214\211\351\222\256/\346\234\252\351\200\211\344\270\255.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(40, 40));
        toolButton->setCheckable(true);
        toolButton->setPopupMode(QToolButton::DelayedPopup);
        toolButton->setAutoRaise(true);
        pubCompany = new QLabel(ManaBookItem);
        pubCompany->setObjectName(QStringLiteral("pubCompany"));
        pubCompany->setGeometry(QRect(520, 38, 193, 30));
        pubDate = new QLabel(ManaBookItem);
        pubDate->setObjectName(QStringLiteral("pubDate"));
        pubDate->setGeometry(QRect(570, 83, 100, 30));
        ISBN = new QLabel(ManaBookItem);
        ISBN->setObjectName(QStringLiteral("ISBN"));
        ISBN->setGeometry(QRect(140, 20, 235, 30));
        name = new QLabel(ManaBookItem);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(140, 63, 180, 30));
        author = new QLabel(ManaBookItem);
        author->setObjectName(QStringLiteral("author"));
        author->setGeometry(QRect(140, 105, 86, 30));
        category = new QLabel(ManaBookItem);
        category->setObjectName(QStringLiteral("category"));
        category->setGeometry(QRect(363, 63, 142, 30));
        tableNumber = new QLabel(ManaBookItem);
        tableNumber->setObjectName(QStringLiteral("tableNumber"));
        tableNumber->setGeometry(QRect(328, 105, 209, 30));
        storageRate = new QLabel(ManaBookItem);
        storageRate->setObjectName(QStringLiteral("storageRate"));
        storageRate->setGeometry(QRect(393, 20, 118, 30));
        line = new QFrame(ManaBookItem);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 148, 1100, 3));
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(3);
        line->setFrameShape(QFrame::HLine);

        retranslateUi(ManaBookItem);

        QMetaObject::connectSlotsByName(ManaBookItem);
    } // setupUi

    void retranslateUi(QWidget *ManaBookItem)
    {
        ManaBookItem->setWindowTitle(QApplication::translate("ManaBookItem", "ManaBookItem", nullptr));
        introduction->setText(QApplication::translate("ManaBookItem", "\346\234\254\344\271\246\351\246\226\345\205\210\347\225\214\345\256\232\344\272\206\346\263\225\345\276\213\347\232\204\345\256\232\344\271\211\357\274\214\350\256\244\345\256\232\346\263\225\345\276\213\346\230\257\344\270\216\345\234\260\347\220\206\343\200\201\345\234\237\345\243\244\343\200\201\346\260\224\345\200\231\343\200\201\344\272\272\347\247\215\343\200\201\351\243\216\344\277\227\343\200\201\344\271\240\346\203\257\343\200\201\345\256\227\346\225\231\344\277\241\344\273\260\343\200\201\344\272\272\345\217\243\345\222\214\345\225\206\344\270\232\347\255\211\345\205\263\347\263\273\347\232\204\347\273\274\345\220\210\343\200\202", nullptr));
        toolButton->setText(QApplication::translate("ManaBookItem", "...", nullptr));
        pubCompany->setText(QApplication::translate("ManaBookItem", "\347\231\276\350\212\261\346\226\207\350\211\272\345\207\272\347\211\210\347\244\276", nullptr));
        pubDate->setText(QApplication::translate("ManaBookItem", "2010.1", nullptr));
        ISBN->setText(QApplication::translate("ManaBookItem", "437-8-6111-4677-8", nullptr));
        name->setText(QApplication::translate("ManaBookItem", "\350\256\272\346\263\225\347\232\204\347\262\276\347\245\236", nullptr));
        author->setText(QApplication::translate("ManaBookItem", "\347\216\213\347\247\200\344\270\275", nullptr));
        category->setText(QApplication::translate("ManaBookItem", "\345\210\206\347\261\273:DF896", nullptr));
        tableNumber->setText(QApplication::translate("ManaBookItem", "\347\264\242\344\271\246\345\217\267:DF896/35", nullptr));
        storageRate->setText(QApplication::translate("ManaBookItem", "\345\272\223\345\255\230:66", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManaBookItem: public Ui_ManaBookItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANABOOKITEM_H
