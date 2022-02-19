#ifndef _WINDOW_IWINDOW_H_
#define _WINDOW_IWINDOW_H_

namespace Unknown3d
{
    /**
     * @author 粉哥
     * @date 
     */
    class IWindow
    {
    public:
        /**
        * 默认构造函数<br/>
        */
        IWindow();
        /**
        * 默认析构函数<br/>
        */
        virtual ~IWindow();

        /**
        * 创建窗口<br/>
        * @param
        */
        virtual void createWindow(int width = 640, int height = 480, const char* = "Unknow3d", bool resize = false) = 0;
        /**
        * 销毁窗口<br/>
        * @param
        */
        virtual void destroyWindow() = 0;
        /**
        * 窗口update<br/>
        * @return int
        */
        virtual void onUpdate() = 0;
        /**
        * 设置窗口宽<br/>
        * @return
        */
        void setWidth(int width)
        {
            _m_width = width;
        }
        /**
        * 设置窗口高<br/>
        * @return
        */
        void setHeight(int height)
        {
            _m_height = height;
        }
        /**
        * 获取窗口宽<br/>
        * @return int
        */
        int getWidth()const { return _m_width; }
        /**
        * 获取窗口高<br/>
        * @return int
        */
        int getHeight()const { return _m_height; }
	
    protected:
	
    private:
        int _m_width;
        int _m_height;
    };
}


#endif


