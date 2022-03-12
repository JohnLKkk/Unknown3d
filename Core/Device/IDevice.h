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
	class IDevice
	{
	public:
		IDevice() {};
		virtual ~IDevice() {};
		/**
		 @desc: do some logic before flush 
		 @return: void
		*/
		virtual void DoBeginFrame() = 0;
		/**
		 @desc:do the flush logic
		 @return: void
		*/
		virtual void DoFlushFrame() = 0;
		/**
		 @desc: do some logic after flush
		 @return: void
		*/
		virtual void DoEndFrame() = 0;

	private:
		static IDevice* _m_DeviceInstance;
	};
}



#endif