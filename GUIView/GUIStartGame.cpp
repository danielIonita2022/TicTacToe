#include "GUIStartGame.h"

GUIStartGame::GUIStartGame(IGamePtr game):
    m_game(game)
{
	SetupStartGame(this);
}

void GUIStartGame::SetupStartGame(QMainWindow* MainWindow)
{
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName("MainWindow");
    MainWindow->resize(631, 314);

    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName("centralwidget");
    verticalLayoutWidget = new QWidget(centralwidget);
    verticalLayoutWidget->setObjectName("verticalLayoutWidget");
    verticalLayoutWidget->setGeometry(QRect(39, 29, 531, 231));
    verticalLayout = new QVBoxLayout(verticalLayoutWidget);
    verticalLayout->setObjectName("verticalLayout");
    verticalLayout->setContentsMargins(0, 0, 0, 0);
    label = new QLabel(verticalLayoutWidget);
    label->setObjectName("label");
    label->setAlignment(Qt::AlignCenter);

    verticalLayout->addWidget(label);

    label_2 = new QLabel(verticalLayoutWidget);
    label_2->setObjectName("label_2");

    verticalLayout->addWidget(label_2);

    label_3 = new QLabel(verticalLayoutWidget);
    label_3->setObjectName("label_3");

    verticalLayout->addWidget(label_3);

    lineEdit = new QLineEdit(verticalLayoutWidget);
    lineEdit->setObjectName("lineEdit");

    verticalLayout->addWidget(lineEdit);

    label_4 = new QLabel(verticalLayoutWidget);
    label_4->setObjectName("label_4");

    verticalLayout->addWidget(label_4);

    lineEdit_2 = new QLineEdit(verticalLayoutWidget);
    lineEdit_2->setObjectName("lineEdit_2");

    verticalLayout->addWidget(lineEdit_2);

    StartGame = new QPushButton(verticalLayoutWidget);
    connect(StartGame, &QPushButton::clicked, this, &GUIStartGame::OnStartGamePressed);
    StartGame->setObjectName("StartGame");

    verticalLayout->addWidget(StartGame);

    MainWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName("menubar");
    menubar->setGeometry(QRect(0, 0, 631, 22));
    MainWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName("statusbar");
    MainWindow->setStatusBar(statusbar);

    RetranslateStartGame(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);
}

void GUIStartGame::RetranslateStartGame(QMainWindow* MainWindow)
{
    MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "TicTacToe", nullptr));
    label->setText(QCoreApplication::translate("MainWindow", "Welcome to TicTacToe!", nullptr));
    label_2->setText(QCoreApplication::translate("MainWindow", "Please enter your names:", nullptr));
    label_3->setText(QCoreApplication::translate("MainWindow", "First player", nullptr));
    label_4->setText(QCoreApplication::translate("MainWindow", "Second player", nullptr));
    StartGame->setText(QCoreApplication::translate("MainWindow", "Start Game!", nullptr));
}

std::string GUIStartGame::GetPlayer1Name()
{
	return m_player1;
}

std::string GUIStartGame::GetPlayer2Name()
{
	return m_player2;
}

void GUIStartGame::OnStartGamePressed()
{
	m_player1 = lineEdit->text().toStdString();
	m_player2 = lineEdit_2->text().toStdString();
	if (m_player1.empty() || m_player2.empty())
	{
		QMessageBox::warning(this, "Warning", "Please enter your names!");
	}
	else
	{
		this->close();
		GUIView* view = new GUIView(m_game, m_player1, m_player2);
        view->show();
        /*IPlayerPtr player = IPlayer::Produce(m_player1);
        int pos = view->OnPlayerTurn(player);*/
        m_game->StartGame();
	}
}
