#include "Engine.h"
#include <exception>
#include <cstdlib>
#include <stdexcept>

#include <vcruntime.h>

bool UEngine::init(int args, char* argr[])
{
}

void UEngine::launch()
{
}

void UEngine::onTick()
{
}

bool UEngine::onTerminal()
{
}

IEngine *S_IEngine(NULL);


int EngineMain(int argc, char* argv[])
{
    S_IEngine = new UEngine();
    if(!S_IEngine->init(argc, argv))
    {
        throw std::runtime_error("无法初始化Engine!");
    }

    // launch Engine
    S_IEngine->launch();

    // 获取一个线程,然后分配给引擎,这里使用主线程
    // 下面只是一段未封装的代码,不应该为while(true)
    while(true)
    {
        // 在onTick中，Engine会根据配置情况不断计算tpf(每帧消耗时间)
        S_IEngine->onTick();

        // 其他
    }

    // final
    if(!S_IEngine->onTerminal())
    {
        throw std::runtime_error("无法终止Engine!");
    }
    
    return 0;
}