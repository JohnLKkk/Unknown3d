#ifndef _FRAMEWORK_APPLICATION_H_
#define _FRAMEWORK_APPLICATION_H_
#include <cstddef>
#include <string>

#include "Settings.h"
#include "../Window/IWindow.h"
#include "../Device/IDevice.h"

namespace Unknown3d
{
    /**
     * IApplication是一个基础FrameWorkd。<br/>
     * @author JohnKkk
     * @date 2022年2月10日18点24分
     */
    class IApplication
    {
    protected:
        //-----------------------Application生命周期----------------------------
        virtual void onInit()=0;
        virtual void onStart()=0;
        virtual void onUpdate(float tpf)=0;
        virtual void onDestroy()=0;
        //-----------------------Application生命周期----------------------------
    public:
        /**
         * 启动Application。<br/>
         */
        virtual void launch()=0;
    };

    /**
     * UBaseApplication应该是所有应用的直接父类。<br/>
     * @author JohnKkk
     * @date 2022年2月10日18点26分
     */
    class UBaseApplication: public IApplication
    {
    protected:
        // 应用配置
        USettings m_Setting;
        
        // IWindow(跨平台抽象窗口)
        Unknown3d::IWindow *m_IWindow = nullptr;
		// IDevice(图形渲染)
		Unknown3d::IDevice *m_IDevice = nullptr;
        
        void onInit() override;
        void onStart() override;
        void onUpdate(float tpf) override;
        void onDestroy() override;
    public:
        UBaseApplication():IApplication()
        {
            m_Setting.m_Title = "Unknown3d";
        }
        void launch() override;
    };
}


#endif



