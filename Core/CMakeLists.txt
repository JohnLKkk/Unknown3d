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

set(Geometry
	Geometry/Window.cpp
	Geometry/Window.h
)
source_group("Geometry" FILES ${Geometry})

include_directories(
	Vendor/
)

add_library(${PROJECT_NAME} ${Core} ${FrameWork} ${Math3d} ${Scene} ${Geometry})
