/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUI
{
public:
    QWidget *centralWidget;
    QPushButton *stop_simulation;
    QLabel *mymap;
    QPushButton *start_simulation;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QLCDNumber *lcdNumber;
    QLabel *label;
    QLCDNumber *lcdNumber_2;
    QLabel *label_2;
    QLabel *myicon;
    QComboBox *get_choice;
    QLabel *label_8;
    QTextEdit *textEdit_3;
    QTextEdit *textEdit;
    QLabel *solution;
    QLabel *label_4;
    QTextEdit *textEdit_2;
    QLabel *label_5;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_7;
    QComboBox *get_day;
    QLabel *label_6;
    QComboBox *get_hour;
    QLabel *label_7;
    QPushButton *get_user_state;
    QPushButton *get_path;
    QLabel *time;
    QSpinBox *get_max_time;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QPushButton *add_traveller;
    QComboBox *choose_traveller;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QLabel *choice;
    QRadioButton *get_strategy;
    QRadioButton *get_strategy_2;
    QRadioButton *unchecked;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *ori;
    QComboBox *get_origin;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *des;
    QComboBox *get_destination;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GUI)
    {
        if (GUI->objectName().isEmpty())
            GUI->setObjectName(QStringLiteral("GUI"));
        GUI->resize(1309, 859);
        centralWidget = new QWidget(GUI);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stop_simulation = new QPushButton(centralWidget);
        stop_simulation->setObjectName(QStringLiteral("stop_simulation"));
        stop_simulation->setGeometry(QRect(530, 17, 121, 41));
        mymap = new QLabel(centralWidget);
        mymap->setObjectName(QStringLiteral("mymap"));
        mymap->setGeometry(QRect(310, 77, 971, 641));
        start_simulation = new QPushButton(centralWidget);
        start_simulation->setObjectName(QStringLiteral("start_simulation"));
        start_simulation->setGeometry(QRect(390, 17, 121, 41));
        layoutWidget_2 = new QWidget(centralWidget);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(720, 17, 261, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lcdNumber = new QLCDNumber(layoutWidget_2);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));

        horizontalLayout->addWidget(lcdNumber);

        label = new QLabel(layoutWidget_2);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lcdNumber_2 = new QLCDNumber(layoutWidget_2);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));

        horizontalLayout->addWidget(lcdNumber_2);

        label_2 = new QLabel(layoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        myicon = new QLabel(centralWidget);
        myicon->setObjectName(QStringLiteral("myicon"));
        myicon->setGeometry(QRect(1290, 0, 20, 20));
        get_choice = new QComboBox(centralWidget);
        get_choice->setObjectName(QStringLiteral("get_choice"));
        get_choice->setGeometry(QRect(190, 360, 69, 20));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 360, 161, 16));
        textEdit_3 = new QTextEdit(centralWidget);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        textEdit_3->setGeometry(QRect(10, 660, 251, 71));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 200, 256, 151));
        solution = new QLabel(centralWidget);
        solution->setObjectName(QStringLiteral("solution"));
        solution->setGeometry(QRect(10, 170, 241, 31));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 390, 91, 16));
        textEdit_2 = new QTextEdit(centralWidget);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(10, 410, 256, 171));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(11, 600, 201, 16));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 630, 201, 25));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        get_day = new QComboBox(layoutWidget);
        get_day->setObjectName(QStringLiteral("get_day"));

        horizontalLayout_7->addWidget(get_day);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_7->addWidget(label_6);

        get_hour = new QComboBox(layoutWidget);
        get_hour->setObjectName(QStringLiteral("get_hour"));

        horizontalLayout_7->addWidget(get_hour);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_7->addWidget(label_7);

        get_user_state = new QPushButton(layoutWidget);
        get_user_state->setObjectName(QStringLiteral("get_user_state"));

        horizontalLayout_7->addWidget(get_user_state);

        get_path = new QPushButton(centralWidget);
        get_path->setObjectName(QStringLiteral("get_path"));
        get_path->setGeometry(QRect(159, 127, 111, 23));
        time = new QLabel(centralWidget);
        time->setObjectName(QStringLiteral("time"));
        time->setGeometry(QRect(206, 100, 91, 16));
        get_max_time = new QSpinBox(centralWidget);
        get_max_time->setObjectName(QStringLiteral("get_max_time"));
        get_max_time->setGeometry(QRect(160, 100, 40, 20));
        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 88, 51));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        add_traveller = new QPushButton(layoutWidget1);
        add_traveller->setObjectName(QStringLiteral("add_traveller"));

        verticalLayout->addWidget(add_traveller);

        choose_traveller = new QComboBox(layoutWidget1);
        choose_traveller->setObjectName(QStringLiteral("choose_traveller"));

        verticalLayout->addWidget(choose_traveller);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 70, 109, 80));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        choice = new QLabel(layoutWidget2);
        choice->setObjectName(QStringLiteral("choice"));

        verticalLayout_2->addWidget(choice);

        get_strategy = new QRadioButton(layoutWidget2);
        get_strategy->setObjectName(QStringLiteral("get_strategy"));

        verticalLayout_2->addWidget(get_strategy);

        get_strategy_2 = new QRadioButton(layoutWidget2);
        get_strategy_2->setObjectName(QStringLiteral("get_strategy_2"));

        verticalLayout_2->addWidget(get_strategy_2);

        unchecked = new QRadioButton(layoutWidget2);
        unchecked->setObjectName(QStringLiteral("unchecked"));

        verticalLayout_2->addWidget(unchecked);

        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(130, 10, 131, 22));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        ori = new QLabel(layoutWidget3);
        ori->setObjectName(QStringLiteral("ori"));

        horizontalLayout_2->addWidget(ori);

        get_origin = new QComboBox(layoutWidget3);
        get_origin->setObjectName(QStringLiteral("get_origin"));

        horizontalLayout_2->addWidget(get_origin);

        layoutWidget4 = new QWidget(centralWidget);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(130, 37, 131, 22));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        des = new QLabel(layoutWidget4);
        des->setObjectName(QStringLiteral("des"));

        horizontalLayout_3->addWidget(des);

        get_destination = new QComboBox(layoutWidget4);
        get_destination->setObjectName(QStringLiteral("get_destination"));

        horizontalLayout_3->addWidget(get_destination);

        GUI->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GUI);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1309, 23));
        GUI->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GUI);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        GUI->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GUI);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GUI->setStatusBar(statusBar);

        retranslateUi(GUI);

        QMetaObject::connectSlotsByName(GUI);
    } // setupUi

    void retranslateUi(QMainWindow *GUI)
    {
        GUI->setWindowTitle(QApplication::translate("GUI", "GUI", Q_NULLPTR));
        stop_simulation->setText(QApplication::translate("GUI", "\347\273\223\346\235\237\346\250\241\346\213\237", Q_NULLPTR));
        mymap->setText(QApplication::translate("GUI", "map", Q_NULLPTR));
        start_simulation->setText(QApplication::translate("GUI", "\345\274\200\345\247\213\346\250\241\346\213\237", Q_NULLPTR));
        label_3->setText(QApplication::translate("GUI", "\345\275\223\345\211\215\346\227\266\351\227\264", Q_NULLPTR));
        label->setText(QApplication::translate("GUI", "\345\244\251", Q_NULLPTR));
        label_2->setText(QApplication::translate("GUI", "\346\227\266", Q_NULLPTR));
        myicon->setText(QApplication::translate("GUI", "TextLabel", Q_NULLPTR));
        label_8->setText(QApplication::translate("GUI", "\350\257\267\351\200\211\346\213\251\344\270\200\344\270\252\350\247\243\345\206\263\346\226\271\346\241\210", Q_NULLPTR));
        solution->setText(QApplication::translate("GUI", "\350\247\243\345\206\263\346\226\271\346\241\210", Q_NULLPTR));
        label_4->setText(QApplication::translate("GUI", "\346\227\205\350\241\214\347\212\266\346\200\201", Q_NULLPTR));
        label_5->setText(QApplication::translate("GUI", "\346\237\245\350\257\242\346\227\205\345\256\242\346\227\205\350\241\214\344\277\241\346\201\257", Q_NULLPTR));
        get_day->clear();
        get_day->insertItems(0, QStringList()
         << QApplication::translate("GUI", "0", Q_NULLPTR)
         << QApplication::translate("GUI", "1", Q_NULLPTR)
         << QApplication::translate("GUI", "2", Q_NULLPTR)
         << QApplication::translate("GUI", "3", Q_NULLPTR)
         << QApplication::translate("GUI", "4", Q_NULLPTR)
         << QApplication::translate("GUI", "5", Q_NULLPTR)
         << QApplication::translate("GUI", "6", Q_NULLPTR)
         << QApplication::translate("GUI", "7", Q_NULLPTR)
         << QApplication::translate("GUI", "8", Q_NULLPTR)
         << QApplication::translate("GUI", "9", Q_NULLPTR)
         << QApplication::translate("GUI", "10", Q_NULLPTR)
         << QApplication::translate("GUI", "11", Q_NULLPTR)
         << QApplication::translate("GUI", "12", Q_NULLPTR)
         << QApplication::translate("GUI", "13", Q_NULLPTR)
         << QApplication::translate("GUI", "14", Q_NULLPTR)
         << QApplication::translate("GUI", "15", Q_NULLPTR)
         << QApplication::translate("GUI", "16", Q_NULLPTR)
         << QApplication::translate("GUI", "17", Q_NULLPTR)
         << QApplication::translate("GUI", "18", Q_NULLPTR)
         << QApplication::translate("GUI", "19", Q_NULLPTR)
         << QApplication::translate("GUI", "20", Q_NULLPTR)
         << QApplication::translate("GUI", "21", Q_NULLPTR)
         << QApplication::translate("GUI", "22", Q_NULLPTR)
         << QApplication::translate("GUI", "23", Q_NULLPTR)
        );
        label_6->setText(QApplication::translate("GUI", "\345\244\251", Q_NULLPTR));
        get_hour->clear();
        get_hour->insertItems(0, QStringList()
         << QApplication::translate("GUI", "0", Q_NULLPTR)
         << QApplication::translate("GUI", "1", Q_NULLPTR)
         << QApplication::translate("GUI", "2", Q_NULLPTR)
         << QApplication::translate("GUI", "3", Q_NULLPTR)
         << QApplication::translate("GUI", "4", Q_NULLPTR)
         << QApplication::translate("GUI", "5", Q_NULLPTR)
         << QApplication::translate("GUI", "6", Q_NULLPTR)
         << QApplication::translate("GUI", "7", Q_NULLPTR)
         << QApplication::translate("GUI", "8", Q_NULLPTR)
         << QApplication::translate("GUI", "9", Q_NULLPTR)
         << QApplication::translate("GUI", "10", Q_NULLPTR)
         << QApplication::translate("GUI", "11", Q_NULLPTR)
         << QApplication::translate("GUI", "12", Q_NULLPTR)
         << QApplication::translate("GUI", "13", Q_NULLPTR)
         << QApplication::translate("GUI", "14", Q_NULLPTR)
         << QApplication::translate("GUI", "15", Q_NULLPTR)
         << QApplication::translate("GUI", "16", Q_NULLPTR)
         << QApplication::translate("GUI", "17", Q_NULLPTR)
         << QApplication::translate("GUI", "18", Q_NULLPTR)
         << QApplication::translate("GUI", "19", Q_NULLPTR)
         << QApplication::translate("GUI", "20", Q_NULLPTR)
         << QApplication::translate("GUI", "21", Q_NULLPTR)
         << QApplication::translate("GUI", "22", Q_NULLPTR)
         << QApplication::translate("GUI", "23", Q_NULLPTR)
        );
        label_7->setText(QApplication::translate("GUI", "\346\227\266", Q_NULLPTR));
        get_user_state->setText(QApplication::translate("GUI", "\346\237\245\350\257\242", Q_NULLPTR));
        get_path->setText(QApplication::translate("GUI", "\345\274\200\345\247\213\346\237\245\350\257\242\350\267\257\347\272\277", Q_NULLPTR));
        time->setText(QApplication::translate("GUI", "\345\260\217\346\227\266\345\206\205\345\210\260\350\276\276", Q_NULLPTR));
        add_traveller->setText(QApplication::translate("GUI", "\346\267\273\345\212\240\346\227\205\345\256\242", Q_NULLPTR));
        choose_traveller->clear();
        choose_traveller->insertItems(0, QStringList()
         << QApplication::translate("GUI", "\350\257\267\351\200\211\346\213\251\346\227\205\345\256\242", Q_NULLPTR)
        );
        choose_traveller->setCurrentText(QApplication::translate("GUI", "\350\257\267\351\200\211\346\213\251\346\227\205\345\256\242", Q_NULLPTR));
        choice->setText(QApplication::translate("GUI", "\346\227\205\350\241\214\347\255\226\347\225\245", Q_NULLPTR));
        get_strategy->setText(QApplication::translate("GUI", "\344\270\215\351\231\220\346\227\266\346\234\200\345\260\217\351\243\216\351\231\251", Q_NULLPTR));
        get_strategy_2->setText(QApplication::translate("GUI", "\351\231\220\346\227\266\346\234\200\345\260\217\351\243\216\351\231\251", Q_NULLPTR));
        unchecked->setText(QApplication::translate("GUI", "unchecked", Q_NULLPTR));
        ori->setText(QApplication::translate("GUI", "\345\207\272\345\217\221\345\234\260", Q_NULLPTR));
        get_origin->clear();
        get_origin->insertItems(0, QStringList()
         << QApplication::translate("GUI", "\350\257\267\351\200\211\346\213\251", Q_NULLPTR)
         << QApplication::translate("GUI", "\345\214\227\344\272\254", Q_NULLPTR)
         << QApplication::translate("GUI", "\344\270\212\346\265\267", Q_NULLPTR)
         << QApplication::translate("GUI", "\346\255\246\346\261\211", Q_NULLPTR)
         << QApplication::translate("GUI", "\345\223\210\345\260\224\346\273\250", Q_NULLPTR)
         << QApplication::translate("GUI", "\346\210\220\351\203\275", Q_NULLPTR)
         << QApplication::translate("GUI", "\345\271\277\345\267\236", Q_NULLPTR)
         << QApplication::translate("GUI", "\350\245\277\345\256\211", Q_NULLPTR)
         << QApplication::translate("GUI", "\344\271\214\351\262\201\346\234\250\351\275\220", Q_NULLPTR)
         << QApplication::translate("GUI", "\346\213\211\350\220\250", Q_NULLPTR)
         << QApplication::translate("GUI", "\346\265\267\345\217\243", Q_NULLPTR)
        );
        des->setText(QApplication::translate("GUI", "\347\233\256\347\232\204\345\234\260", Q_NULLPTR));
        get_destination->clear();
        get_destination->insertItems(0, QStringList()
         << QApplication::translate("GUI", "\350\257\267\351\200\211\346\213\251", Q_NULLPTR)
         << QApplication::translate("GUI", "\345\214\227\344\272\254", Q_NULLPTR)
         << QApplication::translate("GUI", "\344\270\212\346\265\267", Q_NULLPTR)
         << QApplication::translate("GUI", "\346\255\246\346\261\211", Q_NULLPTR)
         << QApplication::translate("GUI", "\345\223\210\345\260\224\346\273\250", Q_NULLPTR)
         << QApplication::translate("GUI", "\346\210\220\351\203\275", Q_NULLPTR)
         << QApplication::translate("GUI", "\345\271\277\345\267\236", Q_NULLPTR)
         << QApplication::translate("GUI", "\350\245\277\345\256\211", Q_NULLPTR)
         << QApplication::translate("GUI", "\344\271\214\351\262\201\346\234\250\351\275\220", Q_NULLPTR)
         << QApplication::translate("GUI", "\346\213\211\350\220\250", Q_NULLPTR)
         << QApplication::translate("GUI", "\346\265\267\345\217\243", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class GUI: public Ui_GUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
