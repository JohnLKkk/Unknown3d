#ifndef _SCENE_SCENE_H_
#define _SCENE_SCENE_H_
#include <vector>
#include <string>

namespace Unknown3d
{
    /**
     * USpatial表示场景中任意的对象。
     * @author JohnKkk
     * @date 2022年2月10日14点22分
     */
    class USpatial
    {
    protected:
        // id
        std::string m_Id;
    public:
        USpatial(const char *const id = ""):m_Id(id){}
    };

    /**
     * UNode表示场景中可变换的对象。
     * @author JohnKkk
     * @date 2022年2月10日14点22分
     */
    using std::vector;
    class UNode : public USpatial
    {
    public:
        
    protected:
        // 子节点
        vector<UNode*> m_Childrens;
    };

    /**
     * UScene表示一个世界场景,托管渲染实例表示的场景,并由<br/>
     * @author JohnKkk
     */
    class UScene
    {
    public:
        
    };
}


#endif



