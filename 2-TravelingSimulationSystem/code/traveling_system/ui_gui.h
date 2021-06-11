/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
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
            GUI->setObjectName(QString::fromUtf8("GUI"));
        GUI->resize(1309, 859);
        centralWidget = new QWidget(GUI);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        stop_simulation = new QPushButton(centralWidget);
        stop_simulation->setObjectName(QString::fromUtf8("stop_simulation"));
        stop_simulation->setGeometry(QRect(530, 17, 121, 41));
        mymap = new QLabel(centralWidget);
        mymap->setObjectName(QString::fromUtf8("mymap"));
        mymap->setGeometry(QRect(310, 77, 971, 641));
        start_simulation = new QPushButton(centralWidget);
        start_simulation->setObjectName(QString::fromUtf8("start_simulation"));
        start_simulation->setGeometry(QRect(390, 17, 121, 41));
        layoutWidget_2 = new QWidget(centralWidget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(720, 17, 261, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lcdNumber = new QLCDNumber(layoutWidget_2);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));

        horizontalLayout->addWidget(lcdNumber);

        label = new QLabel(layoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lcdNumber_2 = new QLCDNumber(layoutWidget_2);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));

        horizontalLayout->addWidget(lcdNumber_2);

        label_2 = new QLabel(layoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        myicon = new QLabel(centralWidget);
        myicon->setObjectName(QString::fromUtf8("myicon"));
        myicon->setGeometry(QRect(1290, 0, 20, 20));
        get_choice = new QComboBox(centralWidget);
        get_choice->setObjectName(QString::fromUtf8("get_choice"));
        get_choice->setGeometry(QRect(190, 360, 69, 20));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 360, 161, 16));
        textEdit_3 = new QTextEdit(centralWidget);
        textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));
        textEdit_3->setGeometry(QRect(10, 660, 251, 71));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 200, 256, 151));
        solution = new QLabel(centralWidget);
        solution->setObjectName(QString::fromUtf8("solution"));
        solution->setGeometry(QRect(10, 170, 241, 31));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 390, 91, 16));
        textEdit_2 = new QTextEdit(centralWidget);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(10, 410, 256, 171));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(11, 600, 201, 16));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 630, 201, 25));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        get_day = new QComboBox(layoutWidget);
        get_day->addItem(QString());
        get_day->addItem(QString());
        get_day->addItem(QString());
        get_day->addItem(QString());
        get_day->addItem(QString());
        get_day->addItem(QString());
        get_day->addItem(QString());
        get_day->addItem(QString());
        get_day->addItem(QString());
        get_day->addItem(QString());
        get_day->addItem(QString());
        get_day->addItem(QString());
        get_day->addItem(QString());
        get_day->addItem(QString());
        get_day->addItem(QString());
        get_day->addItem(QString());
        get_day->addItem(QString());
        get_day->addItem(QString());
        get_day->addItem(QString());
        get_day->addItem(QString());
        get_day->addItem(QString());
        get_day->addItem(QString());
        get_day->addItem(QString());
        get_day->addItem(QString());
        get_day->setObjectName(QString::fromUtf8("get_day"));

        horizontalLayout_7->addWidget(get_day);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_7->addWidget(label_6);

        get_hour = new QComboBox(layoutWidget);
        get_hour->addItem(QString());
        get_hour->addItem(QString());
        get_hour->addItem(QString());
        get_hour->addItem(QString());
        get_hour->addItem(QString());
        get_hour->addItem(QString());
        get_hour->addItem(QString());
        get_hour->addItem(QString());
        get_hour->addItem(QString());
        get_hour->addItem(QString());
        get_hour->addItem(QString());
        get_hour->addItem(QString());
        get_hour->addItem(QString());
        get_hour->addItem(QString());
        get_hour->addItem(QString());
        get_hour->addItem(QString());
        get_hour->addItem(QString());
        get_hour->addItem(QString());
        get_hour->addItem(QString());
        get_hour->addItem(QString());
        get_hour->addItem(QString());
        get_hour->addItem(QString());
        get_hour->addItem(QString());
        get_hour->addItem(QString());
        get_hour->setObjectName(QString::fromUtf8("get_hour"));

        horizontalLayout_7->addWidget(get_hour);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_7->addWidget(label_7);

        get_user_state = new QPushButton(layoutWidget);
        get_user_state->setObjectName(QString::fromUtf8("get_user_state"));

        horizontalLayout_7->addWidget(get_user_state);

        get_path = new QPushButton(centralWidget);
        get_path->setObjectName(QString::fromUtf8("get_path"));
        get_path->setGeometry(QRect(159, 127, 111, 23));
        time = new QLabel(centralWidget);
        time->setObjectName(QString::fromUtf8("time"));
        time->setGeometry(QRect(206, 100, 91, 16));
        get_max_time = new QSpinBox(centralWidget);
        get_max_time->setObjectName(QString::fromUtf8("get_max_time"));
        get_max_time->setGeometry(QRect(160, 100, 40, 20));
        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 88, 51));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        add_traveller = new QPushButton(layoutWidget1);
        add_traveller->setObjectName(QString::fromUtf8("add_traveller"));

        verticalLayout->addWidget(add_traveller);

        choose_traveller = new QComboBox(layoutWidget1);
        choose_traveller->addItem(QString());
        choose_traveller->setObjectName(QString::fromUtf8("choose_traveller"));

        verticalLayout->addWidget(choose_traveller);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 70, 109, 80));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        choice = new QLabel(layoutWidget2);
        choice->setObjectName(QString::fromUtf8("choice"));

        verticalLayout_2->addWidget(choice);

        get_strategy = new QRadioButton(layoutWidget2);
        get_strategy->setObjectName(QString::fromUtf8("get_strategy"));

        verticalLayout_2->addWidget(get_strategy);

        get_strategy_2 = new QRadioButton(layoutWidget2);
        get_strategy_2->setObjectName(QString::fromUtf8("get_strategy_2"));

        verticalLayout_2->addWidget(get_strategy_2);

        unchecked = new QRadioButton(layoutWidget2);
        unchecked->setObjectName(QString::fromUtf8("unchecked"));

        verticalLayout_2->addWidget(unchecked);

        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(130, 10, 131, 22));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        ori = new QLabel(layoutWidget3);
        ori->setObjectName(QString::fromUtf8("ori"));

        horizontalLayout_2->addWidget(ori);

        get_origin = new QComboBox(layoutWidget3);
        get_origin->addItem(QString());
        get_origin->addItem(QString());
        get_origin->addItem(QString());
        get_origin->addItem(QString());
        get_origin->addItem(QString());
        get_origin->addItem(QString());
        get_origin->addItem(QString());
        get_origin->addItem(QString());
        get_origin->addItem(QString());
        get_origin->addItem(QString());
        get_origin->addItem(QString());
        get_origin->setObjectName(QString::fromUtf8("get_origin"));

        horizontalLayout_2->addWidget(get_origin);

        layoutWidget4 = new QWidget(centralWidget);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(130, 37, 131, 22));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        des = new QLabel(layoutWidget4);
        des->setObjectName(QString::fromUtf8("des"));

        horizontalLayout_3->addWidget(des);

        get_destination = new QComboBox(layoutWidget4);
        get_destination->addItem(QString());
        get_destination->addItem(QString());
        get_destination->addItem(QString());
        get_destination->addItem(QString());
        get_destination->addItem(QString());
        get_destination->addItem(QString());
        get_destination->addItem(QString());
        get_destination->addItem(QString());
        get_destination->addItem(QString());
        get_destination->addItem(QString());
        get_destination->addItem(QString());
        get_destination->setObjectName(QString::fromUtf8("get_destination"));

        horizontalLayout_3->addWidget(get_destination);

        GUI->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GUI);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1309, 23));
        GUI->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GUI);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        GUI->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GUI);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        GUI->setStatusBar(statusBar);

        retranslateUi(GUI);

        QMetaObject::connectSlotsByName(GUI);
    } // setupUi

    void retranslateUi(QMainWindow *GUI)
    {
        GUI->setWindowTitle(QCoreApplication::translate("GUI", "GUI", nullptr));
        stop_simulation->setText(QCoreApplication::translate("GUI", "\347\273\223\346\235\237\346\250\241\346\213\237", nullptr));
        mymap->setText(QCoreApplication::translate("GUI", "map", nullptr));
        start_simulation->setText(QCoreApplication::translate("GUI", "\345\274\200\345\247\213\346\250\241\346\213\237", nullptr));
        label_3->setText(QCoreApplication::translate("GUI", "\345\275\223\345\211\215\346\227\266\351\227\264", nullptr));
        label->setText(QCoreApplication::translate("GUI", "\345\244\251", nullptr));
        label_2->setText(QCoreApplication::translate("GUI", "\346\227\266", nullptr));
        myicon->setText(QCoreApplication::translate("GUI", "TextLabel", nullptr));
        label_8->setText(QCoreApplication::translate("GUI", "\350\257\267\351\200\211\346\213\251\344\270\200\344\270\252\350\247\243\345\206\263\346\226\271\346\241\210", nullptr));
        solution->setText(QCoreApplication::translate("GUI", "\350\247\243\345\206\263\346\226\271\346\241\210", nullptr));
        label_4->setText(QCoreApplication::translate("GUI", "\346\227\205\350\241\214\347\212\266\346\200\201", nullptr));
        label_5->setText(QCoreApplication::translate("GUI", "\346\237\245\350\257\242\346\227\205\345\256\242\346\227\205\350\241\214\344\277\241\346\201\257", nullptr));
        get_day->setItemText(0, QCoreApplication::translate("GUI", "0", nullptr));
        get_day->setItemText(1, QCoreApplication::translate("GUI", "1", nullptr));
        get_day->setItemText(2, QCoreApplication::translate("GUI", "2", nullptr));
        get_day->setItemText(3, QCoreApplication::translate("GUI", "3", nullptr));
        get_day->setItemText(4, QCoreApplication::translate("GUI", "4", nullptr));
        get_day->setItemText(5, QCoreApplication::translate("GUI", "5", nullptr));
        get_day->setItemText(6, QCoreApplication::translate("GUI", "6", nullptr));
        get_day->setItemText(7, QCoreApplication::translate("GUI", "7", nullptr));
        get_day->setItemText(8, QCoreApplication::translate("GUI", "8", nullptr));
        get_day->setItemText(9, QCoreApplication::translate("GUI", "9", nullptr));
        get_day->setItemText(10, QCoreApplication::translate("GUI", "10", nullptr));
        get_day->setItemText(11, QCoreApplication::translate("GUI", "11", nullptr));
        get_day->setItemText(12, QCoreApplication::translate("GUI", "12", nullptr));
        get_day->setItemText(13, QCoreApplication::translate("GUI", "13", nullptr));
        get_day->setItemText(14, QCoreApplication::translate("GUI", "14", nullptr));
        get_day->setItemText(15, QCoreApplication::translate("GUI", "15", nullptr));
        get_day->setItemText(16, QCoreApplication::translate("GUI", "16", nullptr));
        get_day->setItemText(17, QCoreApplication::translate("GUI", "17", nullptr));
        get_day->setItemText(18, QCoreApplication::translate("GUI", "18", nullptr));
        get_day->setItemText(19, QCoreApplication::translate("GUI", "19", nullptr));
        get_day->setItemText(20, QCoreApplication::translate("GUI", "20", nullptr));
        get_day->setItemText(21, QCoreApplication::translate("GUI", "21", nullptr));
        get_day->setItemText(22, QCoreApplication::translate("GUI", "22", nullptr));
        get_day->setItemText(23, QCoreApplication::translate("GUI", "23", nullptr));

        label_6->setText(QCoreApplication::translate("GUI", "\345\244\251", nullptr));
        get_hour->setItemText(0, QCoreApplication::translate("GUI", "0", nullptr));
        get_hour->setItemText(1, QCoreApplication::translate("GUI", "1", nullptr));
        get_hour->setItemText(2, QCoreApplication::translate("GUI", "2", nullptr));
        get_hour->setItemText(3, QCoreApplication::translate("GUI", "3", nullptr));
        get_hour->setItemText(4, QCoreApplication::translate("GUI", "4", nullptr));
        get_hour->setItemText(5, QCoreApplication::translate("GUI", "5", nullptr));
        get_hour->setItemText(6, QCoreApplication::translate("GUI", "6", nullptr));
        get_hour->setItemText(7, QCoreApplication::translate("GUI", "7", nullptr));
        get_hour->setItemText(8, QCoreApplication::translate("GUI", "8", nullptr));
        get_hour->setItemText(9, QCoreApplication::translate("GUI", "9", nullptr));
        get_hour->setItemText(10, QCoreApplication::translate("GUI", "10", nullptr));
        get_hour->setItemText(11, QCoreApplication::translate("GUI", "11", nullptr));
        get_hour->setItemText(12, QCoreApplication::translate("GUI", "12", nullptr));
        get_hour->setItemText(13, QCoreApplication::translate("GUI", "13", nullptr));
        get_hour->setItemText(14, QCoreApplication::translate("GUI", "14", nullptr));
        get_hour->setItemText(15, QCoreApplication::translate("GUI", "15", nullptr));
        get_hour->setItemText(16, QCoreApplication::translate("GUI", "16", nullptr));
        get_hour->setItemText(17, QCoreApplication::translate("GUI", "17", nullptr));
        get_hour->setItemText(18, QCoreApplication::translate("GUI", "18", nullptr));
        get_hour->setItemText(19, QCoreApplication::translate("GUI", "19", nullptr));
        get_hour->setItemText(20, QCoreApplication::translate("GUI", "20", nullptr));
        get_hour->setItemText(21, QCoreApplication::translate("GUI", "21", nullptr));
        get_hour->setItemText(22, QCoreApplication::translate("GUI", "22", nullptr));
        get_hour->setItemText(23, QCoreApplication::translate("GUI", "23", nullptr));

        label_7->setText(QCoreApplication::translate("GUI", "\346\227\266", nullptr));
        get_user_state->setText(QCoreApplication::translate("GUI", "\346\237\245\350\257\242", nullptr));
        get_path->setText(QCoreApplication::translate("GUI", "\345\274\200\345\247\213\346\237\245\350\257\242\350\267\257\347\272\277", nullptr));
        time->setText(QCoreApplication::translate("GUI", "\345\260\217\346\227\266\345\206\205\345\210\260\350\276\276", nullptr));
        add_traveller->setText(QCoreApplication::translate("GUI", "\346\267\273\345\212\240\346\227\205\345\256\242", nullptr));
        choose_traveller->setItemText(0, QCoreApplication::translate("GUI", "\350\257\267\351\200\211\346\213\251\346\227\205\345\256\242", nullptr));

        choose_traveller->setCurrentText(QCoreApplication::translate("GUI", "\350\257\267\351\200\211\346\213\251\346\227\205\345\256\242", nullptr));
        choice->setText(QCoreApplication::translate("GUI", "\346\227\205\350\241\214\347\255\226\347\225\245", nullptr));
        get_strategy->setText(QCoreApplication::translate("GUI", "\344\270\215\351\231\220\346\227\266\346\234\200\345\260\217\351\243\216\351\231\251", nullptr));
        get_strategy_2->setText(QCoreApplication::translate("GUI", "\351\231\220\346\227\266\346\234\200\345\260\217\351\243\216\351\231\251", nullptr));
        unchecked->setText(QCoreApplication::translate("GUI", "unchecked", nullptr));
        ori->setText(QCoreApplication::translate("GUI", "\345\207\272\345\217\221\345\234\260", nullptr));
        get_origin->setItemText(0, QCoreApplication::translate("GUI", "\350\257\267\351\200\211\346\213\251", nullptr));
        get_origin->setItemText(1, QCoreApplication::translate("GUI", "\345\214\227\344\272\254", nullptr));
        get_origin->setItemText(2, QCoreApplication::translate("GUI", "\344\270\212\346\265\267", nullptr));
        get_origin->setItemText(3, QCoreApplication::translate("GUI", "\346\255\246\346\261\211", nullptr));
        get_origin->setItemText(4, QCoreApplication::translate("GUI", "\345\223\210\345\260\224\346\273\250", nullptr));
        get_origin->setItemText(5, QCoreApplication::translate("GUI", "\346\210\220\351\203\275", nullptr));
        get_origin->setItemText(6, QCoreApplication::translate("GUI", "\345\271\277\345\267\236", nullptr));
        get_origin->setItemText(7, QCoreApplication::translate("GUI", "\350\245\277\345\256\211", nullptr));
        get_origin->setItemText(8, QCoreApplication::translate("GUI", "\344\271\214\351\262\201\346\234\250\351\275\220", nullptr));
        get_origin->setItemText(9, QCoreApplication::translate("GUI", "\346\213\211\350\220\250", nullptr));
        get_origin->setItemText(10, QCoreApplication::translate("GUI", "\346\265\267\345\217\243", nullptr));

        des->setText(QCoreApplication::translate("GUI", "\347\233\256\347\232\204\345\234\260", nullptr));
        get_destination->setItemText(0, QCoreApplication::translate("GUI", "\350\257\267\351\200\211\346\213\251", nullptr));
        get_destination->setItemText(1, QCoreApplication::translate("GUI", "\345\214\227\344\272\254", nullptr));
        get_destination->setItemText(2, QCoreApplication::translate("GUI", "\344\270\212\346\265\267", nullptr));
        get_destination->setItemText(3, QCoreApplication::translate("GUI", "\346\255\246\346\261\211", nullptr));
        get_destination->setItemText(4, QCoreApplication::translate("GUI", "\345\223\210\345\260\224\346\273\250", nullptr));
        get_destination->setItemText(5, QCoreApplication::translate("GUI", "\346\210\220\351\203\275", nullptr));
        get_destination->setItemText(6, QCoreApplication::translate("GUI", "\345\271\277\345\267\236", nullptr));
        get_destination->setItemText(7, QCoreApplication::translate("GUI", "\350\245\277\345\256\211", nullptr));
        get_destination->setItemText(8, QCoreApplication::translate("GUI", "\344\271\214\351\262\201\346\234\250\351\275\220", nullptr));
        get_destination->setItemText(9, QCoreApplication::translate("GUI", "\346\213\211\350\220\250", nullptr));
        get_destination->setItemText(10, QCoreApplication::translate("GUI", "\346\265\267\345\217\243", nullptr));

    } // retranslateUi

};

namespace Ui {
    class GUI: public Ui_GUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
