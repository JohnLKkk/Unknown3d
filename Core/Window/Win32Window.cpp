#include <cstdio>
#include "Win32Window.h"


void error_callback(int error, const char * description)
{
	fprintf(stderr, "Error: %s\n", description);
}

void Win32Window::createWindow(int width, int height, const char* win_title)
{
	glfwSetErrorCallback(error_callback);

	if (!glfwInit()) {
		fprintf(stderr, "Error: glfwInit failed.\n");
		return;
	}
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	_m_window = glfwCreateWindow(width, height, win_title, NULL, NULL);
	if (!_m_window)
	{
		fprintf(stderr, "Error: glfwCreateWindow failed.\n");
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(_m_window);
}

void Win32Window::destroyWindow()
{
	glfwDestroyWindow(_m_window);
}

void Win32Window::onUpdate()
{
	if (!glfwWindowShouldClose(_m_window))
	{
		glfwSwapBuffers(_m_window);
		glfwPollEvents();
	}
}

