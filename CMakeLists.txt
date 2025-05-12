cmake_minimum_required(VERSION 3.16)
project(fabrifs VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add executable
add_executable(fabrifs src/main.cpp)

# Add compile options
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(fabrifs PRIVATE -Wall -Wextra -Wpedantic)
elseif(MSVC)
    target_compile_options(fabrifs PRIVATE /W4)
endif()

# Check for filesystem library requirement
find_package(Threads REQUIRED)
target_link_libraries(fabrifs PRIVATE Threads::Threads)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU" AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS 9.0)
    target_link_libraries(fabrifs PRIVATE stdc++fs)
endif()

# Installation rules
install(TARGETS fabrifs
    RUNTIME DESTINATION bin
)

# Package information
set(CPACK_PACKAGE_NAME "fabrifs")
set(CPACK_PACKAGE_VENDOR "SinesCode")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Fast and Brilliant File System Creator")
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_PACKAGE_CONTACT "your.email@example.com")

# Generate different packages based on the system
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(CPACK_GENERATOR "DEB;RPM;TGZ")
    set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6 (>= 2.14), libstdc++6 (>= 9.0)")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(CPACK_GENERATOR "ZIP;NSIS")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    set(CPACK_GENERATOR "TGZ;DragNDrop")
endif()

include(CPack)