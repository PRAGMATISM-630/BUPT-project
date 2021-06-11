/********************************************************************************
** Form generated from reading UI file 'rule.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RULE_H
#define UI_RULE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rule
{
public:
    QPushButton *ack;
    QTextBrowser *rules;

    void setupUi(QWidget *rule)
    {
        if (rule->objectName().isEmpty())
            rule->setObjectName(QString::fromUtf8("rule"));
        rule->resize(600, 440);
        ack = new QPushButton(rule);
        ack->setObjectName(QString::fromUtf8("ack"));
        ack->setGeometry(QRect(220, 400, 151, 41));
        rules = new QTextBrowser(rule);
        rules->setObjectName(QString::fromUtf8("rules"));
        rules->setGeometry(QRect(0, 0, 600, 400));

        retranslateUi(rule);

        QMetaObject::connectSlotsByName(rule);
    } // setupUi

    void retranslateUi(QWidget *rule)
    {
        rule->setWindowTitle(QCoreApplication::translate("rule", "Form", nullptr));
        ack->setText(QCoreApplication::translate("rule", "\346\210\221\347\237\245\351\201\223\344\272\206", nullptr));
        rules->setHtml(QCoreApplication::translate("rule", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\346\210\230\346\226\227\350\247\204\345\210\231 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">1\343\200\201\346\210\230\346\226\227\345\210\206\344\270\272\345\215\207\347\272\247\350\265\233\345\222\214\345\206\263\346\226\227\350\265\233\357\274\214\344\270\244\350\200\205\351\203\275\345\217\257\344\273\245\344\270\272\345\256\235\345\217\257\346\242\246\345\242\236\345\212\240\347\273\217\351\252\214\345"
                        "\200\274 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\345\215\207\347\272\247\350\265\233\357\274\232 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\342\221\240\351\200\211\346\213\251\345\256\235\345\217\257\346\242\246\344\270\216\346\234\215\345\212\241\345\231\250\347\232\204\345\256\235\345\217\257\346\242\246\350\277\233\350\241\214\350\231\232\346\213\237\346\210\230\346\226\227\343\200\202\302\240\302\240\302\240\302\240\302\240\302\240\302\240\302\240\302\240\302\240 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\342\221\241\344\273\205\347\224\250\344\272\216\347\273\231\345\256\235\345\217\257\346\242\246\350\216\267\345\276\227"
                        "\347\273\217\351\252\214\357\274\214\350\203\234\345\210\251\346\210\226\345\244\261\350\264\245\344\270\215\344\274\232\345\276\227\345\210\260\346\210\226\345\244\261\345\216\273\345\256\235\345\217\257\346\242\246\343\200\202</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\302\240 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\345\206\263\346\226\227\350\265\233\357\274\232 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\342\221\240\351\200\211\346\213\251\345\256\235\345\217\257\346\242\246\344\270\216\346\234\215\345\212\241\345\231\250\347\232\204\345\256\235\345\217\257\346\242\246\350\277\233\350\241\214\350\231\232\346\213\237\346\210"
                        "\230\346\226\227\343\200\202 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\342\221\241\345\246\202\346\236\234\350\203\234\345\210\251\357\274\214\345\217\257\344\273\245\350\216\267\345\276\227\350\257\245\346\210\230\350\203\234\347\232\204\345\256\235\345\217\257\346\242\246\343\200\202 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\342\221\242\345\246\202\346\236\234\345\244\261\350\264\245\357\274\214\345\260\206\347\224\261\347\263\273\347\273\237\345\205\210\351\232\217\346\234\272\351\200\211\345\207\2723\345\217\252\345\256\235\345\217\257\346\242\246\357\274\210\345\246\202\346\236\234\347\224\250\346\210\267\346\213\245\346\234\211\347\232\204\345\256\235\345\217\257\346\242\246\345\260\221\344\272\216\344\270\211\345\217\252\345\210\231\351\200\211\345"
                        "\207\272\345\205\266\346\211\200\346\234\211\345\256\235\345\217\257\346\242\246\357\274\211\357\274\214\347\204\266\345\220\216\347\224\250\346\210\267\351\200\211\346\213\251\345\205\266\344\270\255\344\270\200\345\217\252\351\200\201\345\207\272\343\200\202 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\342\221\243\345\275\223\347\224\250\346\210\267\345\244\261\345\216\273\346\211\200\346\213\245\346\234\211\347\232\204\346\234\200\345\220\216\344\270\200\345\217\252\345\256\235\345\217\257\346\242\246\346\227\266\357\274\214\347\263\273\347\273\237\344\274\232\350\207\252\345\212\250\345\217\221\346\224\276\344\270\200\345\217\252\345\210\235\345\247\213\347\212\266\346\200\201\347\232\204\345\256\235\345\217\257\346\242\246\343\200\202 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span st"
                        "yle=\" font-size:12pt;\">\302\240 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">2\343\200\201\344\274\244\345\256\263\350\256\241\347\256\227\346\234\272\345\210\266 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\351\235\242\346\235\277\346\224\273\345\207\273\357\274\232\345\256\235\345\217\257\346\242\246\347\232\204\345\237\272\347\241\200\346\224\273\345\207\273\345\200\274\343\200\202 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\345\237\272\347\241\200\345\200\215\347\216\207\357\274\2320.90~1.10\344\271\213\351\227\264\347\232\204\344\270\200\344\270\252\351\232\217\346\234\272\345\200\274 </span></p>\n"
"<p style=\" margin-top:12p"
                        "x; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\346\212\200\350\203\275\345\200\215\347\216\207\357\274\232\346\231\256\351\200\232\346\224\273\345\207\273\346\227\266\344\270\2721\357\274\214\351\207\212\346\224\276\346\212\200\350\203\275\346\227\266\350\257\267\345\217\202\350\247\201\347\233\270\345\205\263\346\212\200\350\203\275\346\217\217\350\277\260 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\346\232\264\345\207\273\344\274\244\345\256\263\345\200\215\347\216\207\357\274\232\350\247\246\345\217\221\346\232\264\345\207\273\346\227\266\344\270\2721.5\357\274\214\346\234\252\350\247\246\345\217\221\344\270\2721 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\302\240 </span>"
                        "</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\346\224\273\345\207\273\351\200\240\346\210\220\347\232\204\346\234\200\347\273\210\347\234\237\345\256\236\344\274\244\345\256\263= </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\351\235\242\346\235\277\346\224\273\345\207\273*\345\237\272\347\241\200\345\200\215\347\216\207*\346\212\200\350\203\275\345\200\215\347\216\207*\346\232\264\345\207\273\344\274\244\345\256\263\345\200\215\347\216\207-\346\225\214\346\226\271\351\230\262\345\276\241\345\200\274 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\302\240 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-rig"
                        "ht:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">3\343\200\201\346\232\264\345\207\273\343\200\201\351\227\252\351\201\277\346\234\272\345\210\266 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\346\232\264\345\207\273\350\247\246\345\217\221\346\246\202\347\216\207\357\274\23220% </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\346\232\264\345\207\273\344\274\244\345\256\263\345\200\215\347\216\207\357\274\2321.5 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\351\227\252\351\201\277\350\247\246\345\217\221\346\246\202\347\216\207\357\274\23210% </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; ma"
                        "rgin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\351\227\252\351\201\277\345\207\217\345\205\215\344\274\244\345\256\263\357\274\232100%\357\274\210\345\215\263\350\247\246\345\217\221\351\227\252\351\201\277\346\227\266\345\217\227\345\210\260\347\232\204\344\274\244\345\256\263\344\270\2720\357\274\211 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\302\240 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\351\203\250\345\210\206\345\256\235\345\217\257\346\242\246\347\232\204\346\212\200\350\203\275\344\274\232\346\224\271\345\217\230\350\247\246\345\217\221\346\232\264\345\207\273\346\210\226\351\227\252\351\201\277\347\232\204\346\246\202\347\216\207\357\274\214\345\205\267\344\275\223\350\257\267\345\217\202"
                        "\350\247\201\346\212\200\350\203\275\346\217\217\350\277\260 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\302\240 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">4\343\200\201\346\200\222\346\260\224\345\200\274 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\346\257\217\346\254\241\345\217\227\345\210\260\346\224\273\345\207\273\357\274\210\345\214\205\346\213\254\350\247\246\345\217\221\351\227\252\351\201\277\347\232\204\346\203\205\345\206\265\357\274\211\345\217\257\344\273\245\350\216\267\345\276\2271~2\347\202\271\346\200\222\346\260\224\345\200\274\343\200\202 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-l"
                        "eft:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\345\275\223\346\200\222\346\260\224\345\200\274\350\276\276\345\210\2605\347\202\271\346\227\266\357\274\214\345\217\257\344\273\245\344\275\277\347\224\250\346\212\200\350\203\275\343\200\202 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\351\207\212\346\224\276\346\212\200\350\203\275\345\220\216\357\274\214\346\200\222\346\260\224\345\200\274\346\270\205\351\233\266\343\200\202 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\302\240 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">5\343\200\201\346\212\200\350\203\275\357\274\210\344\273\212\345"
                        "\220\216\351\232\217\347\211\210\346\234\254\346\233\264\346\226\260\345\217\257\350\203\275\344\274\232\345\242\236\345\212\240\346\233\264\345\244\232\346\212\200\350\203\275\357\274\211 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">&quot;rage&quot;\302\240\302\240\302\240 \346\204\244\346\200\222\357\274\232\346\224\273\345\207\273\345\212\233\346\217\220\351\253\230100%\357\274\214\344\270\224100%\350\247\246\345\217\221\346\232\264\345\207\273(\347\201\253\347\263\273\357\274\211 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">&quot;tenacity&quot; \302\240\351\241\275\345\274\272\357\274\232\346\257\217\346\215\237\345\244\2613%\346\234\200\345\244\247\347\224\237\345\221\275\357\274\214\344\270\213\346\254\241\346\224\273\345\207\273\351\200\240\346\210\220\347"
                        "\232\204\344\274\244\345\256\263\346\217\220\351\253\23010%\357\274\210\345\234\237\347\263\273\357\274\211 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">&quot;refresh&quot;\302\240  \345\233\236\345\244\215\357\274\232\345\233\236\345\244\215\345\267\262\346\215\237\345\244\261\347\224\237\345\221\275\347\232\20430%\357\274\210\346\260\264\347\263\273\357\274\211 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">&quot;rebound&quot;\302\240  \345\217\215\345\274\271\357\274\232\345\257\271\346\225\214\346\226\271\351\200\240\346\210\220\344\270\212\346\254\241\350\242\253\346\224\273\345\207\273\346\211\200\345\217\227\344\274\244\345\256\263250%\347\232\204\344\274\244\345\256\263 (\347\224\265\347\263\273\357\274\211 </span></p>\n"
"<p style=\"-qt-paragraph-type:em"
                        "pty; margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt;\"><br /></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\346\210\230\346\226\227\346\227\266\357\274\214\351\274\240\346\240\207\347\247\273\350\207\263\346\212\200\350\203\275\345\233\276\346\240\207\346\210\226\346\210\221\346\226\271\345\256\235\345\217\257\346\242\246\345\233\276\347\211\207\344\270\212\357\274\214\345\217\257\344\273\245\346\230\276\347\244\272\346\210\221\346\226\271\345\256\235\345\217\257\346\242\246\347\232\204\346\212\200\350\203\275\343\200\202\351\274\240\346\240\207\347\247\273\350\207\263\346\225\214\346\226\271\345\256\235\345\217\257\346\242\246\345\233\276\347\211\207\344\270\212\357\274\214\345\217\257\344\273\245\346\230\276\347\244\272\346\225\214\346\226\271\345\256\235\345\217\257\346\242\246\347\232\204\346\212\200\350\203\275\343"
                        "\200\202</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\302\240 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">6\343\200\201\346\255\273\344\272\241\345\210\244\345\256\232 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\346\210\221\346\226\271\345\256\235\345\217\257\346\242\246\347\224\237\345\221\275\345\200\274\351\231\215\344\275\216\345\210\2600\346\227\266\357\274\214\346\210\230\346\226\227\345\244\261\350\264\245\343\200\202 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\346\225\214\346\226\271\345\256\235\345"
                        "\217\257\346\242\246\347\224\237\345\221\275\345\200\274\351\231\215\344\275\216\345\210\2600\346\227\266\357\274\214\346\210\230\346\226\227\350\203\234\345\210\251\343\200\202 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\302\240 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">7\343\200\201\350\207\252\345\212\250\346\210\230\346\226\227 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\347\202\271\345\207\273\350\207\252\345\212\250\346\210\230\346\226\227\346\214\211\351\222\256\350\277\233\345\205\245\350\207\252\345\212\250\346\210\230\346\226\227\347\212\266\346\200\201\357\274\214\345\206\215\346\254\241\347\202\271\345\207\273\345\220"
                        "\216\345\217\226\346\266\210\343\200\202 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\350\207\252\345\212\250\346\210\230\346\226\227\347\212\266\346\200\201\344\270\213\357\274\214\344\270\215\345\217\257\344\273\245\346\211\213\345\212\250\350\277\233\350\241\214\346\231\256\351\200\232\346\224\273\345\207\273\346\210\226\351\207\212\346\224\276\346\212\200\350\203\275\343\200\202 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\350\207\252\345\212\250\346\210\230\346\226\227\347\212\266\346\200\201\344\270\213\357\274\214\346\225\214\346\210\221\345\217\214\346\226\271\345\235\207\344\270\272\344\274\230\345\205\210\350\277\233\350\241\214\351\207\212\346\224\276\346\212\200\350\203\275\357\274\210\345\215\263\346\200\222\346\260\224\345\200\274\350\276\276\345"
                        "\210\2605\347\202\271\345\220\216\347\253\213\345\215\263\351\207\212\346\224\276\346\212\200\350\203\275\357\274\211\343\200\202 </span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class rule: public Ui_rule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RULE_H
