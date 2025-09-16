
add_executable(MojaApkaEXE WIN32 main.cpp)

# Definície pre Unicode
target_compile_definitions(MojaApkaEXE PRIVATE UNICODE _UNICODE)
target_link_libraries(MojaApkaEXE PRIVATE MojaApkaLib Main_Page Pages)

# Linker flag pre MinGW, aby hľadal wWinMain
if(MINGW)
    target_link_options(MojaApkaEXE PRIVATE "-municode")
endif()

