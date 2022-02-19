#include "Win32Window.h"
#include "WindowMgr.h"

Unknown3d::WindowMgr::WindowMgr():_m_window_ins(nullptr)
{
}

Unknown3d::WindowMgr::~WindowMgr()
{
}

Unknown3d::WindowMgr & Unknown3d::WindowMgr::Instance()
{
	static WindowMgr instance;
	return instance;
}

Unknown3d::IWindow* Unknown3d::WindowMgr::createPlatformWindow(USettings &settings)
{
	// TODO create window by platform
	_m_window_ins = new Win32Window();
	_m_window_ins->createWindow(settings.m_Width, settings.m_Height, settings.m_Title, settings.m_Resize);

	// 返回窗口句柄
	return _m_window_ins;
}

void Unknown3d::WindowMgr::onUpdate()
{
	if (_m_window_ins)
	{
		_m_window_ins->onUpdate();
	}
}