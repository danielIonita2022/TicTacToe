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
#include "IGameListener.h"
#include "IGame.h"

class GUIView: public QMainWindow, public IGameListener
{
    Q_OBJECT
public:

    QWidget* gridLayoutWidget;
    QGridLayout* gridLayout;
    QPushButton* pushButton_00;
    QPushButton* pushButton_21;
    QPushButton* pushButton_01;
    QPushButton* pushButton_20;
    QPushButton* pushButton_10;
    QPushButton* pushButton_11;
    QPushButton* pushButton_02;
    QPushButton* pushButton_12;
    QPushButton* pushButton_22;
    QLabel* label_5;
    QSignalMapper* signalMapper;
    QPushButton* m_button;
    QEventLoop* loop;
    
	GUIView(IGamePtr game, std::string player1, std::string player2);
    int OnPlayerTurn(IPlayerPtr player) override;
    int OnInvalidMove() override;
    void OnMakeMove() override;
    void OnGameOver(IPlayerPtr player, bool isDraw) override;
    void OnButtonClicked();

    void SetupGame(QMainWindow* MainWindow);
    void RetranslateGame(QMainWindow* MainWindow);
    
public slots: void commonSlot();
    
signals: void buttonClicked();
    
private:
    IGamePtr m_game;
    int m_position;
};

namespace Ui {
    class MainWindow: public GUIView {};
} // namespace Ui

