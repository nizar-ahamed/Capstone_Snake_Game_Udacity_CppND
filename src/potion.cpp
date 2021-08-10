#include "potion.h"

void Potion::Eaten(Snake &snake)
{
  // Shrink snake body and increase speed by twice that of banana
  snake.ShrinkBody();
  snake.speed += 0.04;

  // Place new potion
  if (snake.size>snake.potionThreshold)
  {
    Potion::Place(snake);
  }
}