#include "Win32Window.h"
#include "WindowMgr.h"

WindowMgr::WindowMgr()
{

}

WindowMgr::~WindowMgr()
{
}

WindowMgr & WindowMgr::Instance()
{
	static WindowMgr instance;
	return instance;
}

void WindowMgr::createPlatformWindow()
{
	// TODO create window by platform
	_m_window_ins = new Win32Window();
	_m_window_ins->createWindow();
}

void WindowMgr::onUpdate()
{
	if (_m_window_ins)
	{
		_m_window_ins->onUpdate();
	}
}