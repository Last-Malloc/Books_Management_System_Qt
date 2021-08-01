/********************************************************************************
** Form generated from reading UI file 'UserInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINTERFACE_H
#define UI_USERINTERFACE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <headpor.h>

QT_BEGIN_NAMESPACE

class Ui_UserInterface
{
public:
    HeadPor *frameHead;
    QLabel *label;
    QToolButton *btnCloth;
    QToolButton *btnHelp;
    QToolButton *btnClose;
    QToolButton *btnMin;
    QComboBox *comboBox;
    QFrame *frame;
    QToolButton *btnSearch;
    QLineEdit *lineEdit;
    QTabWidget *tabWidget;
    QWidget *tab;
    QListWidget *listBook;
    QFrame *cannotFound;
    QComboBox *cmbAuthor;
    QComboBox *cmbType;
    QComboBox *cmbPublish;
    QComboBox *cmbKuCun;
    QComboBox *cmbDate;
    QWidget *tab_2;
    QListWidget *listLoan;
    QToolButton *btnFreshen;
    QFrame *line;

    void setupUi(QWidget *UserInterface)
    {
        if (UserInterface->objectName().isEmpty())
            UserInterface->setObjectName(QStringLiteral("UserInterface"));
        UserInterface->resize(1199, 900);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(UserInterface->sizePolicy().hasHeightForWidth());
        UserInterface->setSizePolicy(sizePolicy);
        UserInterface->setStyleSheet(QString::fromUtf8("QComboBox{background-color: rgba(255, 255, 255, 50);}\n"
"\n"
"QLabel{\n"
"font: 16pt \"Adobe \351\273\221\344\275\223 Std R\";}"));
        frameHead = new HeadPor(UserInterface);
        frameHead->setObjectName(QStringLiteral("frameHead"));
        frameHead->setGeometry(QRect(50, 18, 100, 100));
        frameHead->setFrameShape(QFrame::StyledPanel);
        frameHead->setFrameShadow(QFrame::Raised);
        label = new QLabel(UserInterface);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(180, 57, 251, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(50);
        label->setFont(font);
        btnCloth = new QToolButton(UserInterface);
        btnCloth->setObjectName(QStringLiteral("btnCloth"));
        btnCloth->setGeometry(QRect(1028, 2, 40, 40));
        btnCloth->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/\347\224\250\346\210\267\347\225\214\351\235\242\345\260\217\346\214\211\351\222\256/Resources/\345\260\217\346\214\211\351\222\256/\347\232\256\350\202\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCloth->setIcon(icon);
        btnCloth->setIconSize(QSize(40, 40));
        btnCloth->setAutoRaise(true);
        btnHelp = new QToolButton(UserInterface);
        btnHelp->setObjectName(QStringLiteral("btnHelp"));
        btnHelp->setGeometry(QRect(1069, 0, 45, 43));
        btnHelp->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/\347\224\250\346\210\267\347\225\214\351\235\242\345\260\217\346\214\211\351\222\256/Resources/\345\260\217\346\214\211\351\222\256/\345\256\236\345\277\203\345\270\256\345\212\251.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnHelp->setIcon(icon1);
        btnHelp->setIconSize(QSize(40, 40));
        btnHelp->setAutoRaise(true);
        btnClose = new QToolButton(UserInterface);
        btnClose->setObjectName(QStringLiteral("btnClose"));
        btnClose->setGeometry(QRect(1160, 0, 40, 40));
        btnClose->setStyleSheet(QStringLiteral(""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/\347\224\250\346\210\267\347\225\214\351\235\242\345\260\217\346\214\211\351\222\256/Resources/\345\260\217\346\214\211\351\222\256/\345\256\236\345\277\203\345\205\263\351\227\255.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnClose->setIcon(icon2);
        btnClose->setIconSize(QSize(40, 40));
        btnClose->setAutoRaise(true);
        btnMin = new QToolButton(UserInterface);
        btnMin->setObjectName(QStringLiteral("btnMin"));
        btnMin->setGeometry(QRect(1110, -5, 50, 51));
        btnMin->setStyleSheet(QStringLiteral(""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/\347\224\250\346\210\267\347\225\214\351\235\242\345\260\217\346\214\211\351\222\256/Resources/\345\260\217\346\214\211\351\222\256/\345\256\236\345\277\203\346\234\200\345\260\217\345\214\226.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnMin->setIcon(icon3);
        btnMin->setIconSize(QSize(51, 49));
        btnMin->setAutoRaise(true);
        comboBox = new QComboBox(UserInterface);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(885, 5, 139, 36));
        comboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"font: 12pt \"Adobe \351\273\221\344\275\223 Std R\";\n"
"color: rgb(255, 255, 255);"));
        frame = new QFrame(UserInterface);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 1200, 900));
        frame->setAutoFillBackground(false);
        frame->setStyleSheet(QString::fromUtf8("#frame{image: url(:/\347\224\250\346\210\267\347\225\214\351\235\242/Resources/\347\224\250\346\210\267\347\225\214\351\235\242/\347\224\250\346\210\267\344\270\273\350\203\214\346\231\257.jpg);}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        btnSearch = new QToolButton(frame);
        btnSearch->setObjectName(QStringLiteral("btnSearch"));
        btnSearch->setGeometry(QRect(827, 115, 71, 71));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/\347\224\250\346\210\267\347\225\214\351\235\242\345\260\217\346\214\211\351\222\256/Resources/\345\260\217\346\214\211\351\222\256/search.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btnSearch->setIcon(icon4);
        btnSearch->setIconSize(QSize(68, 68));
        btnSearch->setAutoRaise(true);
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(300, 115, 511, 71));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font1.setPointSize(20);
        lineEdit->setFont(font1);
        lineEdit->setStyleSheet(QStringLiteral("background-color:rgba(255, 255, 255, 0)"));
        tabWidget = new QTabWidget(frame);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(27, 232, 1143, 641));
        QFont font2;
        font2.setFamily(QStringLiteral("Adobe Arabic"));
        font2.setPointSize(20);
        tabWidget->setFont(font2);
        tabWidget->setTabletTracking(false);
        tabWidget->setAutoFillBackground(false);
        tabWidget->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        tabWidget->setTabPosition(QTabWidget::West);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setDocumentMode(true);
        tabWidget->setTabBarAutoHide(false);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tab->setLayoutDirection(Qt::LeftToRight);
        tab->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"background-color: rgba(255, 255, 255, 100);font: 15pt \"Adobe \351\273\221\344\275\223 Std R\";}\n"
""));
        listBook = new QListWidget(tab);
        listBook->setObjectName(QStringLiteral("listBook"));
        listBook->setGeometry(QRect(0, 40, 1100, 601));
        listBook->setStyleSheet(QStringLiteral(""));
        listBook->setFrameShape(QFrame::WinPanel);
        listBook->setFrameShadow(QFrame::Raised);
        listBook->setBatchSize(100);
        listBook->setSelectionRectVisible(false);
        cannotFound = new QFrame(tab);
        cannotFound->setObjectName(QStringLiteral("cannotFound"));
        cannotFound->setGeometry(QRect(390, 250, 271, 281));
        cannotFound->setAutoFillBackground(false);
        cannotFound->setStyleSheet(QString::fromUtf8("image: url(:/\345\233\272\345\256\232/Resources/\345\233\272\345\256\232/\346\211\276\344\270\215\345\210\260\347\273\223\346\236\234.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        cannotFound->setFrameShape(QFrame::StyledPanel);
        cannotFound->setFrameShadow(QFrame::Raised);
        cmbAuthor = new QComboBox(tab);
        cmbAuthor->addItem(QString());
        cmbAuthor->setObjectName(QStringLiteral("cmbAuthor"));
        cmbAuthor->setGeometry(QRect(0, 0, 220, 40));
        cmbType = new QComboBox(tab);
        cmbType->addItem(QString());
        cmbType->setObjectName(QStringLiteral("cmbType"));
        cmbType->setGeometry(QRect(220, 0, 220, 40));
        cmbPublish = new QComboBox(tab);
        cmbPublish->addItem(QString());
        cmbPublish->setObjectName(QStringLiteral("cmbPublish"));
        cmbPublish->setGeometry(QRect(440, 0, 220, 40));
        cmbKuCun = new QComboBox(tab);
        cmbKuCun->addItem(QString());
        cmbKuCun->addItem(QString());
        cmbKuCun->addItem(QString());
        cmbKuCun->setObjectName(QStringLiteral("cmbKuCun"));
        cmbKuCun->setGeometry(QRect(660, 0, 200, 40));
        cmbDate = new QComboBox(tab);
        cmbDate->addItem(QString());
        cmbDate->addItem(QString());
        cmbDate->addItem(QString());
        cmbDate->setObjectName(QStringLiteral("cmbDate"));
        cmbDate->setGeometry(QRect(860, 0, 240, 40));
        cmbDate->setFrame(true);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tab_2->setStyleSheet(QStringLiteral(""));
        listLoan = new QListWidget(tab_2);
        listLoan->setObjectName(QStringLiteral("listLoan"));
        listLoan->setGeometry(QRect(0, 0, 1100, 641));
        tabWidget->addTab(tab_2, QString());
        btnFreshen = new QToolButton(frame);
        btnFreshen->setObjectName(QStringLiteral("btnFreshen"));
        btnFreshen->setGeometry(QRect(835, 0, 47, 47));
        btnFreshen->setStyleSheet(QStringLiteral(""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/\347\224\250\346\210\267\347\225\214\351\235\242\345\260\217\346\214\211\351\222\256/Resources/\345\260\217\346\214\211\351\222\256/\345\210\267\346\226\260.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnFreshen->setIcon(icon5);
        btnFreshen->setIconSize(QSize(45, 45));
        btnFreshen->setAutoRaise(true);
        line = new QFrame(UserInterface);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(176, 93, 169, 16));
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(2);
        line->setFrameShape(QFrame::HLine);
        frame->raise();
        frameHead->raise();
        btnCloth->raise();
        btnHelp->raise();
        btnClose->raise();
        btnMin->raise();
        comboBox->raise();
        line->raise();
        label->raise();

        retranslateUi(UserInterface);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(UserInterface);
    } // setupUi

    void retranslateUi(QWidget *UserInterface)
    {
        UserInterface->setWindowTitle(QApplication::translate("UserInterface", "UserInterface", nullptr));
        label->setText(QApplication::translate("UserInterface", "\344\275\240\345\245\275\357\274\214\351\237\251\345\271\277\351\230\263", nullptr));
        btnCloth->setText(QApplication::translate("UserInterface", "\346\234\200\345\260\217\345\214\226", nullptr));
        btnHelp->setText(QApplication::translate("UserInterface", "\346\234\200\345\260\217\345\214\226", nullptr));
        btnClose->setText(QApplication::translate("UserInterface", "\346\234\200\345\260\217\345\214\226", nullptr));
        btnMin->setText(QApplication::translate("UserInterface", "\346\234\200\345\260\217\345\214\226", nullptr));
        comboBox->setItemText(0, QApplication::translate("UserInterface", "1704040212", nullptr));
        comboBox->setItemText(1, QApplication::translate("UserInterface", "\346\210\221\347\232\204\344\277\241\346\201\257", nullptr));
        comboBox->setItemText(2, QApplication::translate("UserInterface", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        comboBox->setItemText(3, QApplication::translate("UserInterface", "\346\263\250\351\224\200\347\231\273\345\275\225", nullptr));
        comboBox->setItemText(4, QApplication::translate("UserInterface", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));

        btnSearch->setText(QApplication::translate("UserInterface", "...", nullptr));
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QApplication::translate("UserInterface", "\350\257\267\350\276\223\345\205\245\346\237\245\350\257\242\345\205\263\351\224\256\345\255\227\346\210\22613\344\275\215ISBN\347\240\201", nullptr));
        cmbAuthor->setItemText(0, QApplication::translate("UserInterface", "\344\270\215\351\231\220\345\210\266\344\275\234\350\200\205", nullptr));

        cmbType->setItemText(0, QApplication::translate("UserInterface", "\344\270\215\351\231\220\345\210\266\345\210\206\347\261\273", nullptr));

        cmbPublish->setItemText(0, QApplication::translate("UserInterface", "\344\270\215\351\231\220\345\210\266\345\207\272\347\211\210\347\244\276", nullptr));

        cmbKuCun->setItemText(0, QApplication::translate("UserInterface", "\345\272\223\345\255\230(\351\273\230\350\256\244\346\216\222\345\272\217)", nullptr));
        cmbKuCun->setItemText(1, QApplication::translate("UserInterface", "\345\272\223\345\255\230\351\231\215\345\272\217", nullptr));
        cmbKuCun->setItemText(2, QApplication::translate("UserInterface", "\345\272\223\345\255\230\345\215\207\345\272\217", nullptr));

        cmbDate->setItemText(0, QApplication::translate("UserInterface", "\345\207\272\347\211\210\346\227\245\346\234\237(\351\273\230\350\256\244\346\216\222\345\272\217)", nullptr));
        cmbDate->setItemText(1, QApplication::translate("UserInterface", "\345\207\272\347\211\210\346\227\245\346\234\237\351\231\215\345\272\217", nullptr));
        cmbDate->setItemText(2, QApplication::translate("UserInterface", "\345\207\272\347\211\210\346\227\245\346\234\237\345\215\207\345\272\217", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("UserInterface", "\344\271\246\347\261\215\346\237\245\350\257\242", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("UserInterface", "\346\210\221\347\232\204\345\200\237\351\230\205", nullptr));
        btnFreshen->setText(QApplication::translate("UserInterface", "\346\234\200\345\260\217\345\214\226", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserInterface: public Ui_UserInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINTERFACE_H
