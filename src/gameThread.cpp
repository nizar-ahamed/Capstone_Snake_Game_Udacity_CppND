#include"gameThread.h"
#include <algorithm>

std::mutex GameThread::_controlMutex;
std::mutex GameThread::_snakeMutex;

GameThread::~GameThread(){
  // Join all threads
  std::for_each(_threads.begin(), _threads.end(), [](std::thread &t)
  {
    t.join();
  });
}