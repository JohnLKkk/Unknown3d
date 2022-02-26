#ifndef _DEVICE_DEVICEBASE_H_
#define _DEVICE_DEVICEBASE_H_
/*!
 * @desc 
 *
 * @author ·Û¸ç
 * @date 2022/02/23
 *
 * 
 */
namespace Unknown3d {
	class DeviceBase
	{
	public:
		DeviceBase();
		virtual ~DeviceBase();



	private:
		static DeviceBase* _m_DeviceInstance;
	};
}



#endif