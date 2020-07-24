#pragma once
#include <mutex>
#include <atomic>
//#include "Application_export.h"
//APPLICATION_EXPORT

class  Application
{
private:
  Application() = default;
  ~Application() = default;
  Application(const Application&) = delete;
  Application& operator=(const Application&) = delete;

  static std::atomic<Application*> m_instance;
  static std::mutex m_mutex;
  
public:
    static Application* getInstance();
    void run(void) const;
};





