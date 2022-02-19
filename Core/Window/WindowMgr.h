#pragma once
#include "IWindow.h"

class WindowMgr
{
	WindowMgr();
	~WindowMgr();
public:
	static WindowMgr& Instance();

	void createPlatformWindow();
	void onUpdate();
	

	IWindow* getWindowIns() { return _m_window_ins; }
protected:
private:
	IWindow* _m_window_ins;
};