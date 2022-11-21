cmake_minimum_required(VERSION 3.16)
project(DLPipeLine_Detection)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
if(${APPLE})
    set(CMAKE_APPLE_SILICON_PROCESSOR arm64)
endif()

if(MSVC)
    set(CUDA_TOOLKIT_ROOT_DIR C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v11.6)
    set(CMAKE_PREFIX_PATH D:/local_lib/libtorch-win-debug)
elseif(${APPLE})
    set(CMAKE_PREFIX_PATH /Users/ichurry/LocalLib/libtorch-debug)
else()
    set(CMAKE_CUDA_COMPILER /usr/local/cuda-11.3/bin/nvcc)
    set(CUDA_TOOLKIT_ROOT_DIR /usr/local/cuda-11.3)
    set(CUDA_CUDART_LIBRARY /usr/local/cuda-11.3/lib64/libcudart.so)
    set(CUDA_NVRTC_SHORTHASH /usr/local/cuda-11.3/lib64/libnvrtc.so)
    set(CMAKE_PREFIX_PATH /home/chlee-sky/libtorch)
endif(MSVC)
find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

set(SRC_FILES
        src/main.cpp
        src/Detector.cpp
        #        src/DetDataset.cpp
        #        src/utils/Augmentations.cpp
        #        src/utils/tinystr.cpp
        #        src/utils/tinyxml.cpp
        #        src/utils/tinyxmlerror.cpp
        #        src/utils/tinyxmlparser.cpp
        #        src/models/CSPdarknet53_tiny.cpp
        #        src/models/yolo4_tiny.cpp
        #        src/models/yolo_training.cpp
        )

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../bin/)
set(OUTPUT_ELF "${CMAKE_PROJECT_NAME}" )

add_executable( ${OUTPUT_ELF} ${SRC_FILES} )

include_directories(
        inc
        inc/utils
        inc/models
)
link_libraries(  )

if (MSVC)
    target_include_directories( ${OUTPUT_ELF} PUBLIC
            D:/local_lib/opencv-454-win/include
            )
    target_link_directories( ${OUTPUT_ELF} PUBLIC
            D:/local_lib/opencv-454-win/lib
            )
    target_link_libraries( ${OUTPUT_ELF} PUBLIC
            "${TORCH_LIBRARIES}"
            opencv_world454d
            )
else()
    find_package(OpenCV REQUIRED)
    target_include_directories( ${OUTPUT_ELF} PUBLIC
            ${OpenCV_INCLUDE_DIRS}
            )
    target_link_directories( ${OUTPUT_ELF} PUBLIC
            /usr/lib
            /usr/local/lib/

            )
    target_link_libraries( ${OUTPUT_ELF} PUBLIC
            opencv_core opencv_highgui
            ${OpenCV_LIBS}
            ${TORCH_LIBRARIES}
            )
endif()

target_compile_definitions( ${OUTPUT_ELF} PUBLIC
        BINARY_FILE_PATH="${EXECUTABLE_OUTPUT_PATH}"
        )


if (MSVC)
    file(GLOB TORCH_DLLS "${TORCH_INSTALL_PREFIX}/lib/*.dll")
    add_custom_command(TARGET ${OUTPUT_ELF}
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${TORCH_DLLS}
            $<TARGET_FILE_DIR:${OUTPUT_ELF}>)
endif (MSVC)

if (MSVC)
    target_compile_options(${OUTPUT_ELF} PUBLIC /W4)
else()
    target_compile_options(${OUTPUT_ELF} PUBLIC -Wall -Wextra -pedantic)
endif(MSVC)

#cmake_minimum_required(VERSION 3.16)
#project(torch_prac)
#
#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED True)
#set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_VERBOSE_MAKEFILE True)
#if(${APPLE})
#    set(CMAKE_APPLE_SILICON_PROCESSOR arm64)
#endif()

#set(CUDA_TOOLKIT_ROOT_DIR /usr/local/cuda-11.3)
#set(CUDA_CUDART_LIBRARY /usr/local/cuda-11.3/lib64/libcudart.so)
#set(CUDA_NVRTC_SHORTHASH /usr/local/cuda-11.3/lib64/libnvrtc.so)
#set(CMAKE_CUDA_COMPILER /usr/local/cuda-11.3/bin/nvcc)

#find_package(CUDA 11.3 REQUIRED)
#set(CMAKE_CUDA_TOOLKIT_INCLUDE_DIRECTORIES C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v11.3/include)
#set(CUDA_NVCC_EXECUTABLE C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v11.3/bin/nvcc.exe)
#set(CUDA_TOOLKIT_ROOT_DIR C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v11.3)
#set(CUDA_INCLUDE_DIRS C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v11.3/include)
#set(CUDA_CUDART_LIBRARY C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v11.3/lib/x64/cudart.lib)
#set(CUDA_NVRTC_SHORTHASH C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v11.3/lib/x64/nvrtc.lib)


#set(CUDA_TOOLKIT_ROOT_DIR C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v11.6)
#set(CMAKE_PREFIX_PATH D:/local_lib/libtorch-win)
#find_package(Torch REQUIRED)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")
##set(CMAKE_CXX_FLAGS "-fsanitize=undefined -fsanitize=address")
#
#set(SRC_FILES
#        main.cpp
#        )
#
#set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set(OUTPUT_ELF "${CMAKE_PROJECT_NAME}.out" )
#
#
#add_executable( ${OUTPUT_ELF} ${SRC_FILES} )
#
#target_include_directories( ${OUTPUT_ELF} PUBLIC
#        D:/local_lib/opencv-454-win/include
#        )
#target_link_directories( ${OUTPUT_ELF} PUBLIC
#        D:/local_lib/opencv-454-win/lib
#        )
#target_link_libraries( ${OUTPUT_ELF} PUBLIC
#        "${TORCH_LIBRARIES}"
#        opencv_world454d
#        )
#
##target_link_libraries(dcgan "${TORCH_LIBRARIES}" /usr/local/cuda-11.3/lib64)
#
#if (MSVC)
#    file(GLOB TORCH_DLLS "${TORCH_INSTALL_PREFIX}/lib/*.dll")
#    add_custom_command(TARGET ${OUTPUT_ELF}
#            POST_BUILD
#            COMMAND ${CMAKE_COMMAND} -E copy_if_different
#            ${TORCH_DLLS}
#            $<TARGET_FILE_DIR:${OUTPUT_ELF}>)
#endif (MSVC)
#
#if (MSVC)
#    target_compile_options(${OUTPUT_ELF} PUBLIC /W4)
#else()
#    target_compile_options(${OUTPUT_ELF} PUBLIC -Wall -Wextra -pedantic -Werror)
#endif(MSVC)
