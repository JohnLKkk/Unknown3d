#ifndef _DEVICE_DEVICEMGR_H_
#define _DEVICE_DEVICEMGR_H_

/*!
 * @desc Device 创建/管理
 *
 * @author 粉哥
 * @date 2022/02/27
 *
 * 
 */
#include "VulkanDevice.h"
#include "DeviceBase.h"

namespace Unknown3d {
	class DeviceMgr
	{
	public:
		static DeviceMgr& Instance();

		DeviceBase* createDevice();
		DeviceBase* getCurDevice() { return device; }

		/**
		 @desc:control the device frame update order
		 @return: void
		*/
		void beginDraw();
	protected:
	private:
		DeviceMgr* _m_deviceMgrIns;
		DeviceBase* device;
	};
}


#endif 