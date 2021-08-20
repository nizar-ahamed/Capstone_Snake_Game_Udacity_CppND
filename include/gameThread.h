#ifndef GAMETHREAD_H
#define GAMETHREAD_H

#include <vector>
#include <thread>
#include <mutex>

class GameThread{
  public:
    ~GameThread();
  protected:
    std::vector<std::thread> _threads;
    static std::mutex _controlMutex;
    static std::mutex _snakeMutex;
};

#endif