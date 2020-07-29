// Includes
#include <iostream>
#if defined(PROJECT_VERSION_DEFINITIONED)
#include "ver.h"
#endif  // PROJECT_VERSION_DEFINITIONED
#include <opencv2/opencv.hpp>
#include "Application/Application.hpp"


int main()
{
#if defined(PROJECT_VERSION_DEFINITIONED)
  std::cout << "Project version is :" << ver << '\n';
#endif  // PROJECT_VERSION_DEFINITIONED

  //cv::Mat my_mat(32000,18000,CV_8UC4);
  //std::cout << my_mat.rows << " and " << my_mat.cols << '\n';
  /*for (size_t i = 0; i < my_mat.rows; i++)
  {
    for (size_t j = 0; j < my_mat.cols; j++)
    {
        my_mat.at<cv::Vec4b>(i,j) = cv::Vec4b(atan2((sin(2*3.14*(10*(my_mat.rows-i)/my_mat.rows)*(my_mat.rows-i)/my_mat.rows)),(cos(2*3.14*(10*j/my_mat.cols)*j/my_mat.cols)))*255,
                                              atan2((sin(2*3.14*(10*(my_mat.cols-j)/my_mat.cols)*(my_mat.cols-j)/my_mat.cols)),(cos(2*3.14*(10*i/my_mat.rows)*i/my_mat.rows)))*255,
                                              (atan2((2*3.14*(10*(my_mat.rows-i)/my_mat.rows)*(my_mat.rows-i)/my_mat.rows),(2*3.14*(10*(my_mat.cols-j)/my_mat.cols)*(my_mat.cols-j)/my_mat.cols)))*255,
                                              (static_cast<float>((i*my_mat.cols)*(j*my_mat.rows))/(my_mat.cols*my_mat.rows))*255);
    }
  }*/
  
  //cv::imwrite("resim.png",my_mat);
  try
  {
    Application::getInstance()->run();
    
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;

}
