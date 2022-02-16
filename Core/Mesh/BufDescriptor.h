#ifndef _MESH_BUFDESCRIPTOR_H_
#define _MESH_BUFDESCRIPTOR_H_
#include <cstdint>

namespace Unknonw3d
{
    /**
     * BufDescriptor展示了所有可能的输入顶点属性。<br/>
     * @author JohnKkk
     * @date 2022年2月16日18点22分
     */
    enum UBufDescriptor
    {
        S_POSITION,
        S_NORMAL,
        S_TANGENT,
        S_INDICES,
        // 至多允许16道纹理坐标
        // 实际将根据硬件平台进行限制
        S_TEXCOORD0,
        S_TEXCOORD1,
        S_TEXCOORD2,
        S_TEXCOORD3,
        S_TEXCOORD4,
        S_TEXCOORD5,
        S_TEXCOORD6,
        S_TEXCOORD7,
        S_TEXCOORD8,
        S_TEXCOORD9,
        S_TEXCOORD10,
        S_TEXCOORD11,
        S_TEXCOORD12,
        S_TEXCOORD13,
        S_TEXCOORD14,
        S_TEXCOORD15,
    };

    /**
     * PrimitiveType表示允许的图元类型。<br/>
     * @author JohnKkk
     * @date 2022年2月16日18点29分
     */
    enum UPrimitiveType : uint8_t
    {
        POINTS          = 0,
        LINES           = 1,
        LINE_STRIP      = 2,
        TRIANGLES       = 3,
        TRIANGLES_STRIP = 4,
        NONE            = 0xff
    };

    /**
     * BufUsage表示允许的缓冲区标记。<br/>
     * @author JohnKkk
     * @date 2022年2月16日18点31分
     */
    enum UBufUsage
    {
        STATIC,
        DYNAMIC,
        STREAM,
        ANY
    };

    /**
     * Mesh表示构成图元渲染信息的实体数据,由一组Buffer表示。<br/>
     * @author JohnKkk
     * @date 2022年2月16日18点32分
     */
    class UMesh
    {
    public:
        /**
         * 设置Mesh的顶点属性。<br/>
         * 例如:<br/>
         * setData(S_POSITION, STATIC, {<br/>
         * 0.0, 0.0, 0.0,<br/>
         * 1.0, 0.0, 0.0,<br/>
         * 1.0, 1.0, 0.0,<br/>
         * }, 3);<br/>
         * setData(S_TEXCOORD0, ANY, {<br/>
         * 0, 0,<br/>
         * 0, 1,<br/>
         * 1, 1},<br/>
         * 3);
         * setData(S_INDICES, ANY, {<br/>
         * 0, 1, 2},<br/>
         * 3);
         * @param bufDescriptor 表示数据元顶点属性类型
         * @param bufUsage 表示数据元顶点属性块标记
         * @param data 表示数据
         * @param count 表示数据长度
         */
        void setData(UBufDescriptor bufDescriptor, UBufUsage bufUsage, void* data, uint32_t count);

        /**
         * 更新数据块,一旦需要重新构造数据,则应该在设置完数据后,调用updateBound()重置当前最新数据。<br/>
         */
        void updateBound();
    };
    
}
#endif
