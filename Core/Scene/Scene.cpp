#include "Scene.h"

void Unknown3d::UNode::attachChildren(UNode* childre)
{
    // 判断是否已经添加过
}

void Unknown3d::UNode::updateLocalTransform()
{
    _m_UpdateLocalTransform = true;
    // 更新世界变换。<br/>
    updateWorldTransform();
    // 更新其他信息
    if(m_Parent)
    {
        // 更新父节点其他信息
    }
}

void Unknown3d::UNode::updateWorldTransform()
{
    _m_UpdateWorldTransform = true;
    // 更新所有子节点
    for (auto children : m_Childrens)
    {
        children->updateLocalTransform();
    }
}

void Unknown3d::UNode::_calcWorldMatrix()
{
    // 仅在需要时进行计算,可以减少大量多余的变换计算
    if(_m_UpdateWorldTransform)
    {
        // 计算本地变换
        auto localTransform = getLocalTransform();
        // 计算世界变换
        if(m_Parent)
        {
            // 合并父节点变换
            // 待补充这里的逻辑
            // todo: m_Parent.getWorldTransform() mergeTo localTransform => worldTransform
        }
        else
        {
            // 说明这是叶子节点,直接复制localTransform->worldTransform
            // 注意不要直接应用,需要进行复制,因为worldTransform是最终计算的值
            // 待补充transform具体实现
        }
        _m_UpdateWorldTransform = false;
    }
}

Unknown3d::UTransform& Unknown3d::UNode::getLocalTransform()
{
    // 仅在需要时更新,而不是每帧更新
    if(_m_UpdateLocalTransform)
    {
        _m_UpdateLocalTransform = false;
    }
    return m_LocalTransform;
}

Unknown3d::UTransform& Unknown3d::UNode::getWorldTransform()
{
    // 仅在需要时更新,而不是每帧更新
    if(_m_UpdateWorldTransform)
    {
        _m_UpdateWorldTransform = false;
        _calcWorldMatrix();
    }
    return m_WorldTransform;
}
