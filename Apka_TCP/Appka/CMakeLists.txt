
# definícia targetu
add_executable(MojaApkaEXE WIN32
    main.cpp
    # ďalšie .cpp súbory sem
)



set_target_properties(MojaApkaEXE PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}
)
# include priečinok s hlavičkami
target_include_directories(MojaApkaEXE PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Definície pre Unicode
target_compile_definitions(MojaApkaEXE PRIVATE UNICODE _UNICODE)

# Linkovanie knižníc / podprojektov
target_link_libraries(MojaApkaEXE PRIVATE MojaApkaLib Main_Page Pages)

# Linker flag pre MinGW, aby hľadal wWinMain
if(MINGW)
    target_link_options(MojaApkaEXE PRIVATE "-municode")
endif()

