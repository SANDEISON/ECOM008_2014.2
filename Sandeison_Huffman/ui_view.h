/********************************************************************************
** Form generated from reading UI file 'view.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW_H
#define UI_VIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_View
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_Search;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *Compress;
    QPushButton *Save;
    QLabel *Save_File;
    QLineEdit *lineEdit_Save;
    QLabel *Open_File;
    QPushButton *Cancel;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *Search;
    QSpacerItem *horizontalSpacer;
    QPushButton *Decompress;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *View)
    {
        if (View->objectName().isEmpty())
            View->setObjectName(QStringLiteral("View"));
        View->resize(406, 237);
        centralWidget = new QWidget(View);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit_Search = new QLineEdit(centralWidget);
        lineEdit_Search->setObjectName(QStringLiteral("lineEdit_Search"));

        gridLayout->addWidget(lineEdit_Search, 1, 0, 1, 6);

        horizontalSpacer_6 = new QSpacerItem(78, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 4, 6, 1, 2);

        horizontalSpacer_7 = new QSpacerItem(101, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 4, 3, 1, 1);

        Compress = new QPushButton(centralWidget);
        Compress->setObjectName(QStringLiteral("Compress"));

        gridLayout->addWidget(Compress, 4, 4, 1, 1);

        Save = new QPushButton(centralWidget);
        Save->setObjectName(QStringLiteral("Save"));

        gridLayout->addWidget(Save, 3, 7, 1, 1);

        Save_File = new QLabel(centralWidget);
        Save_File->setObjectName(QStringLiteral("Save_File"));

        gridLayout->addWidget(Save_File, 2, 0, 1, 1);

        lineEdit_Save = new QLineEdit(centralWidget);
        lineEdit_Save->setObjectName(QStringLiteral("lineEdit_Save"));

        gridLayout->addWidget(lineEdit_Save, 3, 0, 1, 6);

        Open_File = new QLabel(centralWidget);
        Open_File->setObjectName(QStringLiteral("Open_File"));

        gridLayout->addWidget(Open_File, 0, 0, 1, 1);

        Cancel = new QPushButton(centralWidget);
        Cancel->setObjectName(QStringLiteral("Cancel"));

        gridLayout->addWidget(Cancel, 5, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(48, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 4, 0, 1, 2);

        Search = new QPushButton(centralWidget);
        Search->setObjectName(QStringLiteral("Search"));

        gridLayout->addWidget(Search, 1, 7, 1, 1);

        horizontalSpacer = new QSpacerItem(334, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 7);

        Decompress = new QPushButton(centralWidget);
        Decompress->setObjectName(QStringLiteral("Decompress"));

        gridLayout->addWidget(Decompress, 4, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(334, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 1, 1, 7);

        View->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(View);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 406, 20));
        View->setMenuBar(menuBar);
        mainToolBar = new QToolBar(View);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        View->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(View);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        View->setStatusBar(statusBar);

        retranslateUi(View);

        QMetaObject::connectSlotsByName(View);
    } // setupUi

    void retranslateUi(QMainWindow *View)
    {
        View->setWindowTitle(QApplication::translate("View", "Huffman", 0));
        Compress->setText(QApplication::translate("View", "Compress", 0));
        Save->setText(QApplication::translate("View", "Save", 0));
        Save_File->setText(QApplication::translate("View", "Save File", 0));
        Open_File->setText(QApplication::translate("View", "Open File", 0));
        Cancel->setText(QApplication::translate("View", "Cancel", 0));
        Search->setText(QApplication::translate("View", "Search", 0));
        Decompress->setText(QApplication::translate("View", "Decompress", 0));
    } // retranslateUi

};

namespace Ui {
    class View: public Ui_View {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_H
