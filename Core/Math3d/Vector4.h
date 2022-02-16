#ifndef _MATH3D_VECTOR4_H_
#define _MATH3D_VECTOR4_H_
#include "Math.h"
#include "Vector3.h"


namespace Unknown3d
{
    /**
     * Vector4。<br/>
     * @author JohnKk
     * @date 2022年2月16日12点21分
     * @update 2022年2月16日16点52分
     */
    template<typename T>
    class UVector4 : public UVECTOR<UVector4, T>
    {
    public:
        static constexpr const size_t S_SIZE = 4;
        static size_t getSize(){return S_SIZE;};

        // 同时提供数组与分量检索操作
        union
        {
            T m_V[S_SIZE];
            T x, y, z, w;
            T r, g, b, a;
            T u, v, w, n;
        };

        template<typename G>
        UVector4(G v): m_V{T(v), T(v), T(v), T(v)}{}

        template<typename U, typename V, typename W, typename M>
        UVector4(U x, V y, W z, M w):m_V{T(x), T(y), T(z), T(w)}{}

        template<typename G>
        UVector4(const UVector4<G> &tag):m_V{T(tag[0]), T(tag[1]), T(tag[2]), T(tag[3])}{}

        inline constexpr T const& operator[](int i)const
        {
            static_assert(i < S_SIZE);
            return m_V[i];
        }

        inline constexpr T& operator[](int i)
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
        UVector4<CLASS<T, G>> cross(const UVector4& a, const UVector4& b)
        {
            return {
                a[1] * b[2] - a[2] * b[1],
                a[2] * b[0] - a[0] * b[2],
                a[0] * b[1] - a[1] * b[0],
                CLASS<T, G>(1)
            };
        }

        /**
         * c = this.cross(b)。<br/>
         * @param b
         * @return c 返回this x b的结果。
         */
        template<typename G>
        UVector4<CLASS<T, G>> cross(const UVector4& b)
        {
            return {
                this[1] * b[2] - this[2] * b[1],
                this[2] * b[0] - this[0] * b[2],
                this[0] * b[1] - this[1] * b[0],
                CLASS<T, G>(1)
            };
        }
    };
}

#endif
