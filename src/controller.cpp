#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

void Controller::Run(bool &running, Snake &snake) {
  _threads.emplace_back(std::thread(&Controller::HandleInput, this, std::ref(running), std::ref(snake)));
}

void Controller::ChangeDirection(Snake &snake, Snake::Direction input,
                                 Snake::Direction opposite) const {
  std::lock_guard mutex(_snakeMutex);
  if (snake.direction != opposite || snake.size == 1) snake.direction = input;
  return;
}

void Controller::HandleInput(bool &running, Snake &snake) const {
  SDL_Event e;
  std::unique_lock mutex(_controlMutex);
  bool _running = running;
  mutex.unlock();
  while(_running)
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) {
        _running = false;
        mutex.lock();
        running = _running;
        mutex.unlock();
      } else if (e.type == SDL_KEYDOWN) {
        switch (e.key.keysym.sym) {
          case SDLK_UP:
            ChangeDirection(snake, Snake::Direction::kUp,
                            Snake::Direction::kDown);
            break;

          case SDLK_DOWN:
            ChangeDirection(snake, Snake::Direction::kDown,
                            Snake::Direction::kUp);
            break;

          case SDLK_LEFT:
            ChangeDirection(snake, Snake::Direction::kLeft,
                            Snake::Direction::kRight);
            break;

          case SDLK_RIGHT:
            ChangeDirection(snake, Snake::Direction::kRight,
                            Snake::Direction::kLeft);
            break;
        }
      }
    }
  }
}