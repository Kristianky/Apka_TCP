set (TCP_HEADERS
    "TCP_Client.h")
set (TCP_LIBS
    "TCP_Client.cpp")

add_library(TCPClient
           ${TCP_HEADERS}
           ${TCP_LIBS})
target_include_directories(TCPClient PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(TCPClient PUBLIC Pages)