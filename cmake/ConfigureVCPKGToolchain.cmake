# If a VCPKG toolchain file is specified and exists, use that one and skip configuring VCPKG
if (NOT "${CMAKE_TOOLCHAIN_FILE}" STREQUAL "" AND EXISTS "${CMAKE_TOOLCHAIN_FILE}")
    return()
endif()

if (NOT "$ENV{VCPKG_HOME}" STREQUAL "" AND EXISTS "$ENV{VCPKG_HOME}/scripts/buildsystems/vcpkg.cmake")
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_HOME}/scripts/buildsystems/vcpkg.cmake")
    return()
endif ()

# Otherwise use the provided submodule
find_package(Git QUIET)
if (GIT_FOUND AND EXISTS "${CMAKE_SOURCE_DIR}/.gitmodules")
    execute_process(
        COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        RESULT_VARIABLE GIT_SUBMOD_RESULT
    )
    if(NOT GIT_SUBMOD_RESULT EQUAL "0")
        message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules manually")
    endif()

    set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/source/3rdparty/vcpkg/scripts/buildsystems/vcpkg.cmake")
endif()

if("${CMAKE_TOOLCHAIN_FILE}" STREQUAL "" OR NOT EXISTS "${CMAKE_TOOLCHAIN_FILE}")
    message(FATAL_ERROR "Could not find VCPKG toolchain file")
else()
    message(STATUS "Using ${CMAKE_TOOLCHAIN_FILE} for the VCPKG toolchain file")
endif()
