/********************************************************************************
** Form generated from reading UI file 'FindPassword.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDPASSWORD_H
#define UI_FINDPASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_FindPassword
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineID;
    QLineEdit *lineAnswer;
    QRadioButton *radioZH;
    QRadioButton *radioCZ;
    QLabel *label_3;
    QPushButton *btnOK;
    QToolButton *btnBack;

    void setupUi(QDialog *FindPassword)
    {
        if (FindPassword->objectName().isEmpty())
            FindPassword->setObjectName(QStringLiteral("FindPassword"));
        FindPassword->resize(450, 300);
        FindPassword->setStyleSheet(QString::fromUtf8("QLabel,QLineEdit,QRadioButton,QPushButton\n"
"{font: 15pt \"Adobe \351\273\221\344\275\223 Std R\";color:rgb(0, 0, 0)}\n"
"\n"
"#FindPassword\n"
"{image: url(:/\345\233\272\345\256\232/Resources/\345\233\272\345\256\232/\346\211\276\345\233\236\345\257\206\347\240\201\350\203\214\346\231\257.jpg);}\n"
"\n"
"QLineEdit\n"
"{background-color:rgb(255, 255, 255,0);}"));
        label = new QLabel(FindPassword);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 10, 71, 41));
        label_2 = new QLabel(FindPassword);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 140, 101, 41));
        lineID = new QLineEdit(FindPassword);
        lineID->setObjectName(QStringLiteral("lineID"));
        lineID->setGeometry(QRect(150, 10, 251, 41));
        lineID->setEchoMode(QLineEdit::Normal);
        lineID->setCursorPosition(0);
        lineAnswer = new QLineEdit(FindPassword);
        lineAnswer->setObjectName(QStringLiteral("lineAnswer"));
        lineAnswer->setGeometry(QRect(150, 140, 251, 41));
        lineAnswer->setAutoFillBackground(false);
        lineAnswer->setEchoMode(QLineEdit::Normal);
        lineAnswer->setCursorPosition(0);
        radioZH = new QRadioButton(FindPassword);
        radioZH->setObjectName(QStringLiteral("radioZH"));
        radioZH->setGeometry(QRect(70, 190, 151, 31));
        radioCZ = new QRadioButton(FindPassword);
        radioCZ->setObjectName(QStringLiteral("radioCZ"));
        radioCZ->setGeometry(QRect(250, 190, 151, 31));
        label_3 = new QLabel(FindPassword);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 60, 361, 71));
        label_3->setWordWrap(true);
        btnOK = new QPushButton(FindPassword);
        btnOK->setObjectName(QStringLiteral("btnOK"));
        btnOK->setGeometry(QRect(140, 230, 181, 51));
        btnOK->setStyleSheet(QString::fromUtf8("background-image: url(:/\345\233\272\345\256\232/Resources/\345\233\272\345\256\232/\347\231\273\345\275\225\346\214\211\351\222\256tip.jpg);"));
        btnBack = new QToolButton(FindPassword);
        btnBack->setObjectName(QStringLiteral("btnBack"));
        btnBack->setGeometry(QRect(390, 260, 61, 41));
        btnBack->setStyleSheet(QString::fromUtf8("font: 12pt \"Adobe \351\273\221\344\275\223 Std R\";"));
        btnBack->setAutoRaise(true);

        retranslateUi(FindPassword);

        QMetaObject::connectSlotsByName(FindPassword);
    } // setupUi

    void retranslateUi(QDialog *FindPassword)
    {
        FindPassword->setWindowTitle(QApplication::translate("FindPassword", "FindPassword", nullptr));
        label->setText(QApplication::translate("FindPassword", "\345\255\246\345\217\267", nullptr));
        label_2->setText(QApplication::translate("FindPassword", "\345\257\206\344\277\235\347\255\224\346\241\210", nullptr));
#ifndef QT_NO_TOOLTIP
        lineID->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineID->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineID->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        lineID->setInputMask(QString());
        lineID->setText(QString());
        lineID->setPlaceholderText(QApplication::translate("FindPassword", "\350\257\267\350\276\223\345\205\245\345\255\246\345\217\267", nullptr));
#ifndef QT_NO_TOOLTIP
        lineAnswer->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineAnswer->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineAnswer->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        lineAnswer->setInputMask(QString());
        lineAnswer->setText(QString());
        lineAnswer->setPlaceholderText(QApplication::translate("FindPassword", "\350\257\267\350\276\223\345\205\245\345\257\206\344\277\235\347\255\224\346\241\210", nullptr));
        radioZH->setText(QApplication::translate("FindPassword", "\346\211\276\345\233\236\345\257\206\347\240\201", nullptr));
        radioCZ->setText(QApplication::translate("FindPassword", "\351\207\215\347\275\256\345\257\206\347\240\201", nullptr));
        label_3->setText(QString());
        btnOK->setText(QApplication::translate("FindPassword", "\347\241\256    \345\256\232", nullptr));
        btnBack->setText(QApplication::translate("FindPassword", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FindPassword: public Ui_FindPassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDPASSWORD_H
