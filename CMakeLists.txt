cmake_minimum_required(VERSION 3.16)
project(
    wifi_password
    VERSION 0.0.1
    DESCRIPTION "Quickly fetch WIFI password"
    LANGUAGES C
)
configure_file(
    ${CMAKE_CURRENT_LIST_DIR}/in/project_info.h.in
    ${CMAKE_CURRENT_LIST_DIR}/include_config/project_info.h
)
add_executable(
    wifi_password
    ${CMAKE_CURRENT_LIST_DIR}/include_config/project_info.h
    ${CMAKE_CURRENT_LIST_DIR}/main.c
)
target_include_directories(
    wifi_password
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include_config
)
target_compile_features(
    wifi_password
    PUBLIC
    c_std_11
)
target_compile_options(wifi_password PRIVATE
    $<$<OR:$<C_COMPILER_ID:Clang>,$<C_COMPILER_ID:AppleClang>,$<C_COMPILER_ID:GNU>>:  -Wall
                                                                                            -Werror
                                                                                            -pedantic
                                                                                            -Wextra
                                                                                            -pedantic-errors
                                                                                            -Wconversion
                                                                                            -Wsign-conversion
                                                                                            -Wfatal-errors>
    $<$<C_COMPILER_ID:MSVC>: /W4>)
