#include "./Application/Application.hpp"




std::atomic<Application*> Application::m_instance;
std::mutex Application::m_mutex;
using namespace std::complex_literals;



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



void Application::run(void)
{
  cft::Artist m_artist(32000,18000);
  auto t_count = std::thread::hardware_concurrency();
  
  for (size_t sayi = 0; sayi < t_count; sayi++)
  {
     m_artist.addTask([=](std::shared_ptr<cft::Picture>& m_pic){
       double n_i,n_j;  
        int color;
      for (size_t i = 0; i < m_pic->getImage().rows; i++)
      {
        for (size_t j = sayi ; j < m_pic->getImage().cols; j+=t_count)
        {
          n_i = static_cast<double>(i)/m_pic->getImage().rows;
          n_j = static_cast<double>(j)/m_pic->getImage().cols;
          color =cft::iterateFractal(n_i+(n_j*1i),255);
          if ((sqrt(pow((m_pic->getCanvas().centerPoint.first-i),2)+pow(m_pic->getCanvas().centerPoint.second-j,2))) <= (9000))
          {
            // ?(((static_cast<double>(i*i)/(n_i*n_i))+(static_cast<double>(j*j)/(n_i*n_i)))/(2))*255
            if(color<5) m_pic->getPixel(i,j) = cv::Vec4b(0,0,color*5,255);
            else if(color<10) m_pic->getPixel(i,j) = cv::Vec4b(0,0,color*5,255);
            else if(color<15) m_pic->getPixel(i,j) = cv::Vec4b(0,0,color*5,255);
            else if(color<20) m_pic->getPixel(i,j) = cv::Vec4b(0,0,color*5,255);			
            else if(color<30) m_pic->getPixel(i,j) = cv::Vec4b(0,0,color*5,255);
            else if(color<45) m_pic->getPixel(i,j) = cv::Vec4b(0,0,color*5,255);
            else m_pic->getPixel(i,j) = cv::Vec4b(0,0,color*5,255);
          }
          else if ((sqrt(pow((i-m_pic->getCanvas().centerPoint.first),2)+pow(j-m_pic->getCanvas().centerPoint.second,2))) <= (9000))
          {
            if(color<5) m_pic->getPixel(i,j) = cv::Vec4b(0,0,color*5,255);
            else if(color<10) m_pic->getPixel(i,j) = cv::Vec4b(0,0,color*5,255);
            else if(color<15) m_pic->getPixel(i,j) = cv::Vec4b(0,0,color*5,255);
            else if(color<20) m_pic->getPixel(i,j) = cv::Vec4b(0,0,color*5,255);			
            else if(color<30) m_pic->getPixel(i,j) = cv::Vec4b(0,0,color*5,255);
            else if(color<45) m_pic->getPixel(i,j) = cv::Vec4b(0,0,color*5,255);
            else m_pic->getPixel(i,j) = cv::Vec4b(0,0,color*5,255);          
          }
          else if ((sqrt(pow((m_pic->getCanvas().centerPoint.first-i),2)+pow(j-m_pic->getCanvas().centerPoint.second,2))) <= (9000))
          {
            if(color<5) m_pic->getPixel(i,j) = cv::Vec4b(0,0,color*5,255);
            else if(color<10) m_pic->getPixel(i,j) = cv::Vec4b(0,0,color*5,255);
            else if(color<15) m_pic->getPixel(i,j) = cv::Vec4b(0,0,color*5,255);
            else if(color<20) m_pic->getPixel(i,j) = cv::Vec4b(0,0,color*5,255);			
            else if(color<30) m_pic->getPixel(i,j) = cv::Vec4b(0,0,color*5,255);
            else if(color<45) m_pic->getPixel(i,j) = cv::Vec4b(0,0,color*5,255);
            else m_pic->getPixel(i,j) = cv::Vec4b(0,0,color*5,255);
          }
          else if ((sqrt(pow((i-m_pic->getCanvas().centerPoint.first),2)+pow(m_pic->getCanvas().centerPoint.second-j,2))) <= (9000))
          {
            if(color<5) m_pic->getPixel(i,j) = cv::Vec4b(0,0,color*5,255);
            else if(color<10) m_pic->getPixel(i,j) = cv::Vec4b(0,0,color*5,255);
            else if(color<15) m_pic->getPixel(i,j) = cv::Vec4b(0,0,color*5,255);
            else if(color<20) m_pic->getPixel(i,j) = cv::Vec4b(0,0,color*5,255);			
            else if(color<30) m_pic->getPixel(i,j) = cv::Vec4b(0,0,color*5,255);
            else if(color<45) m_pic->getPixel(i,j) = cv::Vec4b(0,0,color*5,255);
            else m_pic->getPixel(i,j) = cv::Vec4b(0,0,color*5,255);
          }
          else
          {
            if((pow(cos((3.14/2)*n_i),2)+pow(sin((3.14/2)*n_j),2)) <= 1)
            {
              m_pic->getPixel(i,j) = cv::Vec4b(
              cos((3.14/2)*static_cast<double>(m_pic->getImage().rows-i)/m_pic->getImage().rows)*255,
              (1-sin((3.14/2)*static_cast<double>(m_pic->getImage().cols-j)/m_pic->getImage().cols))*255,
              255,
              255);

            }
            else
            {
              m_pic->getPixel(i,j) = cv::Vec4b(
              cos((3.14/2)*static_cast<double>(m_pic->getImage().rows-i)/m_pic->getImage().rows)*255,
              (1-sin((3.14/2)*static_cast<double>(m_pic->getImage().cols-j)/m_pic->getImage().cols))*255,
              255,
              255);
            }
          }
          
          
        }
      }    
    });
  }
  
 


  m_artist.draw();

}