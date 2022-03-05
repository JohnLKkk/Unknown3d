# 请求最低CMake版本为3.0
cmake_minimum_required (VERSION 3.0)
set(CMAKE_CXX_STANDARD 17)
project(Unknown3d)

# 宏开关设置
option(USE_DLL "Use Dynamic Link Library" OFF)

# C++17 版本设置
# include(CheckCXXCompilerFlag)
# check_cxx_compiler_flag("c++17" _cpp_17_flag_supported)
# if (_cpp_17_flag_supported)
# 	set (CMAKE_CXX_STANDARD 17)
# endif()

set(GAME_ENTRY Tests)
add_executable(${GAME_ENTRY} ${GAME_ENTRY}/TestLauncher.cpp)

set(SubModules
	Core
)

message("Submodules:" ${SubModules})
foreach(module ${SubModules})
	message("module:" ${module})
	add_subdirectory(${module})
	include_directories(
		${module}
	)
	add_dependencies(${GAME_ENTRY} ${module})
	target_link_libraries(${GAME_ENTRY} ${module})
endforeach(module ${SubModules})

# thirdparty
if(USE_DLL)
	set(LinkFile "dynamic")
	set(LinkType ".dll")
else()
	set(LinkFile "static")
	set(LinkType ".lib")
endif()
# target_link_libraries(${GAME_ENTRY} ${PROJECT_SOURCE_DIR}/Thirdparty/glfw/${LinkFile}/glfw3${LinkType})


# vulkan
include_directories(
	#../Thirdparty/Vulkan/Include
	Thirdparty/Vulkan/Include
	Thirdparty/Vulkan/Third-Party/Include
)
if(USE_DLL)
	#TODO 未验证，暂时不知道动态库要引入啥dll
	target_link_directories(${GAME_ENTRY} PUBLIC ${PROJECT_SOURCE_DIR}/Thirdparty/Vulkan/Bin/)
	# target_link_directories(${GAME_ENTRY} ${PROJECT_SOURCE_DIR}/Thirdparty/Vulkan/Third-Party/Bin)
else()
	target_link_directories(${GAME_ENTRY} PUBLIC ${PROJECT_SOURCE_DIR}/Thirdparty/Vulkan/Lib/)
	target_link_directories(${GAME_ENTRY} PUBLIC ${PROJECT_SOURCE_DIR}/Thirdparty/Vulkan/Third-Party/Bin)
	# target_link_directories(${GAME_ENTRY} ${PROJECT_SOURCE_DIR}/Thirdparty/Vulkan/Third-Party/Bin)
	target_link_libraries(${GAME_ENTRY} vulkan-1.lib)
endif()
target_link_libraries(${GAME_ENTRY} glfw3${LinkType})