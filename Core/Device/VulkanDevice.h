#ifndef _DEVICE_VULKANDEVICE_H_
#define _DEVICE_VULKANDEVICE_H_

#define GLFW_INCLUDE_VULKAN
#include<glfw/glfw3.h>
#include <vector>
#include <optional>
#include "IDevice.h"
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

	class VulkanDevice :public IDevice
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

		void recreateSwapChain();
		void cleanupSwapChain();
		/**
		 @desc:停止渲染时清理vulkan实例和数据
		 @return: void
		*/
		void cleanup();

		/**
		 @desc: do some logic before flush
		 @return: void
		*/
		virtual void DoBeginFrame() override;
		/**
		 @desc:do the flush logic
		 @return: void
		*/
		virtual void DoFlushFrame() override;
		/**
		 @desc: do some logic after flush
		 @return: void
		*/
		virtual void DoEndFrame() override;

	private:
		bool isDeviceSuitable(VkPhysicalDevice device);
		SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
		QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
		VkShaderModule createShaderModule(VkDevice device, const std::vector<char>& code);

		void* getWindowIns();
		void* window_ins = nullptr;

		VkInstance instance;
		VkDebugUtilsMessengerEXT debugMessenger;
		VkSurfaceKHR surface;

		VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
		VkDevice device;

		VkQueue graphicsQueue;
		VkQueue presentQueue;

		VkSwapchainKHR swapChain;
		std::vector<VkImage> swapChainImages;
		VkFormat swapChainImageFormat;
		VkExtent2D swapChainExtent;
		std::vector<VkImageView> swapChainImageViews;
		std::vector<VkFramebuffer> swapChainFramebuffers;

		VkRenderPass renderPass;
		VkPipelineLayout pipelineLayout;
		VkPipeline graphicsPipeline;

		VkCommandPool commandPool;
		std::vector<VkCommandBuffer> commandBuffers;

		std::vector<VkSemaphore> imageAvailableSemaphores;
		std::vector<VkSemaphore> renderFinishedSemaphores;
		std::vector<VkFence> inFlightFences;
		std::vector<VkFence> imagesInFlight;

		size_t currentFrame = 0;
		bool framebufferResized = false;
	};

	VulkanDevice::VulkanDevice()
	{
	}

	VulkanDevice::~VulkanDevice()
	{
	}
}

#endif
