add_library(Data_Struct
            Data_Struct.h
            Data_Struct.cpp
            )
add_library(Sparse_Matrix
            Sparse_Matrix.h 
            Sparse_Matrix.cpp)

target_include_directories(Data_Struct PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(Sparse_Matrix PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Data_Struct PUBLIC Pages)