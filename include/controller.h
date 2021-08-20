#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"
#include "gameThread.h"
#include <thread>

class Controller : public GameThread {
 public:
  
  void Run(bool &running, Snake &snake);

 private:
  void ChangeDirection(Snake &snake, Snake::Direction input,
                       Snake::Direction opposite) const;
  void HandleInput(bool &running, Snake &snake) const;

};

#endif