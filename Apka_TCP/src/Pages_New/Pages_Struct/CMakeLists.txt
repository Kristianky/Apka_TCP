add_library(ButtonLib
            Button.cpp
            Button.h)
add_library(MouseLib
            Mouse.h
            Mouse.cpp)
add_library(EditLib
            Edit.h
            Edit.cpp)
target_include_directories(ButtonLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(ButtonLib PUBLIC MouseLib)
target_include_directories(EditLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})