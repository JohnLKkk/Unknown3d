#ifndef _FRAMEWORK_APPLICATION_H_
#define _FRAMEWORK_APPLICATION_H_

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
        virtual void onInit()=0;
        virtual void onStart()=0;
        virtual void onUpdate()=0;
        virtual void onDestory()=0;
    };

    /**
     * UBaseApplication应该是所有应用的直接父类。<br/>
     * @author JohnKkk
     * @date 2022年2月10日18点26分
     */
    class UBaseApplication: public IApplication
    {
    public:
        
    };
}


#endif



