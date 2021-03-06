#ifndef _MATH3D_VECTOR3_H_
#define _MATH3D_VECTOR3_H_
#include "Math.h"

namespace Unknown3d
{
    /**
     * Vector3。
     * @author JohnKkk
     * @date 2022年2月10日12点23分
     * @update 2022年2月16日12点16分
     */
    template<typename T>
    class UVector3:public UVECTOR<UVector3, T>
    {
    public:
        static constexpr const size_t S_SIZE = 3;
        static size_t getSize(){return S_SIZE;};

        // 同时提供数组与分量检索操作
        union
        {
            T m_V[S_SIZE];
            T x, y, z;
            T r, g, b;
            T u, v, w;
        };

        template<typename G>
        UVector3(G v): m_V{T(v), T(v), T(v)}
        {
        }

        template<typename U, typename V, typename W>
        UVector3(U x, V y, W z):m_V{T(x), T(y), T(z)}
        {
        }

        template<typename G>
        UVector3(UVector3<G> & tag):m_V{T(tag[0]), T(tag[1]), T(tag[2])}
        {
        }

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

        /**
         * c = cross(a, b)。<br/>
         * @param a
         * @param b
         * @return c 返回axb的结果。
         */
        template<typename G>
        friend inline
        UVector3<CLASS<T, G>> cross(const UVector3& a, const UVector3& b)
        {
            return {
                a[1] * b[2] - a[2] * b[1],
                a[2] * b[0] - a[0] * b[2],
                a[0] * b[1] - a[1] * b[0]
            };
        }

        /**
         * c = this.cross(b)。<br/>
         * @param b
         * @return c 返回this x b的结果。
         */
        template<typename G>
        UVector3<CLASS<T, G>> cross(const UVector3& b)
        {
            return {
                this[1] * b[2] - this[2] * b[1],
                this[2] * b[0] - this[0] * b[2],
                this[0] * b[1] - this[1] * b[0]
            };
        }
    };
}

#endif



