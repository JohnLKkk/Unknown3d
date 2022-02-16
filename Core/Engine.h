#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "FrameWork/Include.h"
#include "Math3d/Include.h"
#include "Scene/Include.h"


class IEngine
{
public:
 ~IEngine() = default;
    /**
     * 初始化引擎，根据指定参数（通常是命令行参数）进行调试配置。<br/>
     * @param args
     * @param argr
     * @return 初始化成功返回true。
     */
    virtual bool init(int args, char* argr[])=0;

    /**
     * 执行launch后，Engine实例将进入指定的线程中，知道终止。<br/>
     */
    virtual void launch()=0;

    /**
     * 在Engine运行过程中，根据配置情况将在世界时间或游戏时间不断调用onTick。<br/>
     */
    virtual void onTick()=0;

    /**
     * 在Engine终止之前回调，以便进行收尾工作。<br/>
     * @return 成功返回true。
     */
    virtual bool onTerminal()=0;
};

class UEngine:public IEngine
{
protected:
    // 上一帧消耗时间(ms)
    float m_LastTPF = .0F;
public:
    ~UEngine() = default;
    bool init(int args, char* argr[]) override;
    void launch() override;
    void onTick() override;
    bool onTerminal() override;
public:
 
};


/**
 * 引擎启动入口,由跨平台启动函数调用。<br/>
 * @param argc
 * @param argv
 */
int EngineMain(int argc, char* argv[]);

#endif

