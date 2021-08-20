#ifndef GAME_H
#define GAME_H

#include <random>
#include <thread>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "banana.h"
#include "potion.h"
#include "gameThread.h"

class Game : GameThread {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;

 private:
  Snake snake;
  //SDL_Point food;
  Banana banana;
  Potion potion;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};

  // void PlaceFood();
  void Update();
};

#endif