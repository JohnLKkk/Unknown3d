#ifndef _SCENE_SCENE_H_
#define _SCENE_SCENE_H_
#include <vector>
#include <string>

#include "../Math3d/Transform.h"

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
    protected:
        // 局部变换
        UTransform m_LocalTransform;
        // 世界变换
        UTransform m_WorldTransform;
        // 记录是否更新对应变换组件
        bool _m_UpdateLocalTransform = false;
        bool _m_UpdateWorldTransform = false;
        // 子节点
        vector<UNode*> m_Childrens;
        // 父节点
        UNode* m_Parent = nullptr;
    public:
        /**
         * 添加一个子节点。<br/>
         */
        void attachChildren(UNode * childre);
        
        /**
         * 返回当前节点的所有子节点。<br/>
         * @return 
         */
        const vector<UNode*>&const getChildrens()const
        {
            return m_Childrens;
        }

        /**
         * 返回当前节点的所有子节点。<br/>
         * @return 
         */
        vector<UNode*>& getChildrens()
        {
            return m_Childrens;
        }

        /**
         * 返回指定索引的节点。<br/>
         * @return 
         */
        const UNode* const getChildren(uint32_t i)const
        {
            static_assert(i < m_Childrens.size());
            return m_Childrens[i];
        }
        
        /**
         * 返回指定索引的节点。<br/>
         * @return 
         */
        UNode* getChildren(uint32_t i)
        {
            static_assert(i < m_Childrens.size());
            return m_Childrens[i];
        }

        /**
         * 返回当前节点的父节点。<br/>
         * @return 
         */
        const UNode* const getParent()const
        {
            return m_Parent;
        }
        
        /**
         * 返回当前节点的父节点。<br/>
         * @return 
         */
        UNode* const getParent()
        {
            return m_Parent;
        }
    private:
        /**
         * 更新本地变换。<br/>
         */
        void updateLocalTransform();
        
        /**
         * 更新世界变换。<br/>
         */
        void updateWorldTransform();
        
        /**
         * 计算世界变换。<br/>
         */
        void _calcWorldMatrix();
    public:
        /**
         * 返回本地变换。<br/>
         */
        UTransform& getLocalTransform();

        /**
         * 返回世界变换。<br/>
         */
        UTransform& getWorldTransform();
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



