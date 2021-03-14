#include <bits/stdc++.h>
#include "models/Ladder.h"
#include "models/Person.h"
#include "models/Snake.h"
#define BOARD_SIZE 100
#define GAME_NOT_OVER 0
#define GAME_OVER 1

using namespace std;
class Game
{
private:
      vector<Snake> mSnakes;
      vector<Ladder> mLadders;
      vector<Player> mPlayers;
      int numberOfPlayers;

public:
      Game(vector<pair<int, int>> snakePositions, vector<pair<int, int>> ladderPositions, vector<string> players);
      int rollDice();
      void startGame();
      void moveBoard(Player &currentPlayer, int diceValue);
      void diceRolledMessage(int messageType, Player currentPlayer, int dice);
      bool isSnakeBite(int &);
      bool isLadderClimb(int &);
};

void Game::diceRolledMessage(int messageType, Player currentPlayer, int dice)
{
      if (messageType == GAME_NOT_OVER)
      {
            cout << currentPlayer.getName() << " rolled a " << dice << " and moved from " << currentPlayer.getPreviousPosition() << " to " << currentPlayer.getCurrentPosition() << endl;
      }
      else
      {
            cout << currentPlayer.getName() << " rolled a " << dice << " and moved from " << currentPlayer.getPreviousPosition() << " to " << currentPlayer.getCurrentPosition() << endl;
            cout << currentPlayer.getName() << " wins the game" << endl;
      }
}
int Game::rollDice()
{
      return ((rand() % 6) + 1);
}
bool Game::isSnakeBite(int &currentPosition)
{
      for (int i = 0; i < mSnakes.size(); i++)
      {
            if (mSnakes[i].getHeadPosition() == currentPosition)
            {
                  currentPosition = mSnakes[i].getTailPosition();
                  return true;
            }
      }
      return false;
}
bool Game::isLadderClimb(int &currentPosition)
{
      for (int i = 0; i < mLadders.size(); i++)
      {
            if (mLadders[i].getStartPosition() == currentPosition)
            {
                  currentPosition = mLadders[i].getEndPosition();
                  return true;
            }
      }
      return false;
}
void Game::moveBoard(Player &currentPlayer, int diceValue)
{
      int currentPlayerPreviousPosition = currentPlayer.getPreviousPosition();
      int currentPlayerCurrentPosition = currentPlayer.getCurrentPosition();
      int newPosition = currentPlayerCurrentPosition + diceValue;
      if (newPosition > BOARD_SIZE)
      {
            newPosition = currentPlayerCurrentPosition;
      }
      bool isSnakeBit = false, isLadderClimbed = false;
      do
      {
            if (isSnakeBite(newPosition))
            {
                  isSnakeBit = true;
            }
            else
            {
                  isSnakeBit = false;
            }
      } while (isSnakeBit);
      do
      {
            if (isLadderClimb(newPosition))
            {
                  isLadderClimbed = true;
            }
            else
            {
                  isLadderClimbed = false;
            }
      } while (isLadderClimbed);
      currentPlayer.setPreviousPosition(currentPlayer.getCurrentPosition());
      currentPlayer.setCurrentPosition(newPosition);
}
Game::Game(vector<pair<int, int>> snakePositions, vector<pair<int, int>> ladderPositions, vector<string> players)
{
      for (int i = 0; i < snakePositions.size(); i++)
      {
            Snake snake(snakePositions[i].first, snakePositions[i].second);
            mSnakes.push_back(snake);
      }
      for (int i = 0; i < ladderPositions.size(); i++)
      {
            Ladder ladder(ladderPositions[i].first, ladderPositions[i].second);
            mLadders.push_back(ladder);
      }
      for (int i = 0; i < players.size(); i++)
      {
            Player player(players[i]);
            mPlayers.push_back(player);
      }
      numberOfPlayers = players.size();
}

void Game::startGame()
{
      bool isGameOver = false;
      int currentPlayerId = 0, diceValue;
      while (!isGameOver)
      {
            diceValue = rollDice();
            moveBoard(mPlayers[currentPlayerId], diceValue);
            if (mPlayers[currentPlayerId].getCurrentPosition() == BOARD_SIZE)
            {
                  isGameOver = true;
                  diceRolledMessage(GAME_OVER, mPlayers[currentPlayerId], diceValue);
                  break;
            }
            else
            {
                  diceRolledMessage(GAME_NOT_OVER, mPlayers[currentPlayerId], diceValue);
            }
            currentPlayerId = (currentPlayerId + 1) % numberOfPlayers;
      }
}
