#pragma once

class IWindow
{
public:
	/**
	* Ĭ�Ϲ��캯��<br/>
	*/
	IWindow();
	/**
	* Ĭ����������<br/>
	*/
	virtual ~IWindow();

	/**
	* ��������<br/>
	* @param
	*/
	virtual void createWindow(int width = 640, int height = 480, const char* = "Unknow3d") = 0;
	/**
	* ���ٴ���<br/>
	* @param
	*/
	virtual void destroyWindow() = 0;
	/**
	* ����update<br/>
	* @return int
	*/
	virtual void onUpdate() = 0;
	/**
	* ���ô��ڿ�<br/>
	* @return
	*/
	void setWidth(int width)
	{
		_m_width = width;
	}
	/**
	* ���ô��ڸ�<br/>
	* @return
	*/
	void setHeight(int height)
	{
		_m_height = height;
	}
	/**
	* ��ȡ���ڿ�<br/>
	* @return int
	*/
	int getWidth()const { return _m_width; }
	/**
	* ��ȡ���ڸ�<br/>
	* @return int
	*/
	int getHeight()const { return _m_height; }
	
protected:
	
private:
	int _m_width;
	int _m_height;
};
