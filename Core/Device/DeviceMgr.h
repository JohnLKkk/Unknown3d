#ifndef _DEVICE_DEVICEMGR_H_
#define _DEVICE_DEVICEMGR_H_

/*!
 * @desc Device ����/����
 *
 * @author �۸�
 * @date 2022/02/27
 *
 * 
 */
#include "VulkanDevice.h"
#include "IDevice.h"

namespace Unknown3d {
	class DeviceMgr
	{
	public:
		static DeviceMgr& Instance();

		IDevice* createDevice();
		IDevice* getCurDevice() { return device; }

		/**
		 @desc:control the device frame update order
		 @return: void
		*/
		void beginDraw();
	protected:
	private:
		DeviceMgr* _m_deviceMgrIns;
		IDevice* device;
	};
}


#endif 