#include "food.h"

void Food::Place(Snake snake)
{
  int x, y;
  while (true) {
    // Randomly select x and y of food
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
        Food::location.x = x;
        Food::location.y = y;
    return;
    }
  }
}