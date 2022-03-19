#include "DeviceMgr.h"

namespace Unknown3d {

	DeviceMgr& DeviceMgr::Instance()
	{
		static DeviceMgr instance;
		return instance;
	}
	DeviceBase * DeviceMgr::createDevice()
	{
#define USE_VULKAN
#ifdef USE_VULKAN
		device = new VulkanDevice();
#else
		device = nullptr;
#endif
		return device;
	}
	void DeviceMgr::beginDraw()
	{
		if (device)
		{
			device->doBeginFrame();
			device->doFlushFrame();
			device->doEndFrame();
		}
	}
}

