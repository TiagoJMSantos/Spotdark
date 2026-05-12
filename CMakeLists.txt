cmake_minimum_required(VERSION 3.15)
project(AppLauncher 
    VERSION 1.0.0
    DESCRIPTION "SpotDark Edition - CLI App Launcher"
    LANGUAGES CXX
)
 
# ============================================================================
# CONFIGURAÇÃO DO PROJETO
# ============================================================================
 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
 
# Diretórios
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
 
# ============================================================================
# VARIÁVEIS DE COMPILAÇÃO
# ============================================================================
 
# Flags de compilação por compilador
if(MSVC)
    # Visual Studio
    add_compile_options(
        /W4                 # Warning level 4
        /WX                 # Treat warnings as errors (opcional)
        /permissive-        # Conformidade C++ strict
    )
    # Debug info
    add_compile_options($<$<CONFIG:Debug>:/Zi>)
    add_link_options($<$<CONFIG:Debug>:/DEBUG>)
else()
    # GCC / Clang
    add_compile_options(
        -Wall               # Todos os warnings
        -Wextra             # Extra warnings
        -Wpedantic          # Pedantic warnings
        -Wconversion        # Conversão implícita
        -Wunused            # Variáveis não utilizadas
        -fPIC               # Position independent code
    )
    
    # Debug symbols
    add_compile_options($<$<CONFIG:Debug>:-g3>)
    add_compile_options($<$<CONFIG:Release>:-O3>)
endif()
 
# ============================================================================
# FICHEIROS FONTE
# ============================================================================
 
set(SOURCES
    main.cpp
    #launcher.cpp
    print.c++
    systemDetection.c++
    appFinder.c++
)
 
set(HEADERS
    appFinder.h
    systemDetection.h
    print.h
)
 
# ============================================================================
# TARGET PRINCIPAL
# ============================================================================
 
add_executable(app-launcher ${SOURCES} ${HEADERS})
 
# Include directories
target_include_directories(app-launcher 
    PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/utils
)
 
# ============================================================================
# PLATAFORMA ESPECÍFICA
# ============================================================================
 
if(WIN32)
    target_compile_definitions(app-launcher PRIVATE _WIN32_WINNT=0x0601)
    target_link_libraries(app-launcher PRIVATE kernel32 shell32 advapi32)
    message(STATUS "Plataforma: Windows")
elseif(APPLE)
    target_compile_definitions(app-launcher PRIVATE _DARWIN_C_SOURCE)
    message(STATUS "Plataforma: macOS")
elseif(UNIX AND NOT APPLE)
    target_compile_definitions(app-launcher PRIVATE _GNU_SOURCE)
    message(STATUS "Plataforma: Linux")
endif()
 
# ============================================================================
# PROPRIEDADES DO TARGET
# ============================================================================
 
set_target_properties(app-launcher PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
 
# ============================================================================
# OPÇÕES DE BUILD
# ============================================================================
 
option(BUILD_DEBUG "Build with debug symbols" ON)
option(BUILD_RELEASE "Build with optimizations" OFF)
option(ENABLE_WARNINGS_AS_ERRORS "Treat warnings as errors" OFF)
 
if(ENABLE_WARNINGS_AS_ERRORS AND MSVC)
    target_compile_options(app-launcher PRIVATE /WX)
elseif(ENABLE_WARNINGS_AS_ERRORS AND NOT MSVC)
    target_compile_options(app-launcher PRIVATE -Werror)
endif()
 
# ============================================================================
# CONFIGURAÇÃO DE DEBUG
# ============================================================================
 
if(BUILD_DEBUG)
    set(CMAKE_BUILD_TYPE Debug)
    target_compile_definitions(app-launcher PRIVATE DEBUG_BUILD=1)
    message(STATUS "Build type: Debug")
else()
    set(CMAKE_BUILD_TYPE Release)
    message(STATUS "Build type: Release")
endif()
 
# ============================================================================
# INFORMAÇÕES DE BUILD
# ============================================================================
 
message(STATUS "========================================")
message(STATUS "App Launcher - SpotDark Edition")
message(STATUS "========================================")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "Compiler: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Output: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message(STATUS "========================================")