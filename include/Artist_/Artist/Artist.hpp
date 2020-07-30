

#pragma once
#include <vector>
#include <functional>
#include <thread>
#include <condition_variable>
#include <atomic>
#include <complex>
#include "opencv2/opencv.hpp"
//#include "Artist_export.h"
//ARTIST_EXPORT
 namespace cft{
   // !
    class Picture;
   class Artist
   {
   private:
     std::vector<std::shared_ptr<std::thread>> m_threads;
     std::unordered_map<std::thread::id,bool> areThreadsDone;
     std::shared_ptr<Picture> m_Picture;
     static std::mutex m_mutex;
     bool isDone = true;
     
   public:
     using Callback = std::function<void(std::shared_ptr<Picture>&)>;
     static std::condition_variable m_cv;
     bool areAllDone();
     Artist() = delete;
     Artist(const size_t& w,const size_t& h);
     Artist& addTask(Callback task);
     void draw(const std::string& name = "pic.png") ;
     static std::complex<double> iterateFractal(); 
     ~Artist();
   };
   
   
  inline int iterateFractal(const std::complex<double>& init, int maxIter) 
    {
        std::complex<double> Z = init;
        int cnt = 0;
        while ((((Z.real()*Z.real())+(Z.imag()*Z.real())) <= 4.f) && (cnt < maxIter))
        {
            Z = pow(Z,3);
            Z += init;
            cnt++;
        }
        return cnt;
    }
  
  struct Canvas
  {
    Canvas(const size_t& w,const size_t& h):sizeOfCanvas({w,h}),minPoint({0,0}),maxPoint({w,h}),centerPoint({w/2,h/2}){};
    const std::pair<size_t,size_t> sizeOfCanvas;
    const std::pair<size_t,size_t> minPoint;
    const std::pair<size_t,size_t> maxPoint;
    const std::pair<size_t,size_t> centerPoint;
  };
  
   class Picture
   {
   private:
     const Canvas m_canvas;
     cv::Mat m_image;
   public:
     Picture(const size_t& w,const size_t& h);
     Picture(const Picture&) = delete;
     Picture operator=(const Picture&) = delete;
     ~Picture();
     cv::Vec4b& getPixel(size_t x, size_t y);
     const Canvas getCanvas() const;
     cv::Mat& getImage();
   };
 }

