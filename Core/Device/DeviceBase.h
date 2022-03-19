#ifndef _DEVICE_DEVICEBASE_H_
#define _DEVICE_DEVICEBASE_H_
/*!
 * @desc 
 *
 * @author �۸�
 * @date 2022/02/23
 *
 * 
 */
namespace Unknown3d {
	class DeviceBase
	{
	public:
		DeviceBase() {};
		virtual ~DeviceBase() {};
		/**
		 @desc: do some logic before flush 
		 @return: void
		*/
		virtual void doBeginFrame() = 0;
		/**
		 @desc:do the flush logic
		 @return: void
		*/
		virtual void doFlushFrame() = 0;
		/**
		 @desc: do some logic after flush
		 @return: void
		*/
		virtual void doEndFrame() = 0;

		/**
		 @desc:��������ʼ��device instance
		 @return: void
		*/
		virtual void createInstance() = 0;
		/**
		 @desc:����debug�����Ϣ
		 @return: void
		*/
		virtual void setupDebugMessenger() = 0;
		/**
		 @desc: �������Ӳ�������Ľӿ�
		 @return: void
		*/
		void createSurface();
		void createSwapChain();
		void createImageViews();
		void createFramebuffers();
		void createCommandBuffers();

	private:
		static DeviceBase* _m_DeviceInstance;

		// --��do��һ���Ǹ�����Ⱦ������д�Լ��ľ������--

		/**
		 @desc:
		 @return: void
		*/
		virtual void doCreateSurface() {};
		virtual void doCreateSwapChain() {};
		virtual void doCreateImageViews() {};
		virtual void doCreateFramebuffers() {};
		virtual void doCreateCommandBuffers() {};
	};
}



#endif