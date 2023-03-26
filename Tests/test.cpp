#include "pch.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "IGameListener.h"
#include "IGame.h"
#include "IPlayer.h"

using namespace testing;


bool operator==(const Player& first, const Player& second)
{
	return first.GetName() == second.GetName() && first.GetSymbol() == second.GetSymbol();
}

class MockGameListener : public IGameListener
{
public:
	MockGameListener(IGamePtr game) : m_game(game) {}
	MOCK_METHOD(void, OnMakeMove, (), (override));
	MOCK_METHOD(void, OnGameOver, (Player& player), (override));

	~MockGameListener() override = default;

private:
	IGamePtr m_game;
};

TEST(TestListener, CheckOnMakeMove)
{
	IGamePtr game = IGame::Produce();
	game->CreatePlayer(1, "ana");
	game->CreatePlayer(2, "maria");
	MockGameListener* listener = new MockGameListener(game);
	game->AddListener(listener);

	EXPECT_CALL(*listener, OnMakeMove()).Times(1);

	game->HasMadeMove(game->GetPlayer1(), 0);

	game->RemoveListener(listener);
	delete listener;
}

TEST(TestListener, CheckOnGameOver)
{
	IGamePtr game = IGame::Produce();
	game->CreatePlayer(1, "ana");
	game->CreatePlayer(2, "maria");
	MockGameListener* listener = new MockGameListener(game);
	game->AddListener(listener);

	EXPECT_CALL(*listener, OnMakeMove()).Times(5);
	EXPECT_CALL(*listener, OnGameOver(game->GetPlayer1()));

	game->HasMadeMove(game->GetPlayer1(), 0);
	game->HasMadeMove(game->GetPlayer2(), 1);
	game->HasMadeMove(game->GetPlayer1(), 3);
	game->HasMadeMove(game->GetPlayer2(), 4);
	game->HasMadeMove(game->GetPlayer1(), 6);

	game->RemoveListener(listener);
	delete listener;
}

TEST(TestBoard, CheckValidPosition)
{
	Board board;

	ASSERT_TRUE(board.IsValidPosition(0));
}

TEST(TestBoard, CheckInvalidPosition)
{
	Board board;

	ASSERT_FALSE(board.IsValidPosition(9));
}

TEST(TestBoard, CheckOccupiedPosition)
{
	Board board;
	board.PlaceSymbol(3, ESymbol::X);

	ASSERT_FALSE(board.IsValidPosition(3));
}
  
TEST(TestBoard, IsEmptyPosition)
{
	Board board;
	auto matrixBoard = board.GetMatrixBoard();

	ASSERT_EQ(matrixBoard[1], ESymbol::None);
}

TEST(TestBoard, IsSymbolPlaced)
{
	Board board;
	board.PlaceSymbol(4, ESymbol::X);
	auto matrixBoard = board.GetMatrixBoard();

	ASSERT_EQ(matrixBoard[4], ESymbol::X);
}

TEST(TestGame, HasXWonLine)
{
	IGamePtr game = IGame::Produce();
	Board board = game->GetBoard();
	game->CreatePlayer(1, "Player1");
	game->CreatePlayer(2, "Player2");
	Player player1 = game->GetPlayer1();
	Player player2 = game->GetPlayer2();
	MockGameListener* listener = new MockGameListener(game);
	game->AddListener(listener);

	EXPECT_CALL(*listener, OnMakeMove()).Times(5);
	EXPECT_CALL(*listener, OnGameOver(player1));

	game->HasMadeMove(player1, 0);
	game->HasMadeMove(player2, 3);
	game->HasMadeMove(player1, 1);
	game->HasMadeMove(player2, 4);
	game->HasMadeMove(player1, 2);

	ASSERT_EQ(game->GetGameState(), EGameState::XWon);

	game->RemoveListener(listener);
	delete listener;
}

TEST(TestGame, HasXWonColumn)
{
	IGamePtr game = IGame::Produce();
	Board board = game->GetBoard();
	game->CreatePlayer(1, "Player1");
	game->CreatePlayer(2, "Player2");
	Player player1 = game->GetPlayer1();
	Player player2 = game->GetPlayer2();
	MockGameListener* listener = new MockGameListener(game);
	game->AddListener(listener);

	EXPECT_CALL(*listener, OnMakeMove()).Times(5);
	EXPECT_CALL(*listener, OnGameOver(player1));

	game->HasMadeMove(player1, 0);
	game->HasMadeMove(player2, 1);
	game->HasMadeMove(player1, 3);
	game->HasMadeMove(player2, 2);
	game->HasMadeMove(player1, 6);

	game->UpdateGameState();

	ASSERT_EQ(game->GetGameState(), EGameState::XWon);

	game->RemoveListener(listener);
	delete listener;
}

TEST(TestGame, HasOWonDiagonal)
{
	IGamePtr game = IGame::Produce();
	Board board = game->GetBoard();
	game->CreatePlayer(1, "Player1");
	game->CreatePlayer(2, "Player2");
	Player player1 = game->GetPlayer1();
	Player player2 = game->GetPlayer2();
	MockGameListener* listener = new MockGameListener(game);
	game->AddListener(listener);

	EXPECT_CALL(*listener, OnMakeMove()).Times(6);
	EXPECT_CALL(*listener, OnGameOver(player2));

	game->HasMadeMove(player1, 1);
	game->HasMadeMove(player2, 0);
	game->HasMadeMove(player1, 2);
	game->HasMadeMove(player2, 4);
	game->HasMadeMove(player1, 6);
	game->HasMadeMove(player2, 8);

	game->UpdateGameState();

	ASSERT_EQ(game->GetGameState(), EGameState::OWon);

	game->RemoveListener(listener);
	delete listener;
}

TEST(TestGame, HasDrawn)
{
	IGamePtr game = IGame::Produce();
	Board board = game->GetBoard();
	game->CreatePlayer(1, "Player1");
	game->CreatePlayer(2, "Player2");
	Player player1 = game->GetPlayer1();
	Player player2 = game->GetPlayer2();
	MockGameListener* listener = new MockGameListener(game);
	game->AddListener(listener);

	EXPECT_CALL(*listener, OnMakeMove()).Times(9);
	EXPECT_CALL(*listener, OnGameOver(player1));

	game->HasMadeMove(player1, 0);
	game->HasMadeMove(player2, 1);
	game->HasMadeMove(player1, 3);
	game->HasMadeMove(player2, 6);
	game->HasMadeMove(player1, 7);
	game->HasMadeMove(player2, 4);
	game->HasMadeMove(player1, 2);
	game->HasMadeMove(player2, 5);
	game->HasMadeMove(player1, 8);

	game->UpdateGameState();

	ASSERT_EQ(game->GetGameState(), EGameState::Draw);

	game->RemoveListener(listener);
	delete listener;
}

TEST(TestGame, IsOngoing)
{
	IGamePtr game = IGame::Produce();
	Board board = game->GetBoard();
	game->CreatePlayer(1, "Player1");
	game->CreatePlayer(2, "Player2");
	Player player1 = game->GetPlayer1();
	Player player2 = game->GetPlayer2();
	MockGameListener* listener = new MockGameListener(game);
	game->AddListener(listener);

	EXPECT_CALL(*listener, OnMakeMove()).Times(8);

	game->HasMadeMove(player1, 0);
	game->HasMadeMove(player2, 1);
	game->HasMadeMove(player1, 3);
	game->HasMadeMove(player2, 6);
	game->HasMadeMove(player1, 7);
	game->HasMadeMove(player2, 4);
	game->HasMadeMove(player1, 2);
	game->HasMadeMove(player2, 5);

	game->UpdateGameState();

	ASSERT_EQ(game->GetGameState(), EGameState::Ongoing);

	game->RemoveListener(listener);
	delete listener;
}


int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

