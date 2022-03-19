#include "DeviceBase.h"

namespace Unknown3d {

	void DeviceBase::createSurface()
	{
		doCreateSurface();
	}

	void DeviceBase::createSwapChain()
	{
		doCreateSwapChain();
	}

	void DeviceBase::createImageViews()
	{
		doCreateImageViews();
	}

	void DeviceBase::createFramebuffers()
	{
		doCreateFramebuffers();
	}

	void DeviceBase::createCommandBuffers()
	{
		doCreateCommandBuffers();
	}

}