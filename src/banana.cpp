#include "banana.h"

void Banana::Eaten(Snake &snake)
{
  // Grow snake and increase speed.
  snake.GrowBody();
  snake.speed += 0.02;
  
  // Place banana in a new posiion
  Banana::Place(snake);
}