#ifndef _SCENE_GEOMETRY_H_
#define _SCENE_GEOMETRY_H_
#include "Scene.h"
#include "../Mesh/BufDescriptor.h"


namespace Unknown3d
{
    /**
     * Geometry表示空间中一个可渲染的实例节点，其几何信息由Mesh提供，材质信息由Material决定。<br/>
     * @author JohnKkk
     * @date 2022年2月16日18点45分
     */
    class UGeometry : public UNode
    {
    private:
        // mesh数据
        Unknonw3d::UMesh *_m_Mesh;
        // 材质(待补充),暂时绘制纯色mesh
    public:
    
    };
}

#endif
