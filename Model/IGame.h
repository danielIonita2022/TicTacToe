#pragma once

#include "IGameListener.h"
#include "IPlayer.h"
#include "EGameState.h"

class IGame
{
public:
	/// <summary>
	/// Produces a shared pointer to a Game object.
	/// </summary>
	/// <returns>Pointer to IGame interface.</returns>
	static IGamePtr Produce();
	/// <summary>
	/// Method that creates a player.
	/// </summary>
	/// <param name="playerNo">1 for the first player, 2 for the second player.</param>
	/// <param name="name">The name of the player.</param>
	virtual void CreatePlayer(int playerNo, const std::string& name) = 0;
	/// <summary>
	/// Method that returns the first player.
	/// </summary>
	/// <returns>A Player object.</returns>
	virtual IPlayerPtr GetPlayer1() const = 0;
	/// <summary>
	/// Method that returns the second player.
	/// </summary>
	/// <returns>A Player object.</returns>
	virtual IPlayerPtr GetPlayer2() const = 0;
	/// <summary>
	/// Method that returns the current player.
	/// </summary>
	/// <returns></returns>
	virtual IPlayerPtr GetCurrentPlayer() const = 0;
	/// <summary>
	///  Method that confirms that a move has been made and notifies the observers.
	/// </summary>
	/// <param name="player">Current player that makes the move</param>
	/// <param name="position">The position on the board the player chose.</param>
	/// <returns></returns>
	virtual bool MakeMove(int position) = 0;
	/// <summary>
	/// Method that adds a listener.
	/// </summary>
	/// <param name="listener">Pointer to observer object</param>
	virtual void AddListener(IGameListener* listener) = 0;
	/// <summary>
	/// Method that removes the given listener.
	/// </summary>
	/// <param name="listener">Pointer to observer object</param>
	virtual void RemoveListener(IGameListener* listener) = 0;
	/// <summary>
	/// Method that returns the board.
	/// </summary>
	/// <returns>A Board object.</returns>
	virtual std::array <ESymbol, 9> GetBoardArray() const = 0;
	/// <summary>
	/// Returns current game state.
	/// </summary>
	virtual EGameState GetGameState() const = 0;

	virtual ~IGame() = default;
};

