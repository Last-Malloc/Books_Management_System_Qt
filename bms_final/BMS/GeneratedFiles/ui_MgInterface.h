/********************************************************************************
** Form generated from reading UI file 'MgInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MGINTERFACE_H
#define UI_MGINTERFACE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <headpor.h>
#include <messagebutton.h>

QT_BEGIN_NAMESPACE

class Ui_MgInterface
{
public:
    QTabWidget *tabWidget;
    QWidget *tab_A;
    QTabWidget *tabWidgetOfA;
    QWidget *tab_A_1;
    QWidget *MyBookToolBar;
    QLineEdit *bookBarKey;
    QPushButton *bkBarChgeHead;
    QToolButton *bookBarSearch;
    QComboBox *cmbType;
    QComboBox *cmbPublish;
    QComboBox *cmbAuthor;
    QComboBox *cmbKuCun;
    QComboBox *cmbDate;
    QPushButton *bkBarAlter;
    QPushButton *bkBarDelete;
    QPushButton *bookBarSelect;
    HeadPor *bkBarHead;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLineEdit *bkBarISBN;
    QLineEdit *bkBarName;
    QLineEdit *bkBarAuthor;
    QLineEdit *bookBarcategory;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *bkBarPubCompany;
    QLineEdit *bkBarPubDate;
    QLineEdit *bkBarTableNumber;
    QLineEdit *bkBarStorageRate;
    QPlainTextEdit *bkBarIntroduction;
    QToolButton *btnBookBarHide;
    QListWidget *listWidgetOfBook;
    QFrame *cannotFound;
    QWidget *tab_A_2;
    QPushButton *sJiaChooseFile;
    HeadPor *sJiaHead;
    QPushButton *sJiaChgeHead;
    QPushButton *sJiaOK;
    QLabel *sJiaFilepath;
    QFrame *line_2;
    QLabel *label_11;
    QLabel *label_12;
    QPlainTextEdit *sJiaIntroduction;
    QLabel *label_13;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *sJiaISBN;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *sJiaName;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *sJiaAuthor;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLineEdit *sJiaCategory;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_8;
    QLineEdit *sJiaPubCompany;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *sJiaPubDate;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_10;
    QLineEdit *sJiaTableNumber;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QLineEdit *sJiaStorageRate;
    QWidget *tab_B;
    QLineEdit *jYueLIneID;
    QLineEdit *jYueLineISBN;
    QComboBox *jYueOrder;
    QListWidget *listLeft;
    QListWidget *listRight;
    QPushButton *jYueButton;
    QFrame *cannotFoundLeft;
    QFrame *cannotFoundRight;
    QWidget *tab_C;
    QFrame *userBar;
    QComboBox *userBarCBSex;
    QComboBox *userBarCBSort;
    QLineEdit *userBarKey;
    QComboBox *userBarCBClass;
    QToolButton *userBarSearch;
    QComboBox *userBarCBInstitute;
    HeadPor *userBarHead;
    QPushButton *userBarOK;
    QPushButton *userBarDelete;
    QPushButton *userBarSelectAll;
    QPushButton *userBarResetPW;
    QLabel *userBarPower;
    QLabel *userBarID;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_15;
    QLineEdit *userBarName;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_16;
    QLineEdit *userBarSex;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_17;
    QLineEdit *userBarInstitute;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_18;
    QLineEdit *userBarClass;
    QListWidget *listUser;
    QToolButton *userBarHide;
    QFrame *userCannotFound;
    QFrame *beiJingBan;
    MessageButton *btnMessage;
    QToolButton *btnClose;
    QToolButton *btnMin;
    QToolButton *btnHelp;
    QToolButton *btnCloth;
    QComboBox *comboBox;
    HeadPor *frameHead;
    QLabel *label;
    QFrame *line;
    QToolButton *btnFreshen;

    void setupUi(QWidget *MgInterface)
    {
        if (MgInterface->objectName().isEmpty())
            MgInterface->setObjectName(QStringLiteral("MgInterface"));
        MgInterface->resize(1200, 900);
        MgInterface->setStyleSheet(QStringLiteral("ToolButtom{background-color: rgba(255, 255, 255, 0);}"));
        tabWidget = new QTabWidget(MgInterface);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(31, 160, 1137, 720));
        QFont font;
        font.setFamily(QStringLiteral("Adobe Arabic"));
        font.setPointSize(20);
        tabWidget->setFont(font);
        tabWidget->setTabletTracking(false);
        tabWidget->setAutoFillBackground(false);
        tabWidget->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        tabWidget->setTabPosition(QTabWidget::West);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setDocumentMode(true);
        tabWidget->setTabBarAutoHide(false);
        tab_A = new QWidget();
        tab_A->setObjectName(QStringLiteral("tab_A"));
        tab_A->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        tabWidgetOfA = new QTabWidget(tab_A);
        tabWidgetOfA->setObjectName(QStringLiteral("tabWidgetOfA"));
        tabWidgetOfA->setGeometry(QRect(0, 0, 1100, 720));
        tabWidgetOfA->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 50);\n"
"font: 16pt \"Adobe \351\273\221\344\275\223 Std R\";"));
        tabWidgetOfA->setTabPosition(QTabWidget::North);
        tabWidgetOfA->setTabShape(QTabWidget::Rounded);
        tabWidgetOfA->setDocumentMode(true);
        tabWidgetOfA->setTabBarAutoHide(false);
        tab_A_1 = new QWidget();
        tab_A_1->setObjectName(QStringLiteral("tab_A_1"));
        tab_A_1->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        MyBookToolBar = new QWidget(tab_A_1);
        MyBookToolBar->setObjectName(QStringLiteral("MyBookToolBar"));
        MyBookToolBar->setGeometry(QRect(0, 360, 1100, 320));
        MyBookToolBar->setStyleSheet(QStringLiteral("background-color: rgb(85, 255, 255);"));
        bookBarKey = new QLineEdit(MyBookToolBar);
        bookBarKey->setObjectName(QStringLiteral("bookBarKey"));
        bookBarKey->setGeometry(QRect(5, 5, 400, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        bookBarKey->setFont(font1);
        bookBarKey->setStyleSheet(QStringLiteral("background-color:rgba(255, 255, 255, 0)"));
        bkBarChgeHead = new QPushButton(MyBookToolBar);
        bkBarChgeHead->setObjectName(QStringLiteral("bkBarChgeHead"));
        bkBarChgeHead->setGeometry(QRect(30, 240, 111, 31));
        bkBarChgeHead->setStyleSheet(QString::fromUtf8("background-image: url(:/\345\233\272\345\256\232/Resources/\345\233\272\345\256\232/\347\231\273\345\275\225\346\214\211\351\222\256tip.jpg);"));
        bookBarSearch = new QToolButton(MyBookToolBar);
        bookBarSearch->setObjectName(QStringLiteral("bookBarSearch"));
        bookBarSearch->setGeometry(QRect(410, 5, 40, 40));
        bookBarSearch->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/\347\224\250\346\210\267\347\225\214\351\235\242\345\260\217\346\214\211\351\222\256/Resources/\345\260\217\346\214\211\351\222\256/search.ico"), QSize(), QIcon::Normal, QIcon::Off);
        bookBarSearch->setIcon(icon);
        bookBarSearch->setIconSize(QSize(68, 68));
        bookBarSearch->setPopupMode(QToolButton::DelayedPopup);
        bookBarSearch->setAutoRaise(true);
        bookBarSearch->setArrowType(Qt::NoArrow);
        cmbType = new QComboBox(MyBookToolBar);
        cmbType->addItem(QString());
        cmbType->setObjectName(QStringLiteral("cmbType"));
        cmbType->setGeometry(QRect(870, 5, 221, 40));
        cmbPublish = new QComboBox(MyBookToolBar);
        cmbPublish->addItem(QString());
        cmbPublish->setObjectName(QStringLiteral("cmbPublish"));
        cmbPublish->setGeometry(QRect(651, 5, 203, 40));
        cmbAuthor = new QComboBox(MyBookToolBar);
        cmbAuthor->addItem(QString());
        cmbAuthor->setObjectName(QStringLiteral("cmbAuthor"));
        cmbAuthor->setGeometry(QRect(456, 5, 190, 40));
        cmbKuCun = new QComboBox(MyBookToolBar);
        cmbKuCun->addItem(QString());
        cmbKuCun->addItem(QString());
        cmbKuCun->addItem(QString());
        cmbKuCun->setObjectName(QStringLiteral("cmbKuCun"));
        cmbKuCun->setGeometry(QRect(180, 50, 211, 40));
        cmbDate = new QComboBox(MyBookToolBar);
        cmbDate->addItem(QString());
        cmbDate->addItem(QString());
        cmbDate->addItem(QString());
        cmbDate->setObjectName(QStringLiteral("cmbDate"));
        cmbDate->setGeometry(QRect(400, 50, 205, 40));
        cmbDate->setFrame(true);
        bkBarAlter = new QPushButton(MyBookToolBar);
        bkBarAlter->setObjectName(QStringLiteral("bkBarAlter"));
        bkBarAlter->setGeometry(QRect(940, 220, 111, 31));
        bkBarAlter->setStyleSheet(QString::fromUtf8("background-image: url(:/\345\233\272\345\256\232/Resources/\345\233\272\345\256\232/\347\231\273\345\275\225\346\214\211\351\222\256tip.jpg);"));
        bkBarDelete = new QPushButton(MyBookToolBar);
        bkBarDelete->setObjectName(QStringLiteral("bkBarDelete"));
        bkBarDelete->setGeometry(QRect(940, 160, 111, 31));
        bkBarDelete->setStyleSheet(QString::fromUtf8("background-image: url(:/\345\233\272\345\256\232/Resources/\345\233\272\345\256\232/\347\231\273\345\275\225\346\214\211\351\222\256tip.jpg);"));
        bookBarSelect = new QPushButton(MyBookToolBar);
        bookBarSelect->setObjectName(QStringLiteral("bookBarSelect"));
        bookBarSelect->setGeometry(QRect(920, 110, 151, 31));
        bookBarSelect->setStyleSheet(QString::fromUtf8("background-image: url(:/\345\233\272\345\256\232/Resources/\345\233\272\345\256\232/\347\231\273\345\275\225\346\214\211\351\222\256tip.jpg);"));
        bkBarHead = new HeadPor(MyBookToolBar);
        bkBarHead->setObjectName(QStringLiteral("bkBarHead"));
        bkBarHead->setGeometry(QRect(40, 98, 100, 130));
        bkBarHead->setStyleSheet(QStringLiteral(""));
        bkBarHead->setFrameShape(QFrame::StyledPanel);
        bkBarHead->setFrameShadow(QFrame::Raised);
        layoutWidget = new QWidget(MyBookToolBar);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(160, 100, 731, 185));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        bkBarISBN = new QLineEdit(layoutWidget);
        bkBarISBN->setObjectName(QStringLiteral("bkBarISBN"));

        verticalLayout->addWidget(bkBarISBN);

        bkBarName = new QLineEdit(layoutWidget);
        bkBarName->setObjectName(QStringLiteral("bkBarName"));

        verticalLayout->addWidget(bkBarName);

        bkBarAuthor = new QLineEdit(layoutWidget);
        bkBarAuthor->setObjectName(QStringLiteral("bkBarAuthor"));

        verticalLayout->addWidget(bkBarAuthor);

        bookBarcategory = new QLineEdit(layoutWidget);
        bookBarcategory->setObjectName(QStringLiteral("bookBarcategory"));

        verticalLayout->addWidget(bookBarcategory);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        bkBarPubCompany = new QLineEdit(layoutWidget);
        bkBarPubCompany->setObjectName(QStringLiteral("bkBarPubCompany"));

        verticalLayout_2->addWidget(bkBarPubCompany);

        bkBarPubDate = new QLineEdit(layoutWidget);
        bkBarPubDate->setObjectName(QStringLiteral("bkBarPubDate"));

        verticalLayout_2->addWidget(bkBarPubDate);

        bkBarTableNumber = new QLineEdit(layoutWidget);
        bkBarTableNumber->setObjectName(QStringLiteral("bkBarTableNumber"));

        verticalLayout_2->addWidget(bkBarTableNumber);

        bkBarStorageRate = new QLineEdit(layoutWidget);
        bkBarStorageRate->setObjectName(QStringLiteral("bkBarStorageRate"));

        verticalLayout_2->addWidget(bkBarStorageRate);


        horizontalLayout->addLayout(verticalLayout_2);

        bkBarIntroduction = new QPlainTextEdit(layoutWidget);
        bkBarIntroduction->setObjectName(QStringLiteral("bkBarIntroduction"));

        horizontalLayout->addWidget(bkBarIntroduction);

        btnBookBarHide = new QToolButton(tab_A_1);
        btnBookBarHide->setObjectName(QStringLiteral("btnBookBarHide"));
        btnBookBarHide->setGeometry(QRect(1030, 320, 40, 40));
        btnBookBarHide->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 150);"));
        btnBookBarHide->setIconSize(QSize(68, 68));
        btnBookBarHide->setAutoRaise(true);
        btnBookBarHide->setArrowType(Qt::DownArrow);
        listWidgetOfBook = new QListWidget(tab_A_1);
        listWidgetOfBook->setObjectName(QStringLiteral("listWidgetOfBook"));
        listWidgetOfBook->setGeometry(QRect(0, 0, 1094, 673));
        listWidgetOfBook->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        cannotFound = new QFrame(tab_A_1);
        cannotFound->setObjectName(QStringLiteral("cannotFound"));
        cannotFound->setGeometry(QRect(390, 70, 271, 281));
        cannotFound->setAutoFillBackground(false);
        cannotFound->setStyleSheet(QString::fromUtf8("image: url(:/\345\233\272\345\256\232/Resources/\345\233\272\345\256\232/\346\211\276\344\270\215\345\210\260\347\273\223\346\236\234.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        cannotFound->setFrameShape(QFrame::StyledPanel);
        cannotFound->setFrameShadow(QFrame::Raised);
        tabWidgetOfA->addTab(tab_A_1, QString());
        listWidgetOfBook->raise();
        MyBookToolBar->raise();
        btnBookBarHide->raise();
        cannotFound->raise();
        tab_A_2 = new QWidget();
        tab_A_2->setObjectName(QStringLiteral("tab_A_2"));
        tab_A_2->setStyleSheet(QStringLiteral("QLabel{background-color: rgba(255, 255, 255, 0);}"));
        sJiaChooseFile = new QPushButton(tab_A_2);
        sJiaChooseFile->setObjectName(QStringLiteral("sJiaChooseFile"));
        sJiaChooseFile->setGeometry(QRect(770, 86, 121, 41));
        sJiaChooseFile->setStyleSheet(QString::fromUtf8("background-image: url(:/\345\233\272\345\256\232/Resources/\345\233\272\345\256\232/\347\231\273\345\275\225\346\214\211\351\222\256tip.jpg);"));
        sJiaHead = new HeadPor(tab_A_2);
        sJiaHead->setObjectName(QStringLiteral("sJiaHead"));
        sJiaHead->setGeometry(QRect(70, 270, 100, 130));
        sJiaHead->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 127);"));
        sJiaHead->setFrameShape(QFrame::StyledPanel);
        sJiaHead->setFrameShadow(QFrame::Raised);
        sJiaChgeHead = new QPushButton(tab_A_2);
        sJiaChgeHead->setObjectName(QStringLiteral("sJiaChgeHead"));
        sJiaChgeHead->setGeometry(QRect(64, 410, 112, 40));
        sJiaChgeHead->setStyleSheet(QString::fromUtf8("background-image: url(:/\345\233\272\345\256\232/Resources/\345\233\272\345\256\232/\347\231\273\345\275\225\346\214\211\351\222\256tip.jpg);"));
        sJiaOK = new QPushButton(tab_A_2);
        sJiaOK->setObjectName(QStringLiteral("sJiaOK"));
        sJiaOK->setGeometry(QRect(870, 540, 131, 51));
        sJiaOK->setStyleSheet(QString::fromUtf8("background-image: url(:/\345\233\272\345\256\232/Resources/\345\233\272\345\256\232/\347\231\273\345\275\225\346\214\211\351\222\256tip.jpg);"));
        sJiaFilepath = new QLabel(tab_A_2);
        sJiaFilepath->setObjectName(QStringLiteral("sJiaFilepath"));
        sJiaFilepath->setGeometry(QRect(220, 86, 531, 41));
        sJiaFilepath->setStyleSheet(QStringLiteral("background-color: rgba(85, 255, 255, 100);"));
        line_2 = new QFrame(tab_A_2);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(0, 160, 1094, 5));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setLineWidth(3);
        line_2->setFrameShape(QFrame::HLine);
        label_11 = new QLabel(tab_A_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(340, 180, 371, 40));
        label_11->setMinimumSize(QSize(120, 40));
        label_11->setStyleSheet(QLatin1String("background-color: rgba(170, 255, 0, 150);\n"
""));
        label_11->setAlignment(Qt::AlignCenter);
        label_12 = new QLabel(tab_A_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(340, 10, 371, 40));
        label_12->setMinimumSize(QSize(120, 40));
        label_12->setStyleSheet(QStringLiteral("background-color: rgba(170, 255, 0, 150);"));
        label_12->setAlignment(Qt::AlignCenter);
        sJiaIntroduction = new QPlainTextEdit(tab_A_2);
        sJiaIntroduction->setObjectName(QStringLiteral("sJiaIntroduction"));
        sJiaIntroduction->setGeometry(QRect(320, 470, 471, 181));
        sJiaIntroduction->setMinimumSize(QSize(120, 0));
        label_13 = new QLabel(tab_A_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(203, 470, 108, 45));
        label_13->setMinimumSize(QSize(108, 0));
        label_13->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 100);\n"
""));
        label_13->setAlignment(Qt::AlignCenter);
        layoutWidget1 = new QWidget(tab_A_2);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(200, 250, 831, 211));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(108, 0));
        label_3->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 100);\n"
""));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_3);

        sJiaISBN = new QLineEdit(layoutWidget1);
        sJiaISBN->setObjectName(QStringLiteral("sJiaISBN"));

        horizontalLayout_2->addWidget(sJiaISBN);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(108, 0));
        label_4->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 100);\n"
""));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_4);

        sJiaName = new QLineEdit(layoutWidget1);
        sJiaName->setObjectName(QStringLiteral("sJiaName"));

        horizontalLayout_3->addWidget(sJiaName);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(108, 0));
        label_5->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 100);\n"
""));
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_5);

        sJiaAuthor = new QLineEdit(layoutWidget1);
        sJiaAuthor->setObjectName(QStringLiteral("sJiaAuthor"));

        horizontalLayout_4->addWidget(sJiaAuthor);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(108, 0));
        label_6->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 100);\n"
""));
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_6);

        sJiaCategory = new QLineEdit(layoutWidget1);
        sJiaCategory->setObjectName(QStringLiteral("sJiaCategory"));

        horizontalLayout_5->addWidget(sJiaCategory);


        verticalLayout_3->addLayout(horizontalLayout_5);


        horizontalLayout_10->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(108, 0));
        label_8->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 100);\n"
""));
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_8);

        sJiaPubCompany = new QLineEdit(layoutWidget1);
        sJiaPubCompany->setObjectName(QStringLiteral("sJiaPubCompany"));

        horizontalLayout_6->addWidget(sJiaPubCompany);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(108, 0));
        label_7->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 100);\n"
""));
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_7);

        sJiaPubDate = new QLineEdit(layoutWidget1);
        sJiaPubDate->setObjectName(QStringLiteral("sJiaPubDate"));

        horizontalLayout_7->addWidget(sJiaPubDate);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_10 = new QLabel(layoutWidget1);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(108, 0));
        label_10->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 100);\n"
""));
        label_10->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_10);

        sJiaTableNumber = new QLineEdit(layoutWidget1);
        sJiaTableNumber->setObjectName(QStringLiteral("sJiaTableNumber"));

        horizontalLayout_8->addWidget(sJiaTableNumber);


        verticalLayout_4->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(108, 0));
        label_9->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 100);\n"
""));
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_9);

        sJiaStorageRate = new QLineEdit(layoutWidget1);
        sJiaStorageRate->setObjectName(QStringLiteral("sJiaStorageRate"));

        horizontalLayout_9->addWidget(sJiaStorageRate);


        verticalLayout_4->addLayout(horizontalLayout_9);


        horizontalLayout_10->addLayout(verticalLayout_4);

        tabWidgetOfA->addTab(tab_A_2, QString());
        layoutWidget->raise();
        sJiaChooseFile->raise();
        sJiaHead->raise();
        sJiaChgeHead->raise();
        sJiaFilepath->raise();
        line_2->raise();
        label_11->raise();
        sJiaOK->raise();
        label_12->raise();
        sJiaIntroduction->raise();
        label_13->raise();
        tabWidget->addTab(tab_A, QString());
        tab_B = new QWidget();
        tab_B->setObjectName(QStringLiteral("tab_B"));
        tab_B->setLayoutDirection(Qt::LeftToRight);
        tab_B->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"background-color: rgba(255, 255, 255, 100);font: 15pt \"Adobe \351\273\221\344\275\223 Std R\";}\n"
"QPushButton, QLineEdit{font: 15pt \"Adobe \351\273\221\344\275\223 Std R\";}"));
        jYueLIneID = new QLineEdit(tab_B);
        jYueLIneID->setObjectName(QStringLiteral("jYueLIneID"));
        jYueLIneID->setGeometry(QRect(170, 20, 360, 50));
        jYueLineISBN = new QLineEdit(tab_B);
        jYueLineISBN->setObjectName(QStringLiteral("jYueLineISBN"));
        jYueLineISBN->setGeometry(QRect(570, 20, 360, 50));
        jYueOrder = new QComboBox(tab_B);
        jYueOrder->addItem(QString());
        jYueOrder->addItem(QString());
        jYueOrder->addItem(QString());
        jYueOrder->setObjectName(QStringLiteral("jYueOrder"));
        jYueOrder->setGeometry(QRect(31, 25, 110, 40));
        listLeft = new QListWidget(tab_B);
        listLeft->setObjectName(QStringLiteral("listLeft"));
        listLeft->setGeometry(QRect(0, 90, 550, 631));
        listLeft->setStyleSheet(QStringLiteral("background-color: rgb(255, 170, 255, 100);"));
        listRight = new QListWidget(tab_B);
        listRight->setObjectName(QStringLiteral("listRight"));
        listRight->setGeometry(QRect(550, 90, 550, 631));
        listRight->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 255, 100);"));
        jYueButton = new QPushButton(tab_B);
        jYueButton->setObjectName(QStringLiteral("jYueButton"));
        jYueButton->setGeometry(QRect(971, 25, 100, 40));
        jYueButton->setStyleSheet(QString::fromUtf8("background-image: url(:/\345\233\272\345\256\232/Resources/\345\233\272\345\256\232/\347\231\273\345\275\225\346\214\211\351\222\256tip.jpg);"));
        cannotFoundLeft = new QFrame(tab_B);
        cannotFoundLeft->setObjectName(QStringLiteral("cannotFoundLeft"));
        cannotFoundLeft->setGeometry(QRect(120, 230, 271, 281));
        cannotFoundLeft->setAutoFillBackground(false);
        cannotFoundLeft->setStyleSheet(QString::fromUtf8("image: url(:/\345\233\272\345\256\232/Resources/\345\233\272\345\256\232/\346\211\276\344\270\215\345\210\260\347\273\223\346\236\234.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        cannotFoundLeft->setFrameShape(QFrame::StyledPanel);
        cannotFoundLeft->setFrameShadow(QFrame::Raised);
        cannotFoundRight = new QFrame(tab_B);
        cannotFoundRight->setObjectName(QStringLiteral("cannotFoundRight"));
        cannotFoundRight->setGeometry(QRect(690, 220, 271, 281));
        cannotFoundRight->setAutoFillBackground(false);
        cannotFoundRight->setStyleSheet(QString::fromUtf8("image: url(:/\345\233\272\345\256\232/Resources/\345\233\272\345\256\232/\346\211\276\344\270\215\345\210\260\347\273\223\346\236\234.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        cannotFoundRight->setFrameShape(QFrame::StyledPanel);
        cannotFoundRight->setFrameShadow(QFrame::Raised);
        tabWidget->addTab(tab_B, QString());
        jYueLIneID->raise();
        jYueLineISBN->raise();
        jYueOrder->raise();
        listLeft->raise();
        jYueButton->raise();
        listRight->raise();
        cannotFoundLeft->raise();
        cannotFoundRight->raise();
        tab_C = new QWidget();
        tab_C->setObjectName(QStringLiteral("tab_C"));
        userBar = new QFrame(tab_C);
        userBar->setObjectName(QStringLiteral("userBar"));
        userBar->setGeometry(QRect(0, 420, 1091, 300));
        userBar->setStyleSheet(QString::fromUtf8("#userBar{background-color: rgb(170, 255, 255);}\n"
"\n"
"QLineEdit,QComboBox,QPushButton,QLabel{font: 16pt \"Adobe \351\273\221\344\275\223 Std R\";}\n"
"\n"
"QPushButton{background-image: url(:/\345\233\272\345\256\232/Resources/\345\233\272\345\256\232/\347\231\273\345\275\225\346\214\211\351\222\256tip.jpg);}\n"
"\n"
"QComboBox{background-color: rgb(255, 170, 255, 150);}"));
        userBar->setFrameShape(QFrame::StyledPanel);
        userBar->setFrameShadow(QFrame::Raised);
        userBarCBSex = new QComboBox(userBar);
        userBarCBSex->addItem(QString());
        userBarCBSex->addItem(QString());
        userBarCBSex->addItem(QString());
        userBarCBSex->setObjectName(QStringLiteral("userBarCBSex"));
        userBarCBSex->setGeometry(QRect(765, 5, 150, 40));
        userBarCBSort = new QComboBox(userBar);
        userBarCBSort->addItem(QString());
        userBarCBSort->addItem(QString());
        userBarCBSort->setObjectName(QStringLiteral("userBarCBSort"));
        userBarCBSort->setGeometry(QRect(920, 5, 160, 40));
        userBarKey = new QLineEdit(userBar);
        userBarKey->setObjectName(QStringLiteral("userBarKey"));
        userBarKey->setGeometry(QRect(5, 5, 400, 40));
        userBarKey->setFont(font1);
        userBarKey->setStyleSheet(QStringLiteral("background-color:rgba(255, 255, 255, 0)"));
        userBarCBClass = new QComboBox(userBar);
        userBarCBClass->addItem(QString());
        userBarCBClass->setObjectName(QStringLiteral("userBarCBClass"));
        userBarCBClass->setGeometry(QRect(610, 5, 150, 40));
        userBarSearch = new QToolButton(userBar);
        userBarSearch->setObjectName(QStringLiteral("userBarSearch"));
        userBarSearch->setGeometry(QRect(410, 5, 40, 40));
        userBarSearch->setIcon(icon);
        userBarSearch->setIconSize(QSize(68, 68));
        userBarSearch->setAutoRaise(true);
        userBarCBInstitute = new QComboBox(userBar);
        userBarCBInstitute->addItem(QString());
        userBarCBInstitute->setObjectName(QStringLiteral("userBarCBInstitute"));
        userBarCBInstitute->setGeometry(QRect(455, 5, 150, 40));
        userBarHead = new HeadPor(userBar);
        userBarHead->setObjectName(QStringLiteral("userBarHead"));
        userBarHead->setGeometry(QRect(40, 80, 120, 120));
        userBarHead->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 127);"));
        userBarHead->setFrameShape(QFrame::StyledPanel);
        userBarHead->setFrameShadow(QFrame::Raised);
        userBarOK = new QPushButton(userBar);
        userBarOK->setObjectName(QStringLiteral("userBarOK"));
        userBarOK->setGeometry(QRect(920, 220, 111, 40));
        userBarDelete = new QPushButton(userBar);
        userBarDelete->setObjectName(QStringLiteral("userBarDelete"));
        userBarDelete->setGeometry(QRect(920, 170, 111, 40));
        userBarDelete->setStyleSheet(QStringLiteral(""));
        userBarSelectAll = new QPushButton(userBar);
        userBarSelectAll->setObjectName(QStringLiteral("userBarSelectAll"));
        userBarSelectAll->setGeometry(QRect(900, 120, 151, 40));
        userBarResetPW = new QPushButton(userBar);
        userBarResetPW->setObjectName(QStringLiteral("userBarResetPW"));
        userBarResetPW->setGeometry(QRect(900, 70, 151, 40));
        userBarPower = new QLabel(userBar);
        userBarPower->setObjectName(QStringLiteral("userBarPower"));
        userBarPower->setGeometry(QRect(200, 160, 141, 40));
        userBarPower->setAlignment(Qt::AlignCenter);
        userBarID = new QLabel(userBar);
        userBarID->setObjectName(QStringLiteral("userBarID"));
        userBarID->setGeometry(QRect(190, 110, 161, 40));
        userBarID->setAlignment(Qt::AlignCenter);
        layoutWidget2 = new QWidget(userBar);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(390, 70, 461, 191));
        verticalLayout_5 = new QVBoxLayout(layoutWidget2);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_15 = new QLabel(layoutWidget2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setAlignment(Qt::AlignCenter);

        horizontalLayout_11->addWidget(label_15);

        userBarName = new QLineEdit(layoutWidget2);
        userBarName->setObjectName(QStringLiteral("userBarName"));

        horizontalLayout_11->addWidget(userBarName);


        verticalLayout_5->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_16 = new QLabel(layoutWidget2);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setAlignment(Qt::AlignCenter);

        horizontalLayout_12->addWidget(label_16);

        userBarSex = new QLineEdit(layoutWidget2);
        userBarSex->setObjectName(QStringLiteral("userBarSex"));

        horizontalLayout_12->addWidget(userBarSex);


        verticalLayout_5->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_17 = new QLabel(layoutWidget2);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setAlignment(Qt::AlignCenter);

        horizontalLayout_13->addWidget(label_17);

        userBarInstitute = new QLineEdit(layoutWidget2);
        userBarInstitute->setObjectName(QStringLiteral("userBarInstitute"));

        horizontalLayout_13->addWidget(userBarInstitute);


        verticalLayout_5->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_18 = new QLabel(layoutWidget2);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setAlignment(Qt::AlignCenter);

        horizontalLayout_14->addWidget(label_18);

        userBarClass = new QLineEdit(layoutWidget2);
        userBarClass->setObjectName(QStringLiteral("userBarClass"));

        horizontalLayout_14->addWidget(userBarClass);


        verticalLayout_5->addLayout(horizontalLayout_14);

        listUser = new QListWidget(tab_C);
        listUser->setObjectName(QStringLiteral("listUser"));
        listUser->setGeometry(QRect(0, 0, 1091, 721));
        listUser->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255, 100);"));
        userBarHide = new QToolButton(tab_C);
        userBarHide->setObjectName(QStringLiteral("userBarHide"));
        userBarHide->setGeometry(QRect(1030, 380, 40, 40));
        userBarHide->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 200);"));
        userBarHide->setIconSize(QSize(68, 68));
        userBarHide->setAutoRaise(true);
        userBarHide->setArrowType(Qt::DownArrow);
        userCannotFound = new QFrame(tab_C);
        userCannotFound->setObjectName(QStringLiteral("userCannotFound"));
        userCannotFound->setGeometry(QRect(380, 100, 271, 281));
        userCannotFound->setAutoFillBackground(false);
        userCannotFound->setStyleSheet(QString::fromUtf8("image: url(:/\345\233\272\345\256\232/Resources/\345\233\272\345\256\232/\346\211\276\344\270\215\345\210\260\347\273\223\346\236\234.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        userCannotFound->setFrameShape(QFrame::StyledPanel);
        userCannotFound->setFrameShadow(QFrame::Raised);
        tabWidget->addTab(tab_C, QString());
        listUser->raise();
        userBar->raise();
        userBarHide->raise();
        userCannotFound->raise();
        beiJingBan = new QFrame(MgInterface);
        beiJingBan->setObjectName(QStringLiteral("beiJingBan"));
        beiJingBan->setGeometry(QRect(0, 0, 1200, 900));
        beiJingBan->setStyleSheet(QString::fromUtf8("#beiJingBan{\n"
"image: url(:/\347\224\250\346\210\267\347\225\214\351\235\242/Resources/\347\224\250\346\210\267\347\225\214\351\235\242/\347\224\250\346\210\267\344\270\273\350\203\214\346\231\257.jpg);}"));
        beiJingBan->setFrameShape(QFrame::StyledPanel);
        beiJingBan->setFrameShadow(QFrame::Raised);
        btnMessage = new MessageButton(beiJingBan);
        btnMessage->setObjectName(QStringLiteral("btnMessage"));
        btnMessage->setGeometry(QRect(820, 0, 60, 60));
        btnMessage->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/\347\224\250\346\210\267\347\225\214\351\235\242\345\260\217\346\214\211\351\222\256/Resources/\345\260\217\346\214\211\351\222\256/\346\266\210\346\201\257.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnMessage->setIcon(icon1);
        btnMessage->setIconSize(QSize(40, 40));
        btnMessage->setAutoRaise(true);
        btnClose = new QToolButton(beiJingBan);
        btnClose->setObjectName(QStringLiteral("btnClose"));
        btnClose->setGeometry(QRect(1155, 5, 40, 40));
        btnClose->setStyleSheet(QStringLiteral(""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/\347\224\250\346\210\267\347\225\214\351\235\242\345\260\217\346\214\211\351\222\256/Resources/\345\260\217\346\214\211\351\222\256/\345\256\236\345\277\203\345\205\263\351\227\255.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnClose->setIcon(icon2);
        btnClose->setIconSize(QSize(40, 40));
        btnClose->setAutoRaise(true);
        btnMin = new QToolButton(beiJingBan);
        btnMin->setObjectName(QStringLiteral("btnMin"));
        btnMin->setGeometry(QRect(1105, 0, 50, 51));
        btnMin->setStyleSheet(QStringLiteral(""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/\347\224\250\346\210\267\347\225\214\351\235\242\345\260\217\346\214\211\351\222\256/Resources/\345\260\217\346\214\211\351\222\256/\345\256\236\345\277\203\346\234\200\345\260\217\345\214\226.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnMin->setIcon(icon3);
        btnMin->setIconSize(QSize(51, 49));
        btnMin->setAutoRaise(true);
        btnHelp = new QToolButton(beiJingBan);
        btnHelp->setObjectName(QStringLiteral("btnHelp"));
        btnHelp->setGeometry(QRect(1064, 5, 45, 43));
        btnHelp->setStyleSheet(QStringLiteral(""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/\347\224\250\346\210\267\347\225\214\351\235\242\345\260\217\346\214\211\351\222\256/Resources/\345\260\217\346\214\211\351\222\256/\345\256\236\345\277\203\345\270\256\345\212\251.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnHelp->setIcon(icon4);
        btnHelp->setIconSize(QSize(40, 40));
        btnHelp->setAutoRaise(true);
        btnCloth = new QToolButton(beiJingBan);
        btnCloth->setObjectName(QStringLiteral("btnCloth"));
        btnCloth->setGeometry(QRect(1023, 7, 40, 40));
        btnCloth->setStyleSheet(QStringLiteral(""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/\347\224\250\346\210\267\347\225\214\351\235\242\345\260\217\346\214\211\351\222\256/Resources/\345\260\217\346\214\211\351\222\256/\347\232\256\350\202\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCloth->setIcon(icon5);
        btnCloth->setIconSize(QSize(40, 40));
        btnCloth->setAutoRaise(true);
        comboBox = new QComboBox(beiJingBan);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(880, 10, 139, 36));
        comboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"font: 12pt \"Adobe \351\273\221\344\275\223 Std R\";\n"
"color: rgb(255, 255, 255);"));
        frameHead = new HeadPor(beiJingBan);
        frameHead->setObjectName(QStringLiteral("frameHead"));
        frameHead->setGeometry(QRect(30, 30, 100, 100));
        frameHead->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 0);"));
        frameHead->setFrameShape(QFrame::StyledPanel);
        frameHead->setFrameShadow(QFrame::Raised);
        label = new QLabel(beiJingBan);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 80, 251, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font2.setPointSize(16);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setUnderline(false);
        font2.setWeight(50);
        label->setFont(font2);
        label->setStyleSheet(QStringLiteral(""));
        line = new QFrame(beiJingBan);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(167, 113, 169, 16));
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(2);
        line->setFrameShape(QFrame::HLine);
        btnFreshen = new QToolButton(beiJingBan);
        btnFreshen->setObjectName(QStringLiteral("btnFreshen"));
        btnFreshen->setGeometry(QRect(770, 7, 47, 47));
        btnFreshen->setStyleSheet(QStringLiteral(""));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/\347\224\250\346\210\267\347\225\214\351\235\242\345\260\217\346\214\211\351\222\256/Resources/\345\260\217\346\214\211\351\222\256/\345\210\267\346\226\260.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnFreshen->setIcon(icon6);
        btnFreshen->setIconSize(QSize(45, 45));
        btnFreshen->setAutoRaise(true);
        line->raise();
        btnMessage->raise();
        btnClose->raise();
        btnMin->raise();
        btnHelp->raise();
        btnCloth->raise();
        comboBox->raise();
        frameHead->raise();
        label->raise();
        btnFreshen->raise();
        beiJingBan->raise();
        tabWidget->raise();

        retranslateUi(MgInterface);

        tabWidget->setCurrentIndex(1);
        tabWidgetOfA->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MgInterface);
    } // setupUi

    void retranslateUi(QWidget *MgInterface)
    {
        MgInterface->setWindowTitle(QApplication::translate("MgInterface", "MgInterface", nullptr));
        bookBarKey->setText(QString());
        bookBarKey->setPlaceholderText(QApplication::translate("MgInterface", "\350\257\267\350\276\223\345\205\245\346\237\245\350\257\242\345\205\263\351\224\256\345\255\227\346\210\22613\344\275\215ISBN\347\240\201", nullptr));
        bkBarChgeHead->setText(QApplication::translate("MgInterface", "\346\233\264\346\215\242\345\233\276\347\211\207", nullptr));
        bookBarSearch->setText(QApplication::translate("MgInterface", "...", nullptr));
        cmbType->setItemText(0, QApplication::translate("MgInterface", "\344\270\215\351\231\220\345\210\266\345\210\206\347\261\273", nullptr));

        cmbPublish->setItemText(0, QApplication::translate("MgInterface", "\344\270\215\351\231\220\345\210\266\345\207\272\347\211\210\347\244\276", nullptr));

        cmbAuthor->setItemText(0, QApplication::translate("MgInterface", "\344\270\215\351\231\220\345\210\266\344\275\234\350\200\205", nullptr));

        cmbKuCun->setItemText(0, QApplication::translate("MgInterface", "\345\272\223\345\255\230(\351\273\230\350\256\244\346\216\222\345\272\217)", nullptr));
        cmbKuCun->setItemText(1, QApplication::translate("MgInterface", "\345\272\223\345\255\230\351\231\215\345\272\217", nullptr));
        cmbKuCun->setItemText(2, QApplication::translate("MgInterface", "\345\272\223\345\255\230\345\215\207\345\272\217", nullptr));

        cmbDate->setItemText(0, QApplication::translate("MgInterface", "\346\227\245\346\234\237(\351\273\230\350\256\244\346\216\222\345\272\217)", nullptr));
        cmbDate->setItemText(1, QApplication::translate("MgInterface", "\346\227\245\346\234\237\351\231\215\345\272\217", nullptr));
        cmbDate->setItemText(2, QApplication::translate("MgInterface", "\346\227\245\346\234\237\345\215\207\345\272\217", nullptr));

        bkBarAlter->setText(QApplication::translate("MgInterface", "\344\277\256\346\224\271", nullptr));
        bkBarDelete->setText(QApplication::translate("MgInterface", "\344\270\213\346\236\266", nullptr));
        bookBarSelect->setText(QApplication::translate("MgInterface", "\345\205\250\351\200\211/\345\205\250\344\270\215\351\200\211", nullptr));
#ifndef QT_NO_TOOLTIP
        bkBarISBN->setToolTip(QApplication::translate("MgInterface", "ISBN", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        bkBarISBN->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        bkBarISBN->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        bkBarISBN->setText(QString());
        bkBarISBN->setPlaceholderText(QApplication::translate("MgInterface", "ISBN", nullptr));
#ifndef QT_NO_TOOLTIP
        bkBarName->setToolTip(QApplication::translate("MgInterface", "\344\271\246\345\220\215", nullptr));
#endif // QT_NO_TOOLTIP
        bkBarName->setText(QString());
        bkBarName->setPlaceholderText(QApplication::translate("MgInterface", "\344\271\246\345\220\215", nullptr));
#ifndef QT_NO_TOOLTIP
        bkBarAuthor->setToolTip(QApplication::translate("MgInterface", "\344\275\234\350\200\205", nullptr));
#endif // QT_NO_TOOLTIP
        bkBarAuthor->setText(QString());
        bkBarAuthor->setPlaceholderText(QApplication::translate("MgInterface", "\344\275\234\350\200\205", nullptr));
#ifndef QT_NO_TOOLTIP
        bookBarcategory->setToolTip(QApplication::translate("MgInterface", "\345\210\206\347\261\273", nullptr));
#endif // QT_NO_TOOLTIP
        bookBarcategory->setText(QString());
        bookBarcategory->setPlaceholderText(QApplication::translate("MgInterface", "\345\210\206\347\261\273", nullptr));
#ifndef QT_NO_TOOLTIP
        bkBarPubCompany->setToolTip(QApplication::translate("MgInterface", "\345\207\272\347\211\210\347\244\276", nullptr));
#endif // QT_NO_TOOLTIP
        bkBarPubCompany->setText(QString());
        bkBarPubCompany->setPlaceholderText(QApplication::translate("MgInterface", "\345\207\272\347\211\210\347\244\276", nullptr));
#ifndef QT_NO_TOOLTIP
        bkBarPubDate->setToolTip(QApplication::translate("MgInterface", "\345\207\272\347\211\210\346\227\245\346\234\237", nullptr));
#endif // QT_NO_TOOLTIP
        bkBarPubDate->setText(QString());
        bkBarPubDate->setPlaceholderText(QApplication::translate("MgInterface", "\345\207\272\347\211\210\346\227\245\346\234\237", nullptr));
#ifndef QT_NO_TOOLTIP
        bkBarTableNumber->setToolTip(QApplication::translate("MgInterface", "\347\264\242\344\271\246\345\217\267", nullptr));
#endif // QT_NO_TOOLTIP
        bkBarTableNumber->setText(QString());
        bkBarTableNumber->setPlaceholderText(QApplication::translate("MgInterface", "\347\264\242\344\271\246\345\217\267", nullptr));
#ifndef QT_NO_TOOLTIP
        bkBarStorageRate->setToolTip(QApplication::translate("MgInterface", "\345\272\223\345\255\230\345\256\271\351\207\217", nullptr));
#endif // QT_NO_TOOLTIP
        bkBarStorageRate->setText(QString());
        bkBarStorageRate->setPlaceholderText(QApplication::translate("MgInterface", "\345\272\223\345\255\230\345\256\271\351\207\217", nullptr));
#ifndef QT_NO_TOOLTIP
        bkBarIntroduction->setToolTip(QApplication::translate("MgInterface", "\347\256\200\344\273\213", nullptr));
#endif // QT_NO_TOOLTIP
        bkBarIntroduction->setPlainText(QString());
        bkBarIntroduction->setPlaceholderText(QString());
        btnBookBarHide->setText(QApplication::translate("MgInterface", "...", nullptr));
        tabWidgetOfA->setTabText(tabWidgetOfA->indexOf(tab_A_1), QApplication::translate("MgInterface", "\344\277\256\346\224\271/\344\270\213\346\236\266", nullptr));
        sJiaChooseFile->setText(QApplication::translate("MgInterface", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        sJiaChgeHead->setText(QApplication::translate("MgInterface", "\346\233\264\346\215\242\345\233\276\347\211\207", nullptr));
        sJiaOK->setText(QApplication::translate("MgInterface", "\347\241\256  \350\256\244", nullptr));
        sJiaFilepath->setText(QApplication::translate("MgInterface", "\346\234\252\351\200\211\346\213\251\346\234\211\346\225\210\346\226\207\344\273\266!!!", nullptr));
        label_11->setText(QApplication::translate("MgInterface", "\346\211\271   \351\207\217   \345\257\274   \345\205\245", nullptr));
        label_12->setText(QApplication::translate("MgInterface", "\345\215\225   \346\234\254   \345\275\225   \345\205\245", nullptr));
        sJiaIntroduction->setPlainText(QString());
        label_13->setText(QApplication::translate("MgInterface", "\347\256\200\344\273\213", nullptr));
        label_3->setText(QApplication::translate("MgInterface", "ISBN", nullptr));
        sJiaISBN->setText(QString());
        label_4->setText(QApplication::translate("MgInterface", "\344\271\246\345\220\215", nullptr));
        sJiaName->setText(QString());
        label_5->setText(QApplication::translate("MgInterface", "\344\275\234\350\200\205", nullptr));
        sJiaAuthor->setText(QString());
        label_6->setText(QApplication::translate("MgInterface", "\345\210\206\347\261\273", nullptr));
        sJiaCategory->setText(QString());
        label_8->setText(QApplication::translate("MgInterface", "\345\207\272\347\211\210\347\244\276", nullptr));
        sJiaPubCompany->setText(QString());
        label_7->setText(QApplication::translate("MgInterface", "\345\207\272\347\211\210\346\227\245\346\234\237", nullptr));
        sJiaPubDate->setText(QString());
        label_10->setText(QApplication::translate("MgInterface", "\347\264\242\344\271\246\345\217\267", nullptr));
        sJiaTableNumber->setText(QString());
        label_9->setText(QApplication::translate("MgInterface", "\345\272\223\345\255\230\345\256\271\351\207\217", nullptr));
        sJiaStorageRate->setText(QString());
        tabWidgetOfA->setTabText(tabWidgetOfA->indexOf(tab_A_2), QApplication::translate("MgInterface", "\344\270\212\346\236\266", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_A), QApplication::translate("MgInterface", "\345\233\276\344\271\246\347\256\241\347\220\206", nullptr));
        jYueLIneID->setPlaceholderText(QApplication::translate("MgInterface", "\350\276\223\345\205\245\345\247\223\345\220\215\345\205\263\351\224\256\345\255\227\346\210\22610\344\275\215\345\255\246\345\217\267", nullptr));
        jYueLineISBN->setPlaceholderText(QApplication::translate("MgInterface", "\350\276\223\345\205\245\344\271\246\345\220\215\345\205\263\351\224\256\345\255\227\346\210\22617\344\275\215ISBN\347\240\201", nullptr));
        jYueOrder->setItemText(0, QApplication::translate("MgInterface", "\345\200\237\351\230\205", nullptr));
        jYueOrder->setItemText(1, QApplication::translate("MgInterface", "\346\237\245\350\257\242", nullptr));
        jYueOrder->setItemText(2, QApplication::translate("MgInterface", "\351\200\200\350\277\230", nullptr));

        jYueButton->setText(QApplication::translate("MgInterface", "\347\241\256\345\256\232", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_B), QApplication::translate("MgInterface", "\345\200\237\351\230\205\347\256\241\347\220\206", nullptr));
        userBarCBSex->setItemText(0, QApplication::translate("MgInterface", "\344\270\215\351\231\220\346\200\247\345\210\253", nullptr));
        userBarCBSex->setItemText(1, QApplication::translate("MgInterface", "\347\224\267", nullptr));
        userBarCBSex->setItemText(2, QApplication::translate("MgInterface", "\345\245\263", nullptr));

        userBarCBSort->setItemText(0, QApplication::translate("MgInterface", "\345\255\246\345\217\267\345\215\207\345\272\217", nullptr));
        userBarCBSort->setItemText(1, QApplication::translate("MgInterface", "\345\255\246\345\217\267\351\231\215\345\272\217", nullptr));

        userBarKey->setText(QString());
        userBarKey->setPlaceholderText(QApplication::translate("MgInterface", "\350\257\267\350\276\223\345\205\245\345\247\223\345\220\215\345\205\263\351\224\256\345\255\227\346\210\22610\344\275\215\345\255\246\345\217\267", nullptr));
        userBarCBClass->setItemText(0, QApplication::translate("MgInterface", "\344\270\215\351\231\220\347\217\255\347\272\247", nullptr));

        userBarSearch->setText(QApplication::translate("MgInterface", "...", nullptr));
        userBarCBInstitute->setItemText(0, QApplication::translate("MgInterface", "\344\270\215\351\231\220\345\255\246\351\231\242", nullptr));

        userBarOK->setText(QApplication::translate("MgInterface", "\347\241\256\350\256\244", nullptr));
        userBarDelete->setText(QApplication::translate("MgInterface", "\345\210\240\351\231\244", nullptr));
        userBarSelectAll->setText(QApplication::translate("MgInterface", "\345\205\250\351\200\211/\345\205\250\344\270\215\351\200\211", nullptr));
        userBarResetPW->setText(QApplication::translate("MgInterface", "\351\207\215\347\275\256\345\257\206\347\240\201", nullptr));
        userBarPower->setText(QString());
        userBarID->setText(QString());
        label_15->setText(QApplication::translate("MgInterface", "\345\247\223\345\220\215", nullptr));
        userBarName->setText(QString());
        label_16->setText(QApplication::translate("MgInterface", "\346\200\247\345\210\253", nullptr));
        userBarSex->setText(QString());
        label_17->setText(QApplication::translate("MgInterface", "\345\255\246\351\231\242", nullptr));
        userBarInstitute->setText(QString());
        label_18->setText(QApplication::translate("MgInterface", "\347\217\255\347\272\247", nullptr));
        userBarClass->setText(QString());
        userBarHide->setText(QApplication::translate("MgInterface", "...", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_C), QApplication::translate("MgInterface", "\347\224\250\346\210\267\347\256\241\347\220\206", nullptr));
        btnMessage->setText(QApplication::translate("MgInterface", "\346\234\200\345\260\217\345\214\226", nullptr));
        btnClose->setText(QApplication::translate("MgInterface", "\346\234\200\345\260\217\345\214\226", nullptr));
        btnMin->setText(QApplication::translate("MgInterface", "\346\234\200\345\260\217\345\214\226", nullptr));
        btnHelp->setText(QApplication::translate("MgInterface", "\346\234\200\345\260\217\345\214\226", nullptr));
        btnCloth->setText(QApplication::translate("MgInterface", "\346\234\200\345\260\217\345\214\226", nullptr));
        comboBox->setItemText(0, QApplication::translate("MgInterface", "1704040212", nullptr));
        comboBox->setItemText(1, QApplication::translate("MgInterface", "\346\210\221\347\232\204\344\277\241\346\201\257", nullptr));
        comboBox->setItemText(2, QApplication::translate("MgInterface", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        comboBox->setItemText(3, QApplication::translate("MgInterface", "\346\263\250\351\224\200\347\231\273\345\275\225", nullptr));
        comboBox->setItemText(4, QApplication::translate("MgInterface", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));

        label->setText(QApplication::translate("MgInterface", "\344\275\240\345\245\275\357\274\214\351\237\251\345\271\277\351\230\263", nullptr));
        btnFreshen->setText(QApplication::translate("MgInterface", "\346\234\200\345\260\217\345\214\226", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MgInterface: public Ui_MgInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MGINTERFACE_H
