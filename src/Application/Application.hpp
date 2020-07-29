#pragma once
#include <mutex>
#include <atomic>
#include "Artist/Artist.hpp"
//#include "Application_export.h"
//APPLICATION_EXPORT

class  Application
{
private:
  Application()
  {
  };
  ~Application(){};
  Application(const Application&) = delete;
  Application& operator=(const Application&) = delete;

  static std::atomic<Application*> m_instance;
  static std::mutex m_mutex;
  void assingTask();
public:
    static Application* getInstance();
    void run(void);
    
};













