#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      banana(grid_width, grid_height, snake),
      potion(grid_width, grid_height, snake),      
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {
  //PlaceFood();
}

void Game::Run(Controller &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;
  bool _running = running;
  controller.Run(running, snake);

  while (_running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    //controller.HandleInput(running, snake);
    Update();
    
    if (snake.size>=snake.potionThreshold)
    {
      renderer.Render(snake, banana, potion);
    }
    else
    {
      renderer.Render(snake, banana);
    }
    
    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }

    std::lock_guard mutex(_controlMutex);
    _running = running;
  }
}

void Game::Update() {
  std::lock_guard<std::mutex> lock(_snakeMutex);
  if (!snake.alive) return;

  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's food over here
  if (banana.GetX() == new_x && banana.GetY() == new_y) {
    score++;
    banana.Eaten(snake);
    
  }

  if (potion.GetX() == new_x && potion.GetY() == new_y) {
    score++;
    potion.Eaten(snake);
  }
  
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }