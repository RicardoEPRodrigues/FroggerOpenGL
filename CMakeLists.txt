cmake_minimum_required(VERSION 3.5)
project(FroggerOpenGl)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-std=c++14")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g3 -Og -Wuninitialized")

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Ofast")

include_directories(FroggerObjects GraphicLib shaders resources engine)

set(SOURCE_FILES
        FroggerObjects/Cameras/FpsPerspCamera.cpp
        FroggerObjects/Cameras/FpsPerspCamera.h
        FroggerObjects/Cameras/TopOrthoCamera.cpp
        FroggerObjects/Cameras/TopOrthoCamera.h
        FroggerObjects/Cameras/TopPerspCamera.cpp
        FroggerObjects/Cameras/TopPerspCamera.h
        FroggerObjects/ComplexObjects/BelowRiver.cpp
        FroggerObjects/ComplexObjects/BelowRiver.h
        FroggerObjects/ComplexObjects/Bus.cpp
        FroggerObjects/ComplexObjects/Bus.h
        FroggerObjects/ComplexObjects/Car.cpp
        FroggerObjects/ComplexObjects/Car.h
        FroggerObjects/ComplexObjects/Frog.cpp
        FroggerObjects/ComplexObjects/Frog.h
        FroggerObjects/ComplexObjects/Particle.cpp
        FroggerObjects/ComplexObjects/Particle.h
        FroggerObjects/ComplexObjects/River.cpp
        FroggerObjects/ComplexObjects/River.h
        FroggerObjects/ComplexObjects/Riverside.cpp
        FroggerObjects/ComplexObjects/Riverside.h
        FroggerObjects/ComplexObjects/Road.cpp
        FroggerObjects/ComplexObjects/Road.h
        FroggerObjects/ComplexObjects/Roadside.cpp
        FroggerObjects/ComplexObjects/Roadside.h
        FroggerObjects/ComplexObjects/Timberlog.cpp
        FroggerObjects/ComplexObjects/Timberlog.h
        FroggerObjects/ComplexObjects/Tree.cpp
        FroggerObjects/ComplexObjects/Tree.h
        FroggerObjects/ComplexObjects/Turtle.cpp
        FroggerObjects/ComplexObjects/Turtle.h
        FroggerObjects/Lights/Daylight.cpp
        FroggerObjects/Lights/Daylight.h
        FroggerObjects/Lights/Nightlight.cpp
        FroggerObjects/Lights/Nightlight.h
        FroggerObjects/Lights/Spotlight.cpp
        FroggerObjects/Lights/Spotlight.h
        FroggerObjects/SimpleObjects/Cone.cpp
        FroggerObjects/SimpleObjects/Cone.h
        FroggerObjects/SimpleObjects/Cube.cpp
        FroggerObjects/SimpleObjects/Cube.h
        FroggerObjects/SimpleObjects/Cylinder.cpp
        FroggerObjects/SimpleObjects/Cylinder.h
        FroggerObjects/SimpleObjects/Rectangle.cpp
        FroggerObjects/SimpleObjects/Rectangle.h
        FroggerObjects/SimpleObjects/Sphere.cpp
        FroggerObjects/SimpleObjects/Sphere.h
        FroggerObjects/SimpleObjects/Torus.cpp
        FroggerObjects/SimpleObjects/Torus.h
        FroggerObjects/Utilities/HitableObject.cpp
        FroggerObjects/Utilities/HitableObject.h
        FroggerObjects/Utilities/ObjectFactory.cpp
        FroggerObjects/Utilities/ObjectFactory.h
        FroggerObjects/Utilities/ResetableObject.cpp
        FroggerObjects/Utilities/ResetableObject.h
        FroggerObjects/FroggerGameManager.cpp
        FroggerObjects/FroggerGameManager.h
        FroggerObjects/MovementEngine.cpp
        FroggerObjects/MovementEngine.h
        FroggerObjects/ObjectCollider.cpp
        FroggerObjects/ObjectCollider.h
        GraphicLib/AVTLib/AVTMatrixModule.cpp
        GraphicLib/AVTLib/AVTMatrixModule.h
        GraphicLib/AVTLib/basic_geometry.cpp
        GraphicLib/AVTLib/basic_geometry.h
        GraphicLib/AVTLib/cube.h
        GraphicLib/AVTLib/rectangle.h
        GraphicLib/AVTLib/rectanglexy.h
        GraphicLib/AVTLib/VertexAttrDef.h
        GraphicLib/AVTLib/vsShaderLib.cpp
        GraphicLib/AVTLib/vsShaderLib.h
        GraphicLib/CameraObjects/Camera.cpp
        GraphicLib/CameraObjects/Camera.h
        GraphicLib/CameraObjects/OrthogonalCamera.cpp
        GraphicLib/CameraObjects/OrthogonalCamera.h
        GraphicLib/CameraObjects/PerspectiveCamera.cpp
        GraphicLib/CameraObjects/PerspectiveCamera.h
        GraphicLib/flare_textures/crcl.raw
        GraphicLib/flare_textures/flar.raw
        GraphicLib/flare_textures/Flare1.bmp
        GraphicLib/flare_textures/Flare2.bmp
        GraphicLib/flare_textures/Flare3.bmp
        GraphicLib/flare_textures/Flare4.bmp
        GraphicLib/flare_textures/hxgn.raw
        GraphicLib/flare_textures/ring.raw
        GraphicLib/flare_textures/Sun.bmp
        GraphicLib/flare_textures/sun.raw
        GraphicLib/GameObjects/Billboard.cpp
        GraphicLib/GameObjects/Billboard.h
        GraphicLib/GameObjects/ComposedObject.cpp
        GraphicLib/GameObjects/ComposedObject.h
        GraphicLib/GameObjects/DynamicObject.cpp
        GraphicLib/GameObjects/DynamicObject.h
        GraphicLib/GameObjects/Flare.cpp
        GraphicLib/GameObjects/Flare.h
        GraphicLib/GameObjects/GameObject.cpp
        GraphicLib/GameObjects/GameObject.h
        GraphicLib/GameObjects/SimpleObject.cpp
        GraphicLib/GameObjects/SimpleObject.h
        GraphicLib/GameObjects/StaticObject.cpp
        GraphicLib/GameObjects/StaticObject.h
        GraphicLib/LightObjects/LightSource.cpp
        GraphicLib/LightObjects/LightSource.h
        GraphicLib/Engine.cpp
        GraphicLib/Engine.h
        GraphicLib/Entity.cpp
        GraphicLib/Entity.h
        GraphicLib/flare.txt
        GraphicLib/FlareManager.cpp
        GraphicLib/FlareManager.h
        GraphicLib/GameManager.cpp
        GraphicLib/GameManager.h
        GraphicLib/glbmp.cpp
        GraphicLib/glbmp.h
        resources/particula.bmp
        GraphicLib/TGA.cpp GraphicLib/TGA.h
        GraphicLib/Vector3.cpp GraphicLib/Vector3.h
        GraphicLib/Vector4.cpp GraphicLib/Vector4.h
        main.cpp
        )

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})

add_executable(FroggerOpenGl ${SOURCE_FILES})

target_link_libraries(FroggerOpenGl ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})