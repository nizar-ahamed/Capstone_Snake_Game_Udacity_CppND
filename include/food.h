#ifndef FOOD_H
#define FOOD_H

#include <random>
#include "SDL.h"
#include "snake.h"

class Food {
 public:
  Food(int grid_width, int grid_height, Snake snake)
      : grid_width(grid_width),
        grid_height(grid_height), 
        engine(dev()),
        random_w(0, static_cast<int>(grid_width - 1)),
        random_h(0, static_cast<int>(grid_height - 1)){Place(snake);}

  virtual void Eaten(Snake &snake) = 0;
  int GetX() const {return location.x;}
  int GetY() const {return location.y;}

 protected:
  void Place(Snake snake);

  SDL_Point location;
  int grid_width;
  int grid_height;
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;
};

#endif