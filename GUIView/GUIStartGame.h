#pragma once
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QMessageBox>
#include <QSignalMapper>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCheckBox>
#include <string>
#include "GUIView.h"
#include "IGame.h"

class GUIStartGame: public QMainWindow
{
public:
    QWidget* centralwidget;
    QWidget* verticalLayoutWidget;
    QVBoxLayout* verticalLayout;
    QLabel* label;
    QLabel* label_2;
    QLabel* label_3;
    QLineEdit* lineEdit;
    QLabel* label_4;
    QLineEdit* lineEdit_2;
    QPushButton* StartGame;
    QMenuBar* menubar;
    QStatusBar* statusbar;
	QCheckBox* checkBoxDifficulty;
	QComboBox* comboBox;
    
	GUIStartGame();
    void SetupStartGame(QMainWindow* MainWindow);
    void RetranslateStartGame(QMainWindow* MainWindow);
    void OnCheckBoxChecked();
    void OnStartGamePressed();
    
	~GUIStartGame() = default;
};

