#ifndef _DEVICE_VULKANDEVICE_H_
#define _DEVICE_VULKANDEVICE_H_

#define GLFW_INCLUDE_VULKAN
#include<glfw/include/glfw3.h>
/*!
 * @desc vulkan render
 *
 * @author 粉哥
 * @date 2022/02/21
 *
 * 
 */
namespace Unknown3d
{
	struct SwapChainSupportDetails {
		VkSurfaceCapabilitiesKHR capabilities;
		std::vector<VkSurfaceFormatKHR> formats;
		std::vector<VkPresentModeKHR> presentModes;
	};

	struct QueueFamilyIndices {
		std::optional<uint32_t> graphicsFamily;
		std::optional<uint32_t> presentFamily;

		bool isComplete() {
			return graphicsFamily.has_value() && presentFamily.has_value();
		}
	};

	class VulkanDevice
	{
	public:
		VulkanDevice();
		~VulkanDevice();

		/**
		 @desc: TODO:暂时由它管理vulkan的渲染流程，后面把每个流程都抽离成单个class
		 @return: void
		*/
		void initVulkan();

		void createInstance();
		void setupDebugMessenger();
		void createSurface();
		void pickPhysicalDevice();
		void createLogicalDevice();
		void createSwapChain();
		void createImageViews();
		void createRenderPass();
		void createGraphicsPipeline();
		void createFramebuffers();
		void createCommandPool();
		void createCommandBuffers();
		void createSyncObjects();
	private:
		bool isDeviceSuitable(VkPhysicalDevice device);
		SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
		QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

		VkInstance instance;
		VkDebugUtilsMessengerEXT debugMessenger;
		VkSurfaceKHR surface;
		VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
		VkDevice device;
		VkQueue graphicsQueue;
		VkQueue presentQueue;

		VkSwapchainKHR swapChain;
	};

	VulkanDevice::VulkanDevice()
	{
	}

	VulkanDevice::~VulkanDevice()
	{
	}
}

#endif
