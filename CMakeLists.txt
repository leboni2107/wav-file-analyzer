cmake_minimum_required(VERSION 4.1)
project(wav-file-analyzer VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(wav-file-analyzer STATIC
        library.cpp
        library.h
)

target_include_directories(wav-file-analyzer PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS 9.0)
    target_link_libraries(wav-file-analyzer PUBLIC stdc++fs)
endif()

install(TARGETS wav-file-analyzer
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
)

install(FILES library.h
        DESTINATION include
)
