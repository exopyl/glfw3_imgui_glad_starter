cmake_minimum_required(VERSION 3.20)
project(orion)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_VERBOSE_MAKEFILE 1)
set(APP_VERSION_MAJOR 1)
set(APP_VERSION_MINOR 0)

set(APP_TARGET orion)

add_subdirectory(imgui)
include_directories(${PROJECT_SOURCE_DIR})

set(srcs
        ${PROJECT_SOURCE_DIR}/imgui/imgui_impl_glfw.cpp
        ${PROJECT_SOURCE_DIR}/imgui/imgui_impl_glfw.h
        ${PROJECT_SOURCE_DIR}/imgui/imgui_impl_opengl3.cpp
        ${PROJECT_SOURCE_DIR}/imgui/imgui_impl_opengl3.h
        ${PROJECT_SOURCE_DIR}/imgui/imgui_impl_opengl3_loader.h
        main.cpp
        scene.cpp
        scene.h
        glad/gl.c
        )

add_executable(${APP_TARGET} ${srcs})
target_link_libraries(${APP_TARGET} imgui)

# glfw
set(GLFW_ROOT "C:/path/to/glfw-3.3.8")
if (GLFW_ROOT)
    set(GLFW_INCLUDE ${GLFW_ROOT}/include)

    set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

    add_subdirectory(${GLFW_ROOT} glfw)

    include_directories(${GLFW_INCLUDE})
    target_link_libraries(${PROJECT_NAME} glfw ${GLFW_LIBRARIES})
else ()
    find_package(GLFW3 REQUIRED)
    if (GLFW_FOUND)
        message("GLFW ${GLFW_VERSION} library found !")
        message(" - Headers : ${GLFW_INCLUDE_DIRS}")
        message(" - Binary : ${GLFW_LIBRARIES}")
        include_directories(${GLFW_INCLUDE_DIRS})
        link_libraries(${GLFW_LIBRARY_DIRS})
    endif ()
endif ()

# opengl
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

target_link_libraries(
        ${APP_TARGET}
        glfw
        ${OPENGL_LIBRARIES}
)