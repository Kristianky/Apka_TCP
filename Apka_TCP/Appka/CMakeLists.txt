add_executable(Executable WIN32 main.cpp)

# Definície pre Unicode
target_compile_definitions(Executable PRIVATE UNICODE _UNICODE)

# Linker flag pre MinGW, aby hľadal wWinMain
if(MINGW)
    target_link_options(Executable PRIVATE "-municode")
endif()

