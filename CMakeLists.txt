cmake_minimum_required(VERSION 3.20)
project(EoppEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE ENGINE_SOURCES
    src/*.cpp
    src/*.c
    src/*.hpp
    src/*.h
)

list(FILTER ENGINE_SOURCES EXCLUDE REGEX "screenResolutionW.cpp")
list(FILTER ENGINE_SOURCES EXCLUDE REGEX "screenResolutionL.cpp")

if (WIN32)
    list(APPEND ENGINE_SOURCES src/engine/window/screenResolutionW.cpp)
elseif(UNIX)
    list(APPEND ENGINE_SOURCES src/engine/window/screenResolutionL.cpp)
endif()

add_executable(EoppEngine ${ENGINE_SOURCES})

target_include_directories(EoppEngine PRIVATE include)

find_package(SDL3 REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(Vulkan REQUIRED)

target_link_libraries(EoppEngine PRIVATE
    SDL3::SDL3
    glm::glm
    Vulkan::Vulkan
)

add_custom_command(TARGET EoppEngine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/bin
        $<TARGET_FILE_DIR:EoppEngine>
)