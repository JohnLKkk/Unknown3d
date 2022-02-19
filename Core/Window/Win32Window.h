#pragma once
#include "IWindow.h"
#include<glfw/include/glfw3.h>

class Win32Window : public IWindow
{
public:
	/**
	* �������ڡ�<br/>
	* @param
	*/
	virtual void createWindow(int width = 640, int height = 480, const char* = "Unknow3d") override;
	/**
	* ���ٴ��ڡ�<br/>
	* @param
	*/
	virtual void destroyWindow() override;
	/**
	* ����update<br/>
	* @return int
	*/
	virtual void onUpdate() override;
protected:
private:
	GLFWwindow* _m_window;
};