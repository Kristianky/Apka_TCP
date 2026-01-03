set(PAGES_LIBS
    "Pages.cpp"
    "Sparse_Matrix.cpp"
    "Polynomial.cpp"
    "Linked_List.cpp")
set(PAGES_HEADERS
    "Pages.h"
    "Sparse_Matrix.h"
    "Polynomial.h"
     "Linked_List.h")

add_library(Sparse_Matrix
            Sparse_Matrix.cpp
            Sparse_Matrix.h)
add_library(Pages
            ${PAGES_LIBS}
            ${PAGES_HEADERS}
            )

target_include_directories(Pages PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(Pages PUBLIC Sparse_Matrix)
target_link_libraries(Pages PUBLIC TCPClient)