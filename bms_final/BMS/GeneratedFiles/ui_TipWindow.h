/********************************************************************************
** Form generated from reading UI file 'TipWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIPWINDOW_H
#define UI_TIPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TipWindow
{
public:
    QFrame *frame;
    QPushButton *OK;
    QPushButton *Cancel;

    void setupUi(QDialog *TipWindow)
    {
        if (TipWindow->objectName().isEmpty())
            TipWindow->setObjectName(QStringLiteral("TipWindow"));
        TipWindow->resize(384, 288);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TipWindow->sizePolicy().hasHeightForWidth());
        TipWindow->setSizePolicy(sizePolicy);
        TipWindow->setContextMenuPolicy(Qt::ActionsContextMenu);
        TipWindow->setStyleSheet(QString::fromUtf8("#TipWindow\n"
"{image: url(:/\345\233\272\345\256\232/Resources/\345\233\272\345\256\232/\350\203\214\346\231\257tip.jpg);}\n"
"\n"
"QPushButton\n"
"{background-image: url(:/\345\233\272\345\256\232/Resources/\345\233\272\345\256\232/\347\231\273\345\275\225\346\214\211\351\222\256tip.jpg);\n"
"font: 15pt \"Adobe \351\273\221\344\275\223 Std R\";}"));
        frame = new QFrame(TipWindow);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(40, 30, 300, 160));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        OK = new QPushButton(TipWindow);
        OK->setObjectName(QStringLiteral("OK"));
        OK->setGeometry(QRect(40, 220, 110, 50));
        Cancel = new QPushButton(TipWindow);
        Cancel->setObjectName(QStringLiteral("Cancel"));
        Cancel->setGeometry(QRect(230, 220, 110, 50));

        retranslateUi(TipWindow);

        QMetaObject::connectSlotsByName(TipWindow);
    } // setupUi

    void retranslateUi(QDialog *TipWindow)
    {
        TipWindow->setWindowTitle(QApplication::translate("TipWindow", "TipWindow", nullptr));
        OK->setText(QApplication::translate("TipWindow", "\347\241\256\350\256\244", nullptr));
        Cancel->setText(QApplication::translate("TipWindow", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TipWindow: public Ui_TipWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIPWINDOW_H
