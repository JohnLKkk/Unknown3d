#include "Application.h"

#include <chrono>
#include <stdexcept>

#include "../Window/WindowMgr.h"
#include <Windows.h>

void Unknown3d::UBaseApplication::onInit()
{
    // 创建并检查所有模块是否正常
    
    // create window
    m_IWindow = WindowMgr::Instance().createPlatformWindow(m_Setting);
    // 检查跨平台窗口是否正常创建
    if(!m_IWindow)
    {
        throw std::runtime_error("create Window error,Line:" + __LINE__);
    }

    // 创建renderer

    // 创建inputManager

    // 其他...


    // 所有资源创建完毕!
}

void Unknown3d::UBaseApplication::onStart()
{
    // 一些预处理工作
    // ...
}

void Unknown3d::UBaseApplication::onUpdate(float tpf)
{
    // 更新所有模块
    m_IWindow->onUpdate();

    // inputManager.onUpdate()
    
    // renderer.onRender(tpf)
    // renderer.onUpdate(tpf)

    // 可能还有其他模块,比如物理引擎
}

void Unknown3d::UBaseApplication::onDestroy()
{
    // 销毁工作
}

/**
 * 用于跨平台时间获取。<br/>
 */
double getCurrentTime()
{
    // 暂时使用Window下时间计算
    return GetTickCount();;
}

void Unknown3d::UBaseApplication::launch()
{
    // 首先初始化所有模块
    onInit();
    // 进入application生命周期
    // 第一步回调onStart...
    onStart();

    // 进入onUpdate...
    // 计算tps
    float tpf = 0;
    
    auto currentTime = getCurrentTime();
    auto time = getCurrentTime();
    while(true)
    {
        time = getCurrentTime();
        tpf = (time - currentTime) / 1000.0f;
        currentTime = time;
        onUpdate(tpf);
    }

    // application销毁
    onDestroy();
}
