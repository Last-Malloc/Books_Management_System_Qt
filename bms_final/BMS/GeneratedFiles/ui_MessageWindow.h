/********************************************************************************
** Form generated from reading UI file 'MessageWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGEWINDOW_H
#define UI_MESSAGEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MessageWindow
{
public:
    QListWidget *listWidget;
    QPushButton *btnOK;
    QPushButton *btnCancel;
    QPushButton *btnBack;

    void setupUi(QDialog *MessageWindow)
    {
        if (MessageWindow->objectName().isEmpty())
            MessageWindow->setObjectName(QStringLiteral("MessageWindow"));
        MessageWindow->resize(780, 500);
        MessageWindow->setStyleSheet(QString::fromUtf8("#MessageWindow{image: url(:/\347\256\241\347\220\206\345\221\230\347\225\214\351\235\242/Resources/\344\270\273\350\203\214\346\231\257/MessageImage.jpg);}"));
        listWidget = new QListWidget(MessageWindow);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 10, 761, 430));
        listWidget->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 100);"));
        btnOK = new QPushButton(MessageWindow);
        btnOK->setObjectName(QStringLiteral("btnOK"));
        btnOK->setGeometry(QRect(390, 460, 90, 30));
        btnOK->setStyleSheet(QString::fromUtf8("background-image: url(:/\345\233\272\345\256\232/Resources/\345\233\272\345\256\232/\347\231\273\345\275\225\346\214\211\351\222\256tip.jpg);"));
        btnCancel = new QPushButton(MessageWindow);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setGeometry(QRect(528, 460, 90, 30));
        btnCancel->setStyleSheet(QString::fromUtf8("background-image: url(:/\345\233\272\345\256\232/Resources/\345\233\272\345\256\232/\347\231\273\345\275\225\346\214\211\351\222\256tip.jpg);"));
        btnBack = new QPushButton(MessageWindow);
        btnBack->setObjectName(QStringLiteral("btnBack"));
        btnBack->setGeometry(QRect(666, 460, 90, 30));
        btnBack->setStyleSheet(QString::fromUtf8("background-image: url(:/\345\233\272\345\256\232/Resources/\345\233\272\345\256\232/\347\231\273\345\275\225\346\214\211\351\222\256tip.jpg);"));

        retranslateUi(MessageWindow);

        QMetaObject::connectSlotsByName(MessageWindow);
    } // setupUi

    void retranslateUi(QDialog *MessageWindow)
    {
        MessageWindow->setWindowTitle(QApplication::translate("MessageWindow", "MessageWindow", nullptr));
        btnOK->setText(QApplication::translate("MessageWindow", "\351\200\232\350\277\207", nullptr));
        btnCancel->setText(QApplication::translate("MessageWindow", "\344\270\215\351\200\232\350\277\207", nullptr));
        btnBack->setText(QApplication::translate("MessageWindow", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MessageWindow: public Ui_MessageWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEWINDOW_H
