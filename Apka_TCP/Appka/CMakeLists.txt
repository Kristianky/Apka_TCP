add_executable(MojaApkaEXE WIN32 main.cpp)

# Definície pre Unicode
target_compile_definitions(MojaApkaEXE PRIVATE UNICODE _UNICODE)
target_include_directories(MojaApkaEXE PRIVATE ${PROJECT_SOURCE_DIR}/src)
# Linker flag pre MinGW, aby hľadal wWinMain
if(MINGW)
    target_link_options(MojaApkaEXE PRIVATE "-municode")
endif()

