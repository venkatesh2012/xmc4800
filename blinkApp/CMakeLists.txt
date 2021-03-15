cmake_minimum_required(VERSION 3.6)

set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

project(blinkApp LANGUAGES C CXX)

option(USE_FREERTOS "Use FreeRTOS" OFF)

set(DEVICE_CONFIG_DIR ${CMAKE_SOURCE_DIR}/libs/CMSIS/Device/Infenion/)

include(TOOLCHAIN_arm_none_eabi_cortex.cmake)

# Set XMC SoC specific variables
set(XMC_DEFINES "-DXMC4800_F144x2048")

set(XMC_LIB ${CMAKE_SOURCE_DIR}/libs/XMCLib)

set(OTHER_SRC_FILES "${DEVICE_CONFIG_DIR}/system_XMC4800.c")

# set compiler optimisations
set(COMPILER_OPTIMISATION "-g -O0")

# add startup and linker file
set(STARTUP_ASM_FILE "${CMAKE_SOURCE_DIR}/config/startup/startup_XMC4800.S")
set_property(SOURCE ${STARTUP_ASM_FILE} PROPERTY LANGUAGE ASM)

set(LINKER_FILE "${CMAKE_SOURCE_DIR}/config/linkerfiles/linker_script.ld")

# Only build for arm-none-eabi
if (NOT CMAKE_SYSTEM_PROCESSOR STREQUAL "arm-none-eabi")
    message(FATAL_ERROR "Invalid CMAKE_SYSTEM_PROCESSOR: ${CMAKE_SYSTEM_PROCESSOR}")
endif()

# sets the invalid -O3 flag on the assembler.
set(CMAKE_BUILD_TYPE Debug)

# enable asm for stm startup.s file
enable_language(ASM)

set (CMAKE_C_FLAGS "-g -mthumb -Wall -std=gnu99 -march=armv7-m" CACHE INTERNAL "c compiler flags")
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -gdwarf-2 -O0")

set (CMAKE_ASM_FLAGS "-g -mthumb" CACHE INTERNAL "asm compiler flags")

set (CMAKE_EXE_LINKER_FLAGS " --specs=nosys.specs " CACHE INTERNAL "executable linker flags")
set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -T${LINKER_FILE}")

message(STATUS "System Processor      : ${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS
    "BUILD FLAGS:\n"
    "   c flags         : ${CMAKE_C_FLAGS}\n"
    "   c++ flags       : ${CMAKE_CXX_FLAGS}\n"
    "   asm flags       : ${CMAKE_ASM_FLAGS}\n"
    "   ld flags        : ${CMAKE_EXE_LINKER_FLAGS}\n"
    "   optimizations   : ${COMPILER_OPTIMISATION}\n"
    "   CMSIS           : ${CMSIS_DIR}\n"
    "   HAL library     : ${XMC_LIB}\n"
    "   FreeRTOS        : ${FREERTOS_INC_DIR}\n"
)

include_directories(include ${XMC_LIB}/inc)

aux_source_directory (./src DIR_USER_SRCS)
aux_source_directory (${XMC_LIB}/src DIR_LIB_SRCS)

file(GLOB C_SOURCE ${OTHER_SRC_FILES} ${DIR_USER_SRCS} ${DIR_LIB_SRCS})

set_source_files_properties(${C_SOURCE}
    PROPERTIES COMPILE_FLAGS ${XMC_DEFINES}
)


set(EXTERNAL_EXECUTABLES ${STARTUP_ASM_FILE})

add_executable(${PROJECT_NAME}.elf
    ${C_SOURCE}
    ${EXTERNAL_EXECUTABLES}
)

if (EXTERNAL_DEPENDENCIES)
    add_dependencies(${PROJECT_NAME}.elf
        ${EXTERNAL_DEPENDENCIES}
    )
endif()

if (EXTERNAL_LIBS)
    target_link_libraries(${PROJECT_NAME}.elf
        ${EXTERNAL_LIBS}
    )
endif()

add_custom_target ( ${PROJECT_NAME}.hex ALL
    DEPENDS ${PROJECT_NAME}.elf 
    COMMAND ${CMAKE_OBJCOPY} -O ihex ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
    COMMENT "Generating ${PROJECT_NAME}.hex"
)
add_custom_target ( ${PROJECT_NAME}.bin ALL
    DEPENDS ${PROJECT_NAME}.elf 
    COMMAND ${CMAKE_OBJCOPY} -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.bin
    COMMENT "Generating ${PROJECT_NAME}.bin"
)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
    COMMAND ${CMAKE_SIZE} --format=berkeley "${PROJECT_NAME}.elf")



