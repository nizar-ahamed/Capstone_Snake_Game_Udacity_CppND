#ifndef BANANA_H
#define BANANA_H

#include "SDL.h"
#include "food.h"
#include "snake.h"

class Banana : public Food {
 public:
  Banana(int grid_width, int grid_height, Snake snake) : Food(grid_width, grid_height, snake){} 

  virtual void Eaten(Snake &snake);

};

#endif