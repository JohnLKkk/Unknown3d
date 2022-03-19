#ifndef _DEVICE_VULKANDEVICE_H_
#define _DEVICE_VULKANDEVICE_H_

#define GLFW_INCLUDE_VULKAN
#include<glfw/glfw3.h>
#include <vector>
#include <optional>
#include "DeviceBase.h"
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

	class VulkanDevice :public DeviceBase
	{
	public:
		VulkanDevice() {
			initVulkan();
		}
		~VulkanDevice() {

		}

		/**
		 @desc: TODO:��ʱ��������vulkan����Ⱦ���̣������ÿ�����̶�����ɵ���class
		 @return: void
		*/
		void initVulkan();

		void createInstance();
		void setupDebugMessenger();
		//void createSurface();
		
		//void createSwapChain();
		//void createImageViews();
		void createRenderPass();
		void createGraphicsPipeline();
		//void createFramebuffers();
		void createCommandPool();
		//void createCommandBuffers();
		void createSyncObjects();

		void recreateSwapChain();
		void cleanupSwapChain();
		/**
		 @desc:ֹͣ��Ⱦʱ����vulkanʵ��������
		 @return: void
		*/
		void cleanup();

		/**
		 @desc: do some logic before flush
		 @return: void
		*/
		virtual void doBeginFrame() override;
		/**
		 @desc:do the flush logic
		 @return: void
		*/
		virtual void doFlushFrame() override;
		/**
		 @desc: do some logic after flush
		 @return: void
		*/
		virtual void doEndFrame() override;

	private:
		virtual void doCreateSurface() override;
		virtual void doCreateSwapChain() override;
		virtual void doCreateImageViews() override;
		virtual void doCreateFramebuffers() override;
		virtual void doCreateCommandBuffers() override;
		void pickPhysicalDevice();
		void createLogicalDevice();

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
}

#endif
