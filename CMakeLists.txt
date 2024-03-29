cmake_minimum_required(VERSION 3.15)
project(rnbo.example)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS OFF)

if (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    message("apple config")
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    if (CMAKE_CROSSCOMPILING)
        message("cross compile config")
    else ()
        set(CMAKE_C_COMPILER arm-linux-gnueabihf-gcc)
        set(CMAKE_CXX_COMPILER arm-linux-gnueabihf-g++)
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mcpu=cortex-a17 -mfloat-abi=hard -mfpu=neon-vfpv4")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mcpu=cortex-a17 -mfloat-abi=hard -mfpu=neon-vfpv4")
    endif ()
endif ()


add_subdirectory(juce)

add_subdirectory(modules)

# set(CMAKE_FOLDER .)
function(_juce_add_pips)
    file(GLOB headers
            CONFIGURE_DEPENDS LIST_DIRECTORIES false
            "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

    if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    elseif (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    endif ()

    foreach (header IN ITEMS ${headers})
        juce_add_pip(${header} added_target)
        target_link_libraries(${added_target} PUBLIC
                juce::juce_recommended_config_flags
                juce::juce_recommended_lto_flags
                juce::juce_recommended_warning_flags)
    endforeach ()
endfunction()

