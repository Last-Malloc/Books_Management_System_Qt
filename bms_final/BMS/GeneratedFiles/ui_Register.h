/********************************************************************************
** Form generated from reading UI file 'Register.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QToolButton>
#include <headpor.h>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QLabel *label_2;
    QLineEdit *lineName;
    QLineEdit *lineID;
    QToolButton *btnCancel;
    QLineEdit *lineClassName;
    QLabel *label_9;
    QLineEdit *lineAnswer;
    QPushButton *btnOK;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *linePassWord;
    QLabel *label_7;
    QLabel *label_12;
    QComboBox *cbQuestion;
    QCheckBox *checkBUser;
    QCheckBox *checkBMan;
    HeadPor *frame;
    QPushButton *btnCHead;
    QRadioButton *radioSexMan;
    QRadioButton *radioSexWoman;
    QLabel *label_5;
    QLineEdit *lineInstitute;

    void setupUi(QDialog *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QStringLiteral("Register"));
        Register->resize(400, 700);
        Register->setAutoFillBackground(false);
        Register->setStyleSheet(QString::fromUtf8("/*\345\255\227\344\275\223*/\n"
"QLabel,QToolButton\n"
"{font: 12pt \"Adobe \351\273\221\344\275\223 Std R\";}\n"
"\n"
"QRadioButton\n"
"{font: 15pt \"Adobe \351\273\221\344\275\223 Std R\";}\n"
"\n"
"QCheckBox,QLineEdit\n"
"{font: 13pt \"Adobe \351\273\221\344\275\223 Std R\";}\n"
"\n"
"#btnOK\n"
"{font: 20pt \"Adobe \351\273\221\344\275\223 Std R\";}\n"
"\n"
"QComboBox\n"
"{font: 10pt \"Adobe \351\273\221\344\275\223 Std R\";}\n"
"\n"
"/*\350\203\214\346\231\257\345\233\276*/\n"
"#Register\n"
"{background-image: url(:/\347\231\273\345\275\225\347\225\214\351\235\242\347\232\204\345\233\272\345\256\232\345\233\276\347\211\207/Resources/\345\233\272\345\256\232/\350\203\214\346\231\2572.jpg);}\n"
"\n"
"#btnOK,#btnCHead\n"
"{background-image: url(:/\347\231\273\345\275\225\347\225\214\351\235\242\347\232\204\345\233\272\345\256\232\345\233\276\347\211\207/Resources/\345\233\272\345\256\232/\347\231\273\345\275\225\346\214\211\351\222\256.jpg);}\n"
"\n"
"/*\351\242\234\350\211\262*/\n"
"QLineEdit\n"
"{background"
                        "-color:rgb(255, 255, 255,0);color: rgb(255, 255, 255);}\n"
"\n"
"QCheckBox\n"
"{color:rgb(255, 255, 255);}\n"
"\n"
"QLabel,QCheckBox,QToolButton,QRadioButton\n"
"{color:rgb(255, 255, 255);}\n"
""));
        label_2 = new QLabel(Register);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 320, 81, 41));
        lineName = new QLineEdit(Register);
        lineName->setObjectName(QStringLiteral("lineName"));
        lineName->setGeometry(QRect(120, 120, 200, 35));
        lineName->setAutoFillBackground(false);
        lineName->setStyleSheet(QStringLiteral(""));
        lineID = new QLineEdit(Register);
        lineID->setObjectName(QStringLiteral("lineID"));
        lineID->setGeometry(QRect(120, 200, 200, 35));
        btnCancel = new QToolButton(Register);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setGeometry(QRect(342, 662, 61, 41));
        btnCancel->setAutoRaise(true);
        lineClassName = new QLineEdit(Register);
        lineClassName->setObjectName(QStringLiteral("lineClassName"));
        lineClassName->setGeometry(QRect(120, 320, 200, 35));
        label_9 = new QLabel(Register);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(50, 500, 61, 41));
        lineAnswer = new QLineEdit(Register);
        lineAnswer->setObjectName(QStringLiteral("lineAnswer"));
        lineAnswer->setGeometry(QRect(120, 500, 200, 35));
        btnOK = new QPushButton(Register);
        btnOK->setObjectName(QStringLiteral("btnOK"));
        btnOK->setGeometry(QRect(100, 610, 214, 51));
        label = new QLabel(Register);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 120, 61, 31));
        label_3 = new QLabel(Register);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 200, 72, 41));
        linePassWord = new QLineEdit(Register);
        linePassWord->setObjectName(QStringLiteral("linePassWord"));
        linePassWord->setGeometry(QRect(120, 380, 200, 35));
        label_7 = new QLabel(Register);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(50, 380, 72, 51));
        label_7->setStyleSheet(QStringLiteral(""));
        label_12 = new QLabel(Register);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(20, 440, 101, 51));
        cbQuestion = new QComboBox(Register);
        cbQuestion->addItem(QString());
        cbQuestion->addItem(QString());
        cbQuestion->addItem(QString());
        cbQuestion->addItem(QString());
        cbQuestion->addItem(QString());
        cbQuestion->addItem(QString());
        cbQuestion->addItem(QString());
        cbQuestion->setObjectName(QStringLiteral("cbQuestion"));
        cbQuestion->setGeometry(QRect(120, 440, 200, 35));
        cbQuestion->setStyleSheet(QStringLiteral(""));
        cbQuestion->setEditable(true);
        checkBUser = new QCheckBox(Register);
        checkBUser->setObjectName(QStringLiteral("checkBUser"));
        checkBUser->setGeometry(QRect(60, 560, 120, 30));
        checkBMan = new QCheckBox(Register);
        checkBMan->setObjectName(QStringLiteral("checkBMan"));
        checkBMan->setGeometry(QRect(250, 560, 120, 30));
        frame = new HeadPor(Register);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(120, 20, 90, 90));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        btnCHead = new QPushButton(Register);
        btnCHead->setObjectName(QStringLiteral("btnCHead"));
        btnCHead->setGeometry(QRect(230, 50, 81, 41));
        radioSexMan = new QRadioButton(Register);
        radioSexMan->setObjectName(QStringLiteral("radioSexMan"));
        radioSexMan->setGeometry(QRect(120, 160, 51, 31));
        radioSexWoman = new QRadioButton(Register);
        radioSexWoman->setObjectName(QStringLiteral("radioSexWoman"));
        radioSexWoman->setGeometry(QRect(210, 160, 51, 31));
        label_5 = new QLabel(Register);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 260, 72, 41));
        lineInstitute = new QLineEdit(Register);
        lineInstitute->setObjectName(QStringLiteral("lineInstitute"));
        lineInstitute->setGeometry(QRect(120, 260, 200, 35));

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QDialog *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "Register", nullptr));
        label_2->setText(QApplication::translate("Register", "*\347\217\255\347\272\247", nullptr));
        lineName->setPlaceholderText(QApplication::translate("Register", "\347\234\237\345\256\236\345\247\223\345\220\215", nullptr));
        lineID->setText(QString());
        lineID->setPlaceholderText(QApplication::translate("Register", "10\344\275\215\346\225\260\345\255\227", nullptr));
        btnCancel->setText(QApplication::translate("Register", "\350\277\224\345\233\236", nullptr));
        lineClassName->setPlaceholderText(QApplication::translate("Register", "\344\276\213\345\246\202\350\256\241\347\256\227172", nullptr));
        label_9->setText(QApplication::translate("Register", "\347\255\224\346\241\210", nullptr));
        lineAnswer->setPlaceholderText(QApplication::translate("Register", "\345\257\206\344\277\235\347\255\224\346\241\210", nullptr));
        btnOK->setText(QApplication::translate("Register", "\347\241\256     \345\256\232", nullptr));
        label->setText(QApplication::translate("Register", "*\345\247\223\345\220\215", nullptr));
        label_3->setText(QApplication::translate("Register", "*\345\255\246\345\217\267", nullptr));
        linePassWord->setPlaceholderText(QString());
        label_7->setText(QApplication::translate("Register", "*\345\257\206\347\240\201", nullptr));
        label_12->setText(QApplication::translate("Register", "\345\257\206\344\277\235\351\227\256\351\242\230", nullptr));
        cbQuestion->setItemText(0, QApplication::translate("Register", "\344\270\215\350\256\276\347\275\256\345\257\206\344\277\235", nullptr));
        cbQuestion->setItemText(1, QApplication::translate("Register", "\344\275\240\347\232\204\347\234\237\345\256\236\345\247\223\345\220\215\346\230\257\357\274\237", nullptr));
        cbQuestion->setItemText(2, QApplication::translate("Register", "\344\275\240\347\232\204\347\224\237\346\227\245\346\230\257\357\274\237", nullptr));
        cbQuestion->setItemText(3, QApplication::translate("Register", "\344\275\240\347\210\266\344\272\262\347\232\204\345\220\215\345\255\227\346\230\257\357\274\237", nullptr));
        cbQuestion->setItemText(4, QApplication::translate("Register", "\344\275\240\346\257\215\344\272\262\347\232\204\345\220\215\345\255\227\346\230\257\357\274\237", nullptr));
        cbQuestion->setItemText(5, QApplication::translate("Register", "\344\275\240\346\234\200\345\226\234\346\254\242\347\232\204\346\230\216\346\230\237\346\230\257\357\274\237", nullptr));
        cbQuestion->setItemText(6, QApplication::translate("Register", "\344\275\240\346\234\200\345\245\275\347\232\204\346\234\213\345\217\213\346\230\257\357\274\237", nullptr));

        checkBUser->setText(QApplication::translate("Register", "\346\231\256\351\200\232\347\224\250\346\210\267", nullptr));
        checkBMan->setText(QApplication::translate("Register", "\347\256\241\347\220\206\345\221\230", nullptr));
        btnCHead->setText(QApplication::translate("Register", "\351\200\211\346\213\251\345\244\264\345\203\217", nullptr));
        radioSexMan->setText(QApplication::translate("Register", "\347\224\267", nullptr));
        radioSexWoman->setText(QApplication::translate("Register", "\345\245\263", nullptr));
        label_5->setText(QApplication::translate("Register", "*\345\255\246\351\231\242", nullptr));
#ifndef QT_NO_TOOLTIP
        lineInstitute->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineInstitute->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        lineInstitute->setText(QString());
        lineInstitute->setPlaceholderText(QApplication::translate("Register", "\344\276\213\345\246\202\357\274\232\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
