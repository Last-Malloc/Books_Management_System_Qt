/********************************************************************************
** Form generated from reading UI file 'BMS.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BMS_H
#define UI_BMS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <headpor.h>

QT_BEGIN_NAMESPACE

class Ui_BMSClass
{
public:
    QWidget *centralWidget;
    HeadPor *lgFramePNG;
    QComboBox *lgID;
    QLabel *lgLableID;
    QLineEdit *lgPW;
    QLabel *lgLablePW;
    QCheckBox *remberPW;
    QToolButton *lgFindPW;
    QPushButton *lgOK;
    QToolButton *lgRegister;
    QToolButton *lgSet;
    QToolButton *lgMininum;
    QToolButton *lgClose;
    QToolButton *lgShowPW;

    void setupUi(QMainWindow *BMSClass)
    {
        if (BMSClass->objectName().isEmpty())
            BMSClass->setObjectName(QStringLiteral("BMSClass"));
        BMSClass->resize(700, 500);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BMSClass->sizePolicy().hasHeightForWidth());
        BMSClass->setSizePolicy(sizePolicy);
        BMSClass->setContextMenuPolicy(Qt::NoContextMenu);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../Resources/BMS\345\233\276\346\240\207.ico"), QSize(), QIcon::Normal, QIcon::Off);
        BMSClass->setWindowIcon(icon);
        BMSClass->setAutoFillBackground(false);
        BMSClass->setStyleSheet(QString::fromUtf8("#centralWidget{background-image: url(:/\347\231\273\345\275\225\347\225\214\351\235\242\347\232\204\345\233\272\345\256\232\345\233\276\347\211\207/Resources/\345\233\272\345\256\232/\350\203\214\346\231\2571.jpg);}\n"
"\n"
"#remberPW,#lgFindPW,#lgRegister\n"
"{\n"
"font: 12pt \"Adobe \351\273\221\344\275\223 Std R\";\n"
"}"));
        centralWidget = new QWidget(BMSClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8("image: url(:/\347\231\273\345\275\225\347\225\214\351\235\242\347\232\204\345\233\272\345\256\232\345\233\276\347\211\207/Resources/\347\231\273\345\275\225\347\225\214\351\235\242\350\203\214\346\231\257.jpg);"));
        lgFramePNG = new HeadPor(centralWidget);
        lgFramePNG->setObjectName(QStringLiteral("lgFramePNG"));
        lgFramePNG->setGeometry(QRect(320, 130, 100, 100));
        sizePolicy.setHeightForWidth(lgFramePNG->sizePolicy().hasHeightForWidth());
        lgFramePNG->setSizePolicy(sizePolicy);
        lgFramePNG->setStyleSheet(QStringLiteral(""));
        lgFramePNG->setFrameShape(QFrame::NoFrame);
        lgFramePNG->setFrameShadow(QFrame::Plain);
        lgID = new QComboBox(centralWidget);
        lgID->setObjectName(QStringLiteral("lgID"));
        lgID->setGeometry(QRect(250, 250, 261, 40));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lgID->sizePolicy().hasHeightForWidth());
        lgID->setSizePolicy(sizePolicy1);
        lgID->setMinimumSize(QSize(261, 40));
        lgID->setMaximumSize(QSize(241, 40));
        lgID->setStyleSheet(QString::fromUtf8("font: 18pt \"Adobe \351\273\221\344\275\223 Std R\";"));
        lgID->setEditable(true);
        lgID->setInsertPolicy(QComboBox::InsertAtBottom);
        lgID->setIconSize(QSize(28, 28));
        lgLableID = new QLabel(centralWidget);
        lgLableID->setObjectName(QStringLiteral("lgLableID"));
        lgLableID->setGeometry(QRect(190, 240, 50, 50));
        sizePolicy.setHeightForWidth(lgLableID->sizePolicy().hasHeightForWidth());
        lgLableID->setSizePolicy(sizePolicy);
        lgLableID->setPixmap(QPixmap(QString::fromUtf8(":/\347\231\273\345\275\225\347\225\214\351\235\242\347\232\204\345\233\272\345\256\232\345\233\276\347\211\207/Resources/\345\260\217\346\214\211\351\222\256/\347\224\250\346\210\267\345\220\215.ico")));
        lgLableID->setScaledContents(true);
        lgPW = new QLineEdit(centralWidget);
        lgPW->setObjectName(QStringLiteral("lgPW"));
        lgPW->setGeometry(QRect(250, 310, 211, 40));
        lgPW->setStyleSheet(QString::fromUtf8("font: 18pt \"Adobe \351\273\221\344\275\223 Std R\";"));
        lgPW->setEchoMode(QLineEdit::Password);
        lgPW->setCursorPosition(0);
        lgLablePW = new QLabel(centralWidget);
        lgLablePW->setObjectName(QStringLiteral("lgLablePW"));
        lgLablePW->setGeometry(QRect(190, 300, 50, 50));
        lgLablePW->setPixmap(QPixmap(QString::fromUtf8(":/\347\231\273\345\275\225\347\225\214\351\235\242\347\232\204\345\233\272\345\256\232\345\233\276\347\211\207/Resources/\345\260\217\346\214\211\351\222\256/\345\257\206\347\240\201.ico")));
        lgLablePW->setScaledContents(true);
        remberPW = new QCheckBox(centralWidget);
        remberPW->setObjectName(QStringLiteral("remberPW"));
        remberPW->setGeometry(QRect(220, 360, 110, 30));
        lgFindPW = new QToolButton(centralWidget);
        lgFindPW->setObjectName(QStringLiteral("lgFindPW"));
        lgFindPW->setGeometry(QRect(390, 360, 110, 30));
        lgFindPW->setAutoRaise(true);
        lgOK = new QPushButton(centralWidget);
        lgOK->setObjectName(QStringLiteral("lgOK"));
        lgOK->setGeometry(QRect(200, 400, 300, 60));
        lgOK->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 23pt \"Adobe \351\273\221\344\275\223 Std R\";\n"
"background-image: url(:/\347\231\273\345\275\225\347\225\214\351\235\242\347\232\204\345\233\272\345\256\232\345\233\276\347\211\207/Resources/\345\233\272\345\256\232/\347\231\273\345\275\225\346\214\211\351\222\256.jpg)"));
        lgRegister = new QToolButton(centralWidget);
        lgRegister->setObjectName(QStringLiteral("lgRegister"));
        lgRegister->setGeometry(QRect(597, 469, 110, 30));
        lgRegister->setAutoRaise(true);
        lgSet = new QToolButton(centralWidget);
        lgSet->setObjectName(QStringLiteral("lgSet"));
        lgSet->setGeometry(QRect(580, 0, 40, 40));
        lgSet->setAutoFillBackground(false);
        lgSet->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/\347\231\273\345\275\225\347\225\214\351\235\242\347\232\204\345\233\272\345\256\232\345\233\276\347\211\207/Resources/\345\260\217\346\214\211\351\222\256/\350\256\276\347\275\256.ico"), QSize(), QIcon::Normal, QIcon::Off);
        lgSet->setIcon(icon1);
        lgSet->setIconSize(QSize(40, 40));
        lgSet->setAutoRaise(true);
        lgMininum = new QToolButton(centralWidget);
        lgMininum->setObjectName(QStringLiteral("lgMininum"));
        lgMininum->setGeometry(QRect(620, 0, 40, 40));
        lgMininum->setStyleSheet(QStringLiteral(""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/\347\231\273\345\275\225\347\225\214\351\235\242\347\232\204\345\233\272\345\256\232\345\233\276\347\211\207/Resources/\345\260\217\346\214\211\351\222\256/\346\234\200\345\260\217\345\214\226.ico"), QSize(), QIcon::Normal, QIcon::Off);
        lgMininum->setIcon(icon2);
        lgMininum->setIconSize(QSize(40, 40));
        lgMininum->setAutoRaise(true);
        lgClose = new QToolButton(centralWidget);
        lgClose->setObjectName(QStringLiteral("lgClose"));
        lgClose->setGeometry(QRect(660, 0, 40, 40));
        lgClose->setStyleSheet(QStringLiteral(""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/\347\231\273\345\275\225\347\225\214\351\235\242\347\232\204\345\233\272\345\256\232\345\233\276\347\211\207/Resources/\345\260\217\346\214\211\351\222\256/\351\200\200\345\207\272.ico"), QSize(), QIcon::Normal, QIcon::Off);
        lgClose->setIcon(icon3);
        lgClose->setIconSize(QSize(30, 30));
        lgClose->setAutoRaise(true);
        lgShowPW = new QToolButton(centralWidget);
        lgShowPW->setObjectName(QStringLiteral("lgShowPW"));
        lgShowPW->setGeometry(QRect(470, 310, 41, 41));
        lgShowPW->setIconSize(QSize(40, 40));
        lgShowPW->setAutoRaise(true);
        BMSClass->setCentralWidget(centralWidget);

        retranslateUi(BMSClass);

        lgID->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(BMSClass);
    } // setupUi

    void retranslateUi(QMainWindow *BMSClass)
    {
        BMSClass->setWindowTitle(QApplication::translate("BMSClass", "BMS", nullptr));
#ifndef QT_NO_TOOLTIP
        BMSClass->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        lgID->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        lgID->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        lgLableID->setText(QString());
#ifndef QT_NO_TOOLTIP
        lgPW->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lgPW->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lgPW->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        lgPW->setInputMask(QString());
        lgPW->setText(QString());
        lgPW->setPlaceholderText(QApplication::translate("BMSClass", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        lgLablePW->setText(QString());
        remberPW->setText(QApplication::translate("BMSClass", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        lgFindPW->setText(QApplication::translate("BMSClass", "\346\211\276\345\233\236\345\257\206\347\240\201", nullptr));
        lgOK->setText(QApplication::translate("BMSClass", "\347\231\273         \345\275\225", nullptr));
        lgRegister->setText(QApplication::translate("BMSClass", "\346\263\250\345\206\214\350\264\246\345\217\267", nullptr));
        lgSet->setText(QApplication::translate("BMSClass", "\350\256\276\347\275\256", nullptr));
        lgMininum->setText(QApplication::translate("BMSClass", "\346\234\200\345\260\217\345\214\226", nullptr));
        lgClose->setText(QApplication::translate("BMSClass", "\345\205\263\351\227\255", nullptr));
        lgShowPW->setText(QApplication::translate("BMSClass", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BMSClass: public Ui_BMSClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BMS_H
