cmake_minimum_required(VERSION 3.16)
project(strawberry-bpm VERSION 1.2.11 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

add_executable(strawberry-bpm
    track.cpp
    track.h
    trackmodel.cpp
    trackmodel.h
    playlist.cpp
    playlist.h
)

target_link_libraries(strawberry-bpm PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)

# ---- CPack config for .deb generation ----
include(CPack)
set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_NAME "strawberry-bpm")
set(CPACK_PACKAGE_VERSION "1.2.11")
set(CPACK_PACKAGE_CONTACT "freugo54@gmail.com")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "freugo54")
