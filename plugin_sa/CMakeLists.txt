set(PROJECT_NAME plugin_sa)

################################################################################
# Source groups
################################################################################
file(GLOB_RECURSE PROJECT_FILES "${CMAKE_CURRENT_SOURCE_DIR}/**.h" "${CMAKE_CURRENT_SOURCE_DIR}/**.cpp")
file(GLOB_RECURSE SDK_SHARED_FILES "${CMAKE_CURRENT_SOURCE_DIR}/../shared/**.h" "${CMAKE_CURRENT_SOURCE_DIR}/../shared/**.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/../shared/**.rc")
file(GLOB_RECURSE HOOKING_FILES "${CMAKE_CURRENT_SOURCE_DIR}/../hooking/**.h" "${CMAKE_CURRENT_SOURCE_DIR}/../hooking/**.cpp")
file(GLOB_RECURSE INJECTOR_FILES "${CMAKE_CURRENT_SOURCE_DIR}/../injector/**.hpp")
file(GLOB_RECURSE SAFETYHOOK_FILES "${CMAKE_CURRENT_SOURCE_DIR}/../safetyhook/**.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/../safetyhook/**.hpp" "${CMAKE_CURRENT_SOURCE_DIR}/../safetyhook/**.c")

set(ALL_FILES
    ${PROJECT_FILES}
    ${SDK_SHARED_FILES}
    ${HOOKING_FILES}
    ${INJECTOR_FILES}
    ${SAFETYHOOK_FILES}
)

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} STATIC ${ALL_FILES})

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE plugin_sa)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)
string(TOLOWER "${CMAKE_VS_PLATFORM_NAME}" CMAKE_VS_PLATFORM_NAME_LOWER)
################################################################################
# Target name
################################################################################
if(CMAKE_VS_PLATFORM_NAME_LOWER STREQUAL "mixed platforms")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_RELEASE "plugin"
        TARGET_NAME_DEBUG  "plugin_d"
    )
elseif(CMAKE_VS_PLATFORM_NAME_LOWER STREQUAL "win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_RELEASE "plugin"
        TARGET_NAME_DEBUG  "plugin_d"
    )
elseif(CMAKE_VS_PLATFORM_NAME_LOWER STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_RELEASE "plugin"
        TARGET_NAME_DEBUG  "plugin_d"
    )
elseif(CMAKE_VS_PLATFORM_NAME_LOWER STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_RELEASE "plugin"
        TARGET_NAME_DEBUG  "plugin_d"
    )
endif()
################################################################################
# Output directory
################################################################################
if(CMAKE_VS_PLATFORM_NAME_LOWER STREQUAL "mixed platforms")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/output/lib/"
        OUTPUT_DIRECTORY_DEBUG  "${CMAKE_SOURCE_DIR}/output/lib/"
    )
elseif(CMAKE_VS_PLATFORM_NAME_LOWER STREQUAL "win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/output/lib/"
        OUTPUT_DIRECTORY_DEBUG  "${CMAKE_SOURCE_DIR}/output/lib/"
    )
elseif(CMAKE_VS_PLATFORM_NAME_LOWER STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/output/lib/"
        OUTPUT_DIRECTORY_DEBUG  "${CMAKE_SOURCE_DIR}/output/lib/"
    )
endif()
if(CMAKE_VS_PLATFORM_NAME_LOWER STREQUAL "mixed platforms")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        INTERPROCEDURAL_OPTIMIZATION_RELEASE "TRUE"
    )
elseif(CMAKE_VS_PLATFORM_NAME_LOWER STREQUAL "win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        INTERPROCEDURAL_OPTIMIZATION_RELEASE "TRUE"
    )
elseif(CMAKE_VS_PLATFORM_NAME_LOWER STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        INTERPROCEDURAL_OPTIMIZATION_RELEASE "TRUE"
    )
elseif(CMAKE_VS_PLATFORM_NAME_LOWER STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        INTERPROCEDURAL_OPTIMIZATION_RELEASE "TRUE"
    )
endif()
###############################################################################
# MSVC runtime library
###############################################################################
string(CONCAT "MSVC_RUNTIME_LIBRARY_STR"
    $<$<CONFIG:Release>:
        MultiThreaded
    >
    $<$<CONFIG:Debug>:
        MultiThreadedDebug
    >
    $<$<NOT:$<OR:$<CONFIG:Release>,$<CONFIG:Debug>>>:${MSVC_RUNTIME_LIBRARY_DEFAULT}>
)
set_target_properties(${PROJECT_NAME} PROPERTIES MSVC_RUNTIME_LIBRARY ${MSVC_RUNTIME_LIBRARY_STR})

################################################################################
# Include directories
################################################################################
if(CMAKE_VS_PLATFORM_NAME_LOWER STREQUAL "mixed platforms")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/game_sa;"
        "${CMAKE_CURRENT_SOURCE_DIR}/game_sa/rw;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../shared/game;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../safetyhook"
    )
elseif(CMAKE_VS_PLATFORM_NAME_LOWER STREQUAL "win32")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/game_sa;"
        "${CMAKE_CURRENT_SOURCE_DIR}/game_sa/rw;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../shared/game;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../safetyhook"
    )
elseif(CMAKE_VS_PLATFORM_NAME_LOWER STREQUAL "x64")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/game_sa;"
        "${CMAKE_CURRENT_SOURCE_DIR}/game_sa/rw;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../shared/game;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../safetyhook"
    )
elseif(CMAKE_VS_PLATFORM_NAME_LOWER STREQUAL "x86")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/game_sa;"
        "${CMAKE_CURRENT_SOURCE_DIR}/game_sa/rw;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../shared/game;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../safetyhook"
    )
endif()

################################################################################
# Compile definitions
################################################################################
if(CMAKE_VS_PLATFORM_NAME_LOWER STREQUAL "mixed platforms")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "_CRT_SECURE_NO_WARNINGS;"
        "_CRT_NON_CONFORMING_SWPRINTFS;"
        "_SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING;"
        "_DX9_SDK_INSTALLED;"
        "GTASA;"
        "PLUGIN_SGV_10US;"
        "RW;"
        "_MBCS"
    )
elseif(CMAKE_VS_PLATFORM_NAME_LOWER STREQUAL "win32")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "_CRT_SECURE_NO_WARNINGS;"
        "_CRT_NON_CONFORMING_SWPRINTFS;"
        "_SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING;"
        "_DX9_SDK_INSTALLED;"
        "GTASA;"
        "PLUGIN_SGV_10US;"
        "RW;"
        "_MBCS"
    )
elseif(CMAKE_VS_PLATFORM_NAME_LOWER STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "_CRT_SECURE_NO_WARNINGS;"
        "_CRT_NON_CONFORMING_SWPRINTFS;"
        "_SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING;"
        "_DX9_SDK_INSTALLED;"
        "GTASA;"
        "PLUGIN_SGV_10US;"
        "RW;"
        "_MBCS"
    )
elseif(CMAKE_VS_PLATFORM_NAME_LOWER STREQUAL "x86")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "_CRT_SECURE_NO_WARNINGS;"
        "_CRT_NON_CONFORMING_SWPRINTFS;"
        "_SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING;"
        "_DX9_SDK_INSTALLED;"
        "GTASA;"
        "PLUGIN_SGV_10US;"
        "RW;"
        "_MBCS"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if(CMAKE_VS_PLATFORM_NAME_LOWER STREQUAL "mixed platforms")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Debug>:
                /Od;
                /ZI
            >
            /std:c++latest;
            /W3;
            /wd4073;
            /sdl-;
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    elseif(CMAKE_VS_PLATFORM_NAME_LOWER STREQUAL "win32")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Debug>:
                /Od;
                /ZI
            >
            /std:c++latest;
            /W3;
            /wd4073;
            /sdl-;
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    elseif(CMAKE_VS_PLATFORM_NAME_LOWER STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Debug>:
                /Od;
                /Zi
            >
            /std:c++latest;
            /W3;
            /wd4073;
            /sdl-;
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    elseif(CMAKE_VS_PLATFORM_NAME_LOWER STREQUAL "x86")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Debug>:
                /Od;
                /ZI
            >
            /std:c++latest;
            /W3;
            /wd4073;
            /sdl-;
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    endif()
    if(CMAKE_VS_PLATFORM_NAME_LOWER STREQUAL "mixed platforms")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:
                /OPT:REF;
                /OPT:ICF
            >
            /MACHINE:X86;
            /SUBSYSTEM:WINDOWS
        )
    elseif(CMAKE_VS_PLATFORM_NAME_LOWER STREQUAL "win32")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:
                /OPT:REF;
                /OPT:ICF
            >
            /MACHINE:X86;
            /SUBSYSTEM:WINDOWS
        )
    elseif(CMAKE_VS_PLATFORM_NAME_LOWER STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:
                /OPT:REF;
                /OPT:ICF
            >
            /MACHINE:X86;
            /SUBSYSTEM:WINDOWS
        )
    elseif(CMAKE_VS_PLATFORM_NAME_LOWER STREQUAL "x86")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:
                /OPT:REF;
                /OPT:ICF
            >
            /MACHINE:X86;
            /SUBSYSTEM:WINDOWS
        )
    endif()
endif()

install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/" DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
    FILES_MATCHING
    PATTERN "*.*"
)

# Устанавливаем файлы из каталога ../shared
install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../shared/" DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/shared"
    FILES_MATCHING
    PATTERN "*.*"
)

# Устанавливаем файлы из каталога ../safetyhook
install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../safetyhook/" DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/safetyhook"
    FILES_MATCHING
    PATTERN "*.*"
)

# Устанавливаем файлы из каталога ../injector
install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../injector/" DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/injector"
    FILES_MATCHING
    PATTERN "*.*"
)

# Устанавливаем файлы из каталога ../stb
install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../stb/" DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/stb"
    FILES_MATCHING
    PATTERN "*.*"
)

# Устанавливаем файлы из каталога ../modutils
install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../modutils/" DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/modutils"
    FILES_MATCHING
    PATTERN "*.*"
)

# Устанавливаем файлы из каталога ../hooking
install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../hooking/" DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/hooking"
    FILES_MATCHING
    PATTERN "*.*"
)