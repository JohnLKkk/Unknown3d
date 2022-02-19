#ifndef _WINDOW_WIN32WINDOW_H_
#define _WINDOW_WIN32WINDOW_H_
#include "IWindow.h"

namespace Unknown3d
{
    #include<glfw/include/glfw3.h>

    /**
     * @author
     * @date 
     */
    class Win32Window : public IWindow
    {
    public:
        /**
        * 创建窗口。<br/>
        * @param
        */
        virtual void createWindow(int width = 640, int height = 480, const char* = "Unknow3d", bool resize = false) override;
        /**
        * 销毁窗口。<br/>
        * @param
        */
        virtual void destroyWindow() override;
        /**
        * 窗口update<br/>
        * @return int
        */
        virtual void onUpdate() override;
    protected:
    private:
        GLFWwindow* _m_window;
    };
}


#endif
