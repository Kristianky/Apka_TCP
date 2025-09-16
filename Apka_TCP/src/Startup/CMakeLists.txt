add_library(MojaApkaLib
            Moja_Apka.cpp
            Moja_Apka.h
            )
target_include_directories(MojaApkaLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(MojaApkaLib PUBLIC Pages)
target_link_libraries(MojaApkaLib PUBLIC Main_Page)
