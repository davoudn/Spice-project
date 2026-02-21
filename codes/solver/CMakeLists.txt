cmake_minimum_required(VERSION 3.15)
project(spice VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find a package (example: spdlog)
find_package(spdlog REQUIRED)
# You can also find other packages like:
# find_package(OpenCV REQUIRED)
# find_package(Boost REQUIRED COMPONENTS system filesystem)
# find_package(PkgConfig REQUIRED)

# Include directories (if you have local include folders)
include_directories(
    ${PROJECT_SOURCE_DIR}/components
    ${PROJECT_SOURCE_DIR}
    /usr/local/include/antlr4-runtime
    # Add any other include paths
)

# Better alternative using target_include_directories (modern CMake)
# We'll create an executable and add includes to it

# Collect source files
file(GLOB_RECURSE SOURCES 
    "./Parser/generated/*.cpp"
    "./components/*.cpp"
)

# Or manually list sources:
# set(SOURCES
#     src/main.cpp
#     src/helper.cpp
#     src/utils.cpp
# )

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES} main.cpp)

# Add include directories to the target (modern approach)
target_include_directories(${PROJECT_NAME} 
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

# Link libraries (including the package we found)
target_link_libraries(${PROJECT_NAME}
    PRIVATE
     armadillo 
     lapack 
     blas  
     antlr4-runtime
        # Add other libraries here:
        # OpenCV::OpenCV
        # Boost::system
        # ${PkgConfig_LIBRARIES}
)

# If using pkg-config packages:
# pkg_check_modules(DEPS REQUIRED libssl libcrypto)
# target_link_libraries(${PROJECT_NAME} PRIVATE ${DEPS_LIBRARIES})
# target_include_directories(${PROJECT_NAME} PRIVATE ${DEPS_INCLUDE_DIRS})

# Optional: Set output directory
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
