#ifndef _WINDOW_WINDOW_MGR_H_
#define _WINDOW_WINDOW_MGR_H_
#include "IWindow.h"
#include "../FrameWork/Settings.h"

namespace Unknown3d
{
    /**
     * @author
     * @date 
     */
    class WindowMgr
    {
        WindowMgr();
        ~WindowMgr();
    public:
        static WindowMgr& Instance();
        
        IWindow* createPlatformWindow(USettings &settings);
        void onUpdate();


        IWindow* getWindowIns() const { return _m_window_ins; }
    private:
        IWindow* _m_window_ins;
    };
}

#endif
