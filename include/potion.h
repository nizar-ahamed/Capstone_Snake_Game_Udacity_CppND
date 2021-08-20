#ifndef POTION_H
#define POTION_H

#include "SDL.h"
#include "food.h"
#include "snake.h"

class Potion : public Food {
 public:
  Potion(int grid_width, int grid_height, Snake snake) : Food(grid_width, grid_height, snake){} 

  virtual void Eaten(Snake &snake) override;

};

#endif