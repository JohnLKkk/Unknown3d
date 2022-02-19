#include <iostream>

#include "Engine.h"

/**
 * 用户自定义的Application。<br/>
 */
class MyApplication : public Unknown3d::UBaseApplication
{
protected:
    void onInit() override;
    void onStart() override;
    void onUpdate(float tpf) override;
    void onDestroy() override;
public:
    
};

void MyApplication::onInit()
{
    // 设置窗口信息
    m_Setting.m_Title = "Test!";
    m_Setting.m_Width = 640;
    m_Setting.m_Height = 480;
    UBaseApplication::onInit();
}

void MyApplication::onStart()
{
    UBaseApplication::onStart();


    // 获取scene
    // 然后添加用户自己的模型数据，材质等等操作
}

void MyApplication::onUpdate(float tpf)
{
    UBaseApplication::onUpdate(tpf);


    // 用户自己需要在整个Application生命周期下onUpdate事件做的逻辑
    // 也可通过控制器更新对应Node,Geometry
    // 这里更像是Application生命周期提供给用户每一帧调度的app更新操作
    std::cout << "tpf:" << tpf << std::endl;
}

void MyApplication::onDestroy()
{
    UBaseApplication::onDestroy();

    // 用户自己的销毁工作
}


/**
 * 作为现阶段的临时测试入口<br/>
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char* argv[])
{
    // 创建一个Application
    Unknown3d::IApplication * application = nullptr;
    application = new MyApplication();
    // 启动
    application->launch();
    return 0;
}
