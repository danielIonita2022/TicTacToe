#include "GUIStartGame.h"
#include "EGameDifficulty.h"

GUIStartGame::GUIStartGame()
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
    
    checkBoxDifficulty = new QCheckBox(verticalLayoutWidget);
	checkBoxDifficulty->setObjectName("checkBoxDifficulty");
	connect(checkBoxDifficulty, &QCheckBox::clicked, this, &GUIStartGame::OnCheckBoxChecked);
	verticalLayout->addWidget(checkBoxDifficulty);
    
	comboBox = new QComboBox(verticalLayoutWidget);
	comboBox->setObjectName("comboBox");
	comboBox->setEnabled(false);
	comboBox->addItem("Easy");
	comboBox->addItem("Medium");
	comboBox->addItem("Hard");
	verticalLayout->addWidget(comboBox);

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
	checkBoxDifficulty->setText(QCoreApplication::translate("MainWindow", "Play against the computer", nullptr));
    StartGame->setText(QCoreApplication::translate("MainWindow", "Start Game!", nullptr));
}

void GUIStartGame::OnCheckBoxChecked()
{
	if (checkBoxDifficulty->isChecked())
	{
		label_4->setText(QCoreApplication::translate("MainWindow", "Computer", nullptr));
		lineEdit_2->setEnabled(false);
		comboBox->setEnabled(true);
	}
	else
	{
		label_4->setText(QCoreApplication::translate("MainWindow", "Second player", nullptr));
        lineEdit_2->setEnabled(true);
		comboBox->setEnabled(false);
	}
}

void GUIStartGame::OnStartGamePressed()
{
	if (checkBoxDifficulty->isChecked())
	{
		std::string playerName = lineEdit->text().toStdString();
		std::string difficulty = comboBox->currentText().toStdString();
		if (playerName.empty())
		{
			QMessageBox::warning(this, "Warning", "Please enter your name!");
		}
		else
		{
			this->close();
			IGamePtr game = IGame::Produce();
			IGameListener* guiViewPtr = new GUIView(game, playerName);
			game->AddListener(guiViewPtr);
			game->SetStrategy(StrToDifficulty(difficulty));
			GUIView* view = dynamic_cast<GUIView*>(guiViewPtr);
			view->RunGame();
			game->RemoveListener(guiViewPtr);
			delete guiViewPtr;
		}
	}
	else
	{
		std::string playerName1 = lineEdit->text().toStdString();
		std::string playerName2 = lineEdit_2->text().toStdString();
		if (playerName1.empty() || playerName2.empty())
		{
			QMessageBox::warning(this, "Warning", "Please enter your names!");
		}
		else
		{
			this->close();
			IGamePtr game = IGame::Produce();
			IGameListener* guiViewPtr = new GUIView(game, playerName1, playerName2);
			game->AddListener(guiViewPtr);
			GUIView* view = dynamic_cast<GUIView*>(guiViewPtr);
			view->RunGame();
			game->RemoveListener(guiViewPtr);
			delete guiViewPtr;
		}
	}
}
