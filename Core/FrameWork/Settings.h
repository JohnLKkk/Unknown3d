#ifndef _FRAMEWORK_SETTINGS_H_
#define _FRAMEWORK_SETTINGS_H_


namespace Unknown3d
{
    /**
     * USettings用于提供各种模块的配置信息。<br/>
     * @author JohnKkk
     * @date 2022年2月19日14点26分
     */
    struct USettings
    {
        // Window
        int m_Width = 640;
        int m_Height = 480;
        const char* m_Title;
        // 是否可调整大小
        bool m_Resize = false;


        // Renderer

        // 帧率限制
        int m_FPS = 60;
        // 是否垂直同步
        bool m_Sycn = true;
        // 开启硬件MSAA
        bool m_MSAA = true;
        // 开启Gamma矫正
        bool m_Gamma = true;
        // 开启全屏独占
        bool m_FullScreen = false;
        // 预编译着色器
        bool m_PreBuildShaderCache = false;
        // Other...
    };
}

#endif

