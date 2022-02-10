#ifndef _MATH3D_VECTOR3_H_
#define _MATH3D_VECTOR3_H_
#include "Math.h"

namespace Unknown3d
{
    /**
     * Vector3。
     * @author JohnKkk
     * @date 2022年2月10日12点23分
     * @update 2022年2月10日12点54分
     */
    template<typename T>
    class UVector3:public UVECTOR<UVector3, T>
    {
    public:
        static constexpr const size_t S_SIZE;
        UVector3(): m_V{}, x(), y(), z(), r(), g(), b(), u(), v(), w()
        {
        }

        // 同时提供数组与分量检索操作
        union
        {
            T m_V[S_SIZE];
            T x, y, z;
            T r, g, b;
            T u, v, w;
        };

        inline constexpr T const& operator[](int i)const noexcept
        {
            static_assert(i < S_SIZE);
            return m_V[i];
        }
    
        inline constexpr T& operator[](int i)noexcept
        {
            static_assert(i < S_SIZE);
            return m_V[i];
        }
    };
}

#endif



