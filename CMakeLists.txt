# 请求最低CMake版本为3.0
cmake_minimum_required (VERSION 3.0)
project(Unknown3d)

# 宏开关设置
option(USE_DLL "Use Dynamic Link Library" OFF)

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
target_link_libraries(${GAME_ENTRY} ${PROJECT_SOURCE_DIR}/Thirdparty/glfw/${LinkFile}/glfw3${LinkType})