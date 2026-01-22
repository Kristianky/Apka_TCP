add_library(ButtonLib
            Button.cpp
            Button.h)
add_library(MouseLib
            Mouse.h
            Mouse.cpp)
target_include_directories(ButtonLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(ButtonLib PUBLIC MouseLib)