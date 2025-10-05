add_library(Pages
            Pages.h
            Pages.cpp
            )
target_include_directories(Pages PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(Pages PUBLIC Sparse_Matrix)