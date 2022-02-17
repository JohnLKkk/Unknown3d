#include <iostream>

#include "Engine.h"
#include "FrameWork/Application.h"
#include "Tests/Math3d/TestVector.h"

/**
 * 作为现阶段的临时测试入口。<br/>
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char* argv[])
{
    // return EngineMain(argc, argv);

    ITestTemplate * test = nullptr;
    test = new UTestVector();

    int code = 0;
    try
    {
        code = test->TestMain(argc, argv);
        delete test;
    }
    catch (std::exception & exception)
    {
        std::cout << exception.what() << std::endl;
        delete test;
    }
    return code;
}
