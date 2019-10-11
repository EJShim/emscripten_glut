cmake_minimum_required(VERSION 2.8)

set(CMAKE_BUILD_TYPE Release)
if(EMSCRIPTEN)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s WASM=1")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s USE_WEBGL2=1")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s FULL_ES3=1")
    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s ALLOW_MEMORY_GROWTH=1")
    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s ERROR_ON_UNDEFINED_SYMBOLS=0")
else()
    include_directories(
        "C:/Libs/freeglut-3.2.1/include"
        # "C:/Libs/glew-2.1.0/include"
    )
endif()


find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

#ADd ExeCutable!
add_executable(index main.cpp)


if(NOT EMSCRIPTEN)
    target_link_libraries(index 
        "C:/Libs/freeglut-3.2.1/lib/freeglut.lib" 
        # opengl32        
        # "C:/Libs/glew-2.1.0/lib/Release/x64/glew32.lib"
        ${VTK_LIBRARIES})
endif()


