cmake_minimum_required(VERSION 3.16)
project(strawberry-bpm VERSION 1.2.11 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

qt_standard_project_setup()

qt_add_executable(strawberry-bpm
    src/main.cpp
    src/track.cpp
    src/track.h
    src/trackmodel.cpp
    src/trackmodel.h
    src/playlist.cpp
    src/playlist.h
)

target_link_libraries(strawberry-bpm PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)

# ---- CPack config for .deb generation ----
set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_NAME "strawberry-bpm")
set(CPACK_PACKAGE_VERSION "1.2.11")
set(CPACK_PACKAGE_CONTACT "freugo54@gmail.com")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "freugo54")
include(CPack)
