#ifndef _MATH3D_TRANSFORM_H_
#define _MATH3D_TRANSFORM_H_
#include "Matrix4.h"
#include "Vector3.h"

namespace Unknown3d
{
    /**
     * Transform表示变换组件，包含Translation，Rotation，Scale。<br/>
     * @author JohnKkk
     * @date 2022年2月16日17点09分
     */
    class UTransform
    {
    public:
        UVector3<float> m_Translation{1.0f};
        UVector3<float> m_Scale{1.0f};
        UMatrix4<float> m_Rotation;
    };
}

#endif
