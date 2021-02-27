#include "./Artist/Artist.hpp"

namespace cft
{   
    std::mutex Artist::m_mutex;
    std::condition_variable Artist::m_cv;
    // ! Artist
    Artist::Artist(const size_t& w,const size_t& h)
    :m_Picture(std::make_shared<Picture>(w,h))
    {
    }
    Artist& Artist::addTask(Callback task) 
    {
        m_threads.push_back(std::make_unique<std::thread>([&,this,task](){
            m_cv.notify_one(); 
            task(m_Picture);
            std::unique_lock<std::mutex> m_unique_lock(m_mutex);
            this->areThreadsDone[std::this_thread::get_id()] = true;
            m_unique_lock.unlock();
            m_cv.notify_one();
        }));
        return *this;
    }
    
    bool Artist::areAllDone() 
    {
        bool stiation = true;
        for (auto &&i : m_threads)
        {
           stiation = stiation & this->areThreadsDone[i->get_id()];
        }
        return stiation;
    }
    
    void Artist::draw(const std::string& name) 
    {
        std::unique_lock<std::mutex> m_unique_lock(m_mutex);
        m_cv.wait(m_unique_lock,[&,this]{return areAllDone(); });
        cv::imwrite(name,m_Picture->getImage());
        isDone = false;
    }
    
    Artist::~Artist()
    {
    };

    // ! Picture
    Picture::Picture(const size_t& w,const size_t& h):m_canvas({w,h}),m_image(std::move(cv::Mat(w,h,CV_8UC4))){}
    Picture::~Picture(){}
    cv::Vec4b& Picture::getPixel(size_t x, size_t y) 
    {
        return this->m_image.at<cv::Vec4b>(x,y);
    }
    const Canvas Picture::getCanvas() const
    {
        return this->m_canvas;
    }
    cv::Mat& Picture::getImage() 
    {   
        return this->m_image;
    }

}
