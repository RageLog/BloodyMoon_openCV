// Includes
#include <iostream>
#if defined(PROJECT_VERSION_DEFINITIONED)
#include "ver.h"
#endif  // PROJECT_VERSION_DEFINITIONED

#include "Application/Application.hpp"


int main(/*int argc, char *argv[]*/)
{
#if defined(PROJECT_VERSION_DEFINITIONED)
  std::cout << "Project version is :" << ver << '\n';
#endif  // PROJECT_VERSION_DEFINITIONED


  try
  {
    Application::getInstance()->run();
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    return EXIT_FAILURE;
  }
}
