/********************************************************************************
** Form generated from reading UI file 'WinMyInfo.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINMYINFO_H
#define UI_WINMYINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <headpor.h>

QT_BEGIN_NAMESPACE

class Ui_WinMyInfo
{
public:
    HeadPor *frame;
    QPushButton *btnCHead;
    QToolButton *btnCancel;
    QFrame *frame_2;
    QLabel *label_7;
    QLabel *label_5;
    QComboBox *cbQuestion;
    QLineEdit *lineAnswer;
    QPushButton *btnOK;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *label_2;
    QLabel *label;

    void setupUi(QDialog *WinMyInfo)
    {
        if (WinMyInfo->objectName().isEmpty())
            WinMyInfo->setObjectName(QStringLiteral("WinMyInfo"));
        WinMyInfo->resize(380, 500);
        WinMyInfo->setStyleSheet(QString::fromUtf8("QLabel,QPushButton,QToolButton\n"
"{font: 12pt \"Adobe \351\273\221\344\275\223 Std R\";}"));
        frame = new HeadPor(WinMyInfo);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(88, 20, 90, 90));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        btnCHead = new QPushButton(WinMyInfo);
        btnCHead->setObjectName(QStringLiteral("btnCHead"));
        btnCHead->setGeometry(QRect(219, 46, 91, 41));
        btnCHead->setStyleSheet(QString::fromUtf8("background-image: url(:/\345\233\272\345\256\232/Resources/\345\233\272\345\256\232/\347\231\273\345\275\225\346\214\211\351\222\256tip.jpg);"));
        btnCancel = new QToolButton(WinMyInfo);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setGeometry(QRect(322, 461, 61, 41));
        btnCancel->setAutoRaise(true);
        frame_2 = new QFrame(WinMyInfo);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(0, 0, 380, 500));
        frame_2->setStyleSheet(QString::fromUtf8("#frame_2{image: url(:/\347\224\250\346\210\267\347\225\214\351\235\242/Resources/\345\233\272\345\256\232/\346\210\221\347\232\204\344\277\241\346\201\257\350\203\214\346\231\257.jpg);}"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_7 = new QLabel(frame_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(50, 320, 101, 51));
        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 360, 81, 51));
        cbQuestion = new QComboBox(frame_2);
        cbQuestion->addItem(QString());
        cbQuestion->addItem(QString());
        cbQuestion->addItem(QString());
        cbQuestion->addItem(QString());
        cbQuestion->addItem(QString());
        cbQuestion->addItem(QString());
        cbQuestion->addItem(QString());
        cbQuestion->setObjectName(QStringLiteral("cbQuestion"));
        cbQuestion->setGeometry(QRect(140, 320, 200, 35));
        cbQuestion->setStyleSheet(QStringLiteral(""));
        cbQuestion->setEditable(true);
        lineAnswer = new QLineEdit(frame_2);
        lineAnswer->setObjectName(QStringLiteral("lineAnswer"));
        lineAnswer->setGeometry(QRect(140, 370, 200, 35));
        btnOK = new QPushButton(frame_2);
        btnOK->setObjectName(QStringLiteral("btnOK"));
        btnOK->setGeometry(QRect(100, 430, 181, 51));
        btnOK->setAutoFillBackground(false);
        btnOK->setStyleSheet(QString::fromUtf8("background-image: url(:/\345\233\272\345\256\232/Resources/\345\233\272\345\256\232/\347\231\273\345\275\225\346\214\211\351\222\256tip.jpg);"));
        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 270, 271, 51));
        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(50, 120, 101, 51));
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 170, 331, 51));
        label = new QLabel(frame_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 220, 291, 51));
        frame_2->raise();
        frame->raise();
        btnCHead->raise();
        btnCancel->raise();

        retranslateUi(WinMyInfo);

        QMetaObject::connectSlotsByName(WinMyInfo);
    } // setupUi

    void retranslateUi(QDialog *WinMyInfo)
    {
        WinMyInfo->setWindowTitle(QApplication::translate("WinMyInfo", "WinMyInfo", nullptr));
        btnCHead->setText(QApplication::translate("WinMyInfo", "\346\233\264\346\215\242\345\244\264\345\203\217", nullptr));
        btnCancel->setText(QApplication::translate("WinMyInfo", "\350\277\224\345\233\236", nullptr));
        label_7->setText(QApplication::translate("WinMyInfo", "\345\257\206\344\277\235\351\227\256\351\242\230", nullptr));
        label_5->setText(QApplication::translate("WinMyInfo", "\345\257\206\344\277\235\347\255\224\346\241\210", nullptr));
        cbQuestion->setItemText(0, QApplication::translate("WinMyInfo", "\344\270\215\350\256\276\347\275\256\345\257\206\344\277\235", nullptr));
        cbQuestion->setItemText(1, QApplication::translate("WinMyInfo", "\344\275\240\347\232\204\347\234\237\345\256\236\345\247\223\345\220\215\346\230\257\357\274\237", nullptr));
        cbQuestion->setItemText(2, QApplication::translate("WinMyInfo", "\344\275\240\347\232\204\347\224\237\346\227\245\346\230\257\357\274\237", nullptr));
        cbQuestion->setItemText(3, QApplication::translate("WinMyInfo", "\344\275\240\347\210\266\344\272\262\347\232\204\345\220\215\345\255\227\346\230\257\357\274\237", nullptr));
        cbQuestion->setItemText(4, QApplication::translate("WinMyInfo", "\344\275\240\346\257\215\344\272\262\347\232\204\345\220\215\345\255\227\346\230\257\357\274\237", nullptr));
        cbQuestion->setItemText(5, QApplication::translate("WinMyInfo", "\344\275\240\346\234\200\345\226\234\346\254\242\347\232\204\346\230\216\346\230\237\346\230\257\357\274\237", nullptr));
        cbQuestion->setItemText(6, QApplication::translate("WinMyInfo", "\344\275\240\346\234\200\345\245\275\347\232\204\346\234\213\345\217\213\346\230\257\357\274\237", nullptr));

        lineAnswer->setPlaceholderText(QApplication::translate("WinMyInfo", "\345\257\206\344\277\235\347\255\224\346\241\210", nullptr));
        btnOK->setText(QApplication::translate("WinMyInfo", "\347\241\256\345\256\232", nullptr));
        label_3->setText(QString());
        label_6->setText(QString());
        label_2->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WinMyInfo: public Ui_WinMyInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINMYINFO_H
