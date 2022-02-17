#ifndef _TESTS_TEMPLATE_H_
#define _TESTS_TEMPLATE_H_

/**
 * ITestTemplate，用于测试样例接口，以便统一进行管理。<br/>
 * @author JohnKkk
 * @date 2022年2月17日17点35分
 */
class ITestTemplate
{
public:
    virtual int TestMain(int argc, char* argv[])=0;
};


#endif

