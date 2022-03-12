project(Core)

set(Core
	Engine.h
)

source_group("Core" FILES ${/})

set(FrameWork
	FrameWork/Application.cpp
	FrameWork/Application.h
	FrameWork/Settings.h
	FrameWork/Include.h
)

source_group("FrameWork" FILES ${FrameWork})

set(Tests
	Tests/Template.h
	Tests/Math3d/TestVector.h
	Tests/Math3d/TestVector.cpp
)

source_group("Tests" FILES ${Tests})

set(Math3d
	Math3d/Include.h
	Math3d/Math.h
	Math3d/Vector3.h
	Math3d/Vector4.h
	Math3d/Matrix4.h
	Math3d/Matrix4.cpp
)
source_group("Math3d" FILES ${Math3d})

set(Scene
	Scene/Scene.cpp
	Scene/Scene.h
	Scene/Geometry.h
	Scene/Geometry.cpp
	Scene/Include.h
)
source_group("Scene" FILES ${Scene})

set(Mesh
	Mesh/BufDescriptor.h
	Mesh/BufferBuilder.h
	Mesh/Mesh.cpp
)
source_group("Mesh" FILES ${Mesh})

set(Window
	Window/IWindow.cpp
	Window/IWindow.h
	Window/WindowMgr.cpp
	Window/WindowMgr.h
	Window/Win32Window.cpp
	Window/Win32Window.h
)
source_group("Window" FILES ${Window})

set(Device
	Device/VulkanDevice.cpp
	Device/VulkanDevice.h
	Device/IDevice.h
	Device/DeviceMgr.cpp
	Device/DeviceMgr.h
)
source_group("Device" FILES ${Device})

include_directories(
	# ../Thirdparty/Vulkan/Include
	# ../Thirdparty/Vulkan/Third-Party/Include
	${VULKAN_SDK_PATH}/Include
	${VULKAN_SDK_PATH}/Third-Party/Include
)

if(USE_DLL)
	#target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/Thirdparty/glfw/dynamic/glfw3.dll)
	add_library(${PROJECT_NAME} SHARED ${Core} ${FrameWork} ${Math3d} ${Scene} ${Mesh} ${Window} ${Device})
else()
	add_library(${PROJECT_NAME} ${Core} ${FrameWork} ${Math3d} ${Scene} ${Mesh} ${Window} ${Device})
endif()
