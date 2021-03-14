#include <iostream>

using namespace std;

class Snake
{
private:
      int mHeadPosition, mTailPosition;

public:
      Snake();
      Snake(int headPosition, int tailPosition);
      int getHeadPosition();
      int getTailPosition();
      void setHeadPosition(int headPosition);
      void setTailPosition(int tailPosition);
};
Snake::Snake()
{
}
Snake::Snake(int headPosition, int tailPosition)
{
      mHeadPosition = headPosition;
      mTailPosition = tailPosition;
}

int Snake::getHeadPosition()
{
      return mHeadPosition;
}

int Snake::getTailPosition()
{
      return mTailPosition;
}

void Snake::setHeadPosition(int headPosition)
{
      mHeadPosition = headPosition;
}

void Snake::setTailPosition(int tailPosition)
{
      mTailPosition = tailPosition;
}