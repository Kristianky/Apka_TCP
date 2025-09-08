add_library(Pages
            Pages.h
            Pages.cpp
            )
target_include_directories(Pages PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(Main_Page
            Page_Main.h
            Page_Main.cpp)
target_include_directories(Main_Page PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(Main_Page PUBLIC Pages)
