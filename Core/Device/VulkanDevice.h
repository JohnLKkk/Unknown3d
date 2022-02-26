#ifndef _DEVICE_VULKANDEVICE_H_
#define _DEVICE_VULKANDEVICE_H_

#define GLFW_INCLUDE_VULKAN
#include<glfw/include/glfw3.h>
/*!
 * @desc vulkan render
 *
 * @author �۸�
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
		 @desc: TODO:��ʱ��������vulkan����Ⱦ���̣������ÿ�����̶�����ɵ���class
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
