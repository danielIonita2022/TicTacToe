#include "GUIView.h"

GUIView::GUIView(IGamePtr game, std::string player1, std::string player2) :
	m_game(game)
{
	m_game->CreatePlayer(1, player1);
	m_game->CreatePlayer(2, player2);
	SetupGame(this);
	this->show();
}

void GUIView::StartGame()
{
	IPlayerPtr player1 = m_game->GetPlayer1();
	IPlayerPtr player2 = m_game->GetPlayer2();
	while (m_game->GetGameState() == EGameState::Ongoing)
	{
		PlayerTurn(player1);
		if (m_game->GetGameState() == EGameState::Ongoing)
		{
			PlayerTurn(player2);
		}
	}
}
void GUIView::PlayerTurn(IPlayerPtr& player)
{
	label_5->setText(QString::fromStdString("It's your turn, " + player->GetName()));
	m_position = -1;
	loop->exec();
	m_game->HasMadeMove(player, m_position);
}

void GUIView::OnMakeMove()
{
	auto board = m_game->GetBoard().GetMatrixBoard();
	if (board[0] == ESymbol::X)
	{
		pushButton_00->setText("X");
	}
	else if (board[0] == ESymbol::O)
	{
		pushButton_00->setText("O");
	}
	if (board[1] == ESymbol::X)
	{
		pushButton_01->setText("X");
	}
	else if (board[1] == ESymbol::O)
	{
		pushButton_01->setText("O");
	}
	if (board[2] == ESymbol::X)
	{
		pushButton_02->setText("X");
	}
	else if (board[2] == ESymbol::O)
	{
		pushButton_02->setText("O");
	}
	if (board[3] == ESymbol::X)
	{
		pushButton_10->setText("X");
	}
	else if (board[3] == ESymbol::O)
	{
		pushButton_10->setText("O");
	}
	if (board[4] == ESymbol::X)
	{
		pushButton_11->setText("X");
	}
	else if (board[4] == ESymbol::O)
	{
		pushButton_11->setText("O");
	}
	if (board[5] == ESymbol::X)
	{
		pushButton_12->setText("X");
	}
	else if (board[5] == ESymbol::O)
	{
		pushButton_12->setText("O");
	}
	if (board[6] == ESymbol::X)
	{
		pushButton_20->setText("X");
	}
	else if (board[6] == ESymbol::O)
	{
		pushButton_20->setText("O");
	}
	if (board[7] == ESymbol::X)
	{
		pushButton_21->setText("X");
	}
	else if (board[7] == ESymbol::O)
	{
		pushButton_21->setText("O");
	}
	if (board[8] == ESymbol::X)
	{
		pushButton_22->setText("X");
	}
	else if (board[8] == ESymbol::O)
	{
		pushButton_22->setText("O");
	}
}

void GUIView::OnGameOver(IPlayerPtr& player)
{
    if (m_game->GetGameState() == EGameState::Draw)
    {
		QMessageBox::information(this, "Game Over", "Game Over. It's a draw!");
	}
	else
	{
		QMessageBox::information(this, "Game Over", "Game Over. " + QString::fromStdString(player->GetName()) + " wins!");
    }
	close();
}

void GUIView::CommonSlot()
{
	QWidget* buttonWidget = qobject_cast<QWidget*>(sender());
	if (!buttonWidget)
	{
		return;
	}
	
	int rowOfButton, columnOfButton, rowSpanOfButton, columnSpanOfButton;
	gridLayout->getItemPosition(gridLayout->indexOf(buttonWidget), &rowOfButton, &columnOfButton, &rowSpanOfButton, &columnSpanOfButton);

	QLayoutItem* item = gridLayout->itemAtPosition(rowOfButton, columnOfButton);
	QPushButton* clickedButton = qobject_cast<QPushButton*>(item->widget());
	if (!clickedButton)
		return;

	clickedButton->setEnabled(false);
	
	m_position = rowOfButton * 3 + columnOfButton;
	
	loop->quit();
}

void GUIView::SetupGame(QMainWindow* MainWindow)
{
    if (objectName().isEmpty())
        setObjectName("Form");
    resize(747, 375);
	loop = new QEventLoop(this);
    gridLayoutWidget = new QWidget(this);
	signalMapper = new QSignalMapper(this);
    gridLayoutWidget->setObjectName("gridLayoutWidget");
    gridLayoutWidget->setGeometry(QRect(188, 70, 321, 261));
    gridLayout = new QGridLayout(gridLayoutWidget);
    gridLayout->setObjectName("gridLayout");
    gridLayout->setContentsMargins(0, 0, 0, 0);
    pushButton_00 = new QPushButton(gridLayoutWidget);
    pushButton_00->setObjectName("pushButton");
    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(pushButton_00->sizePolicy().hasHeightForWidth());
    pushButton_00->setSizePolicy(sizePolicy);
    pushButton_00->setMaximumSize(QSize(102, 16777215));
	connect(pushButton_00, SIGNAL(clicked()), this, SLOT(CommonSlot()));
	signalMapper->setMapping(pushButton_00, 0);
	
    gridLayout->addWidget(pushButton_00, 0, 0, 1, 1);

    pushButton_21 = new QPushButton(gridLayoutWidget);
	connect(pushButton_21, SIGNAL(clicked()), this, SLOT(CommonSlot()));
	signalMapper->setMapping(pushButton_21, 7);
    pushButton_21->setObjectName("pushButton_6");

    gridLayout->addWidget(pushButton_21, 2, 1, 1, 1);

    pushButton_01 = new QPushButton(gridLayoutWidget);
	connect(pushButton_01, SIGNAL(clicked()), this, SLOT(CommonSlot()));
	signalMapper->setMapping(pushButton_01, 1);
    pushButton_01->setObjectName("pushButton_2");

    gridLayout->addWidget(pushButton_01, 0, 1, 1, 1);

    pushButton_20 = new QPushButton(gridLayoutWidget);
	connect(pushButton_20, SIGNAL(clicked()), this, SLOT(CommonSlot()));
	signalMapper->setMapping(pushButton_20, 6);
	
    pushButton_20->setObjectName("pushButton_5");

    gridLayout->addWidget(pushButton_20, 2, 0, 1, 1);

    pushButton_10 = new QPushButton(gridLayoutWidget);
	connect(pushButton_10, SIGNAL(clicked()), this, SLOT(CommonSlot()));
	signalMapper->setMapping(pushButton_10, 3);
    pushButton_10->setObjectName("pushButton_3");

    gridLayout->addWidget(pushButton_10, 1, 0, 1, 1);

    pushButton_11 = new QPushButton(gridLayoutWidget);
	connect(pushButton_11, SIGNAL(clicked()), this, SLOT(CommonSlot()));
	signalMapper->setMapping(pushButton_11, 4);
    pushButton_11->setObjectName("pushButton_4");

    gridLayout->addWidget(pushButton_11, 1, 1, 1, 1);

    pushButton_02 = new QPushButton(gridLayoutWidget);
	connect(pushButton_02, SIGNAL(clicked()), this, SLOT(CommonSlot()));
	signalMapper->setMapping(pushButton_02, 2);
	
    pushButton_02->setObjectName("pushButton_7");

    gridLayout->addWidget(pushButton_02, 0, 2, 1, 1);

    pushButton_12 = new QPushButton(gridLayoutWidget);
	connect(pushButton_12, SIGNAL(clicked()), this, SLOT(CommonSlot()));
	signalMapper->setMapping(pushButton_12, 5);
	
    pushButton_12->setObjectName("pushButton_8");

    gridLayout->addWidget(pushButton_12, 1, 2, 1, 1);

    pushButton_22 = new QPushButton(gridLayoutWidget);
	connect(pushButton_22, SIGNAL(clicked()), this, SLOT(CommonSlot()));
	signalMapper->setMapping(pushButton_22, 8);
    pushButton_22->setObjectName("pushButton_9");

    gridLayout->addWidget(pushButton_22, 2, 2, 1, 1);

    label_5 = new QLabel(this);
    label_5->setObjectName("label");
    label_5->setGeometry(QRect(190, 30, 311, 31));
    label_5->setAlignment(Qt::AlignCenter);
	
    RetranslateGame(this);

    QMetaObject::connectSlotsByName(this);
}

void GUIView::RetranslateGame(QMainWindow* MainWindow)
{
    setWindowTitle(QCoreApplication::translate("Form", "TicTacToe", nullptr));
    pushButton_00->setText(QString());
    pushButton_21->setText(QString());
    pushButton_01->setText(QString());
    pushButton_20->setText(QString());
    pushButton_10->setText(QString());
    pushButton_11->setText(QString());
    pushButton_02->setText(QString());
    pushButton_12->setText(QString());
    pushButton_22->setText(QString());
    label_5->setText(QCoreApplication::translate("Form", "It's your turn ", nullptr));
}
