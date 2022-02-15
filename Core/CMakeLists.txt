project(Core)

set(Core 
	Engine.cpp
	Engine.h
	TestLauncher.cpp
)
source_group("Core" FILES ${Core})

set(FrameWork
	FrameWork/Application.cpp
	FrameWork/Application.h
	FrameWork/Include.h
)
source_group("FrameWork" FILES ${FrameWork})

set(Math3d
	Math3d/Include.h
	Math3d/Math.h
	Math3d/Vector3.cpp
	Math3d/Vector3.h
)
source_group("Math3d" FILES ${Math3d})

set(Scene
	Scene/Scene.cpp
	Scene/Scene.h
	Scene/Include.h
)
source_group("Scene" FILES ${Scene})

set(Geometry
	Geometry/Window.cpp
	Geometry/Window.h
)
source_group("Geometry" FILES ${Geometry})

include_directories(
	Vendor/
)

add_library(${PROJECT_NAME} ${Core} ${FrameWork} ${Math3d} ${Scene} ${Geometry})
