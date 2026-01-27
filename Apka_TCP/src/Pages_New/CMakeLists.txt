add_subdirectory(Pages_Struct)
add_library(PagesVirtualLib
            PagesVirtual.h
            PagesVirtual.cpp)
add_library(TCP_PageLib
            TCP_Page.h
            TCP_Page.cpp)
target_include_directories(PagesVirtualLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(TCP_PageLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(PagesVirtualLib PUBLIC TCPClient)
target_link_libraries(TCP_PageLib PUBLIC PagesVirtualLib)
target_link_libraries(PagesVirtualLib PUBLIC ButtonLib)
target_link_libraries(PagesVirtualLib PUBLIC EditLib)
