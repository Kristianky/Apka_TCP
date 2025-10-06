

add_library(Data_Struct
            Data_Struct.h
            Data_Struct.cpp
            )


target_include_directories(Data_Struct PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Data_Struct PUBLIC Pages)