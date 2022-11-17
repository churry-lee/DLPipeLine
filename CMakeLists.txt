cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(DLPipeLine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_APPLE_SILICON_PROCESSOR arm64)

set(CMAKE_PREFIX_PATH /Users/ichurry/LocalLib/libtorch)
find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

set(SRC_FILES
        src/main.cpp
#        src/train.cpp
#        src/valid.cpp
#        src/test.cpp
        src/netImpl.cpp)


set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(OUTPUT_ELF "${CMAKE_PROJECT_NAME}.out" )


add_executable( ${OUTPUT_ELF} ${SRC_FILES} )

target_include_directories( ${OUTPUT_ELF} PUBLIC
        inc
        )
target_link_libraries( ${OUTPUT_ELF} "${TORCH_LIBRARIES}")