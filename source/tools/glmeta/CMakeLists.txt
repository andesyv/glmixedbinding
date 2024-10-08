
# 
# External dependencies
# 

# No external dependencies required


# 
# Executable name and options
# 

# Target name
set(target ${META_PROJECT_NAME}-glmeta)

message(STATUS "Tool ${target}")


# 
# Sources
# 

set(sources
    main.cpp
)


# 
# Create executable
# 

# Build executable
add_executable(${target}
    ${sources}
)

# Create namespaced alias
add_executable(${META_PROJECT_NAME}::${target} ALIAS ${target})


# 
# Project options
# 

set_target_properties(${target}
    PROPERTIES
    ${DEFAULT_PROJECT_OPTIONS}
    INSTALL_RPATH "${EXECUTABLE_INSTALL_RPATH}"
    FOLDER "${IDE_FOLDER}"
)


# 
# Include directories
# 

target_include_directories(${target}
    PRIVATE
    ${DEFAULT_INCLUDE_DIRECTORIES}
    ${PROJECT_BINARY_DIR}/source/include
    SYSTEM
)


# 
# Libraries
# 

target_link_libraries(${target}
    PRIVATE
    ${DEFAULT_LIBRARIES}
    ${META_PROJECT_NAME}::glmixedbinding
    ${META_PROJECT_NAME}::glmixedbinding-aux
)


# 
# Compile definitions
# 

target_compile_definitions(${target}
    PRIVATE
    ${DEFAULT_COMPILE_DEFINITIONS}
)


# 
# Compile options
# 

target_compile_options(${target}
    PRIVATE
    ${DEFAULT_COMPILE_OPTIONS_PRIVATE}
    PUBLIC
    ${DEFAULT_COMPILE_OPTIONS_PUBLIC}
)


# 
# Linker options
# 

target_link_libraries(${target}
    PRIVATE
    ${DEFAULT_LINKER_OPTIONS}
)


#
# Target Health
#

perform_health_checks(
    ${target}
    ${sources}
)


# 
# Deployment
# 

# Executable
install(TARGETS ${target}
    RUNTIME DESTINATION ${INSTALL_BIN} COMPONENT tools
    BUNDLE  DESTINATION ${INSTALL_BIN} COMPONENT tools
)
