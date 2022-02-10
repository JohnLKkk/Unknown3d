#ifndef _MATH3D_MATH_H_
#define _MATH3D_MATH_H_
#include <complex>
#include <utility>


template<typename T, typename  G>
struct TYPE
{
    using CLASS = decltype(std::declval<T>() + std::declval<G>());
};
template<typename T, typename G>
using CLASS = typename TYPE<T, G>::CLASS;

/**
 * UVECTOR提供通用vector相关运算API封装。<br/>
 * @author JohnKkk
 * @date 2022年2月10日12点43分
 */
template<template<typename T> class VECTOR, typename T>
class UVECTOR
{
public:
    /**
     * c = a + b。<br/>
     * @param a
     * @param b
     * @return c
     */
    template<typename G>
    friend inline VECTOR<CLASS<T, G>> operator+(const VECTOR<T>& a, const VECTOR<G>& b)
    {
        VECTOR<CLASS<T, G>> res(a);
        res += b;
        return res;
    }
    
    /**
     * c = a - b。<br/>
     * @param a
     * @param b
     * @return c
     */
    template<typename G>
    friend inline VECTOR<CLASS<T, G>> operator-(const VECTOR<T>& a, const VECTOR<G>& b)
    {
        VECTOR<CLASS<T, G>> res(a);
        res -= b;
        return res;
    }

    /**
     * a = a + b。<br/>
     * @param b
     * @return a
     */
    template<typename G>
    VECTOR<T>& operator+=(const VECTOR<G> & b)
    {
        VECTOR<T>& a = static_cast<VECTOR<T>&>(*this);
        const size_t size = a.size() > b.size() ? b.size() : a.size();
        for(size_t i = 0;i < size;i++)
        {
            a[i] += b[i];
        }
        return a;
    }

    /**
     * a = a - b。<br/>
     * @param b
     * @return a
     */
    template<typename G>
    VECTOR<T>& operator-=(const VECTOR<G> & b)
    {
        VECTOR<T>& a = static_cast<VECTOR<T>&>(*this);
        const size_t size = a.size() > b.size() ? b.size() : a.size();
        for(size_t i = 0;i < size;i++)
        {
            a[i] -= b[i];
        }
        return a;
    }
    
    /**
     * c = -a。<br/>
     * @return c
     */
    VECTOR<T> operator-()const
    {
        VECTOR<T> r{};
        VECTOR<T> const& a(static_cast<VECTOR<T>&>(*this));
        for(size_t i = 0;i < a.size();i++)
            r[i] = -a[i];
        return r;
    }

    template<typename G>
    friend inline bool operator==(const VECTOR<T>& a, const VECTOR<G>& b)
    {
        // 这里的检查是为了防止vec3与vec2,vec4比较
        // 因为这种比较是未定义的,可能vec3.xyz == vec4.xyz也被认为是正确的
        // 但是为了性能,不应该在基础运算上做多余的判断,因此大部分方法不应该包含如下代码:
        // size_t asize = a.size(), bsize = b.size();
        // if(asize != bsize)return false;
        // 复杂的判断操作应该是应用阶段由用户自己处理,比如单独判断vec3.x,y,z与vec4.x,y,z的结果
        // 或者将其转换为vec3/vec4等
        
        size_t asize = a.size();

        for(size_t i = 0;i < asize;i++)
        {
            if(a[i] != b[i])return false;
        }

        return true;
    }

    template<typename G>
    friend inline bool operator!=(const VECTOR<T>& a, const VECTOR<G>& b)
    {
        return !operator==(a, b);
    }

    /**
     * l = a.dot(b)。<br/>
     * @param a
     * @param b
     * @return l 返回a与b的点成结果。
     */
    template<typename G>
    friend inline 
    CLASS<T, G> dot(const VECTOR<T>& a, const VECTOR<G>& b)
    {
        CLASS<T, G> r{};
        for(size_t i = 0;i < a.size();i++)
        {
            r += a[i] * b[i];
        }
        return r;
    }

    template<typename G>
    CLASS<T, G> dot(const VECTOR<G>& b)
    {
        return dot<T>(static_cast<VECTOR<T>&>(*this), b);
    }

    /**
     * 取得VECTOR的模长。<br/>
     * @return l
     */
    T length()
    {
        return std::sqrt(lengthSqrt());
    }
    
    /**
     * 取得VECTOR的模长的平方。<br/>
     * @return l
     */
    inline T lengthSqrt()
    {
        VECTOR<T>& _self(static_cast<VECTOR<T>&>(*this));
        return dot(_self, _self);
    }

    /**
     * 归一化VECTOR。<br/>
     * @return this
     */
    VECTOR<T>& normalize()
    {
        VECTOR<T>& _self(static_cast<VECTOR<T>&>(*this));
        
        T l = length();
        l = l > T(0) ? T(1) / l : T(0);

        constexpr const size_t size = _self.size();
        for(size_t i = 0;i < size;i++)
        {
            _self[i] *= l;
        }
        return _self;
    }

    VECTOR<T>& rcp()
    {
        
    }
};



#endif

