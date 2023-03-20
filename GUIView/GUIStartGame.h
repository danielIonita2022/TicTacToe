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
    
	GUIStartGame(IGamePtr game);
    void SetupStartGame(QMainWindow* MainWindow);
    void RetranslateStartGame(QMainWindow* MainWindow);
	std::string GetPlayer1Name();
	std::string GetPlayer2Name();
    void OnStartGamePressed();
    
private:
    std::string m_player1;
	std::string m_player2;
	IGamePtr m_game;
};

