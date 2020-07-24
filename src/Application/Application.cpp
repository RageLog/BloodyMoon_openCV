#include "./Application/Application.hpp"


std::atomic<Application*> Application::m_instance;
std::mutex Application::m_mutex;

Application* Application::getInstance()
{
  Application* instance = m_instance.load(std::memory_order_acquire);
  if (!instance)
  {
    std::lock_guard<std::mutex> m_Lock(m_mutex);
    instance = m_instance.load(std::memory_order_relaxed);
    if (!instance)
    {
      instance = new Application();
      m_instance.store(instance, std::memory_order_release);
    }
  }
  return instance;
}

void Application::run(void) const
{
  
}