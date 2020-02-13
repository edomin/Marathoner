cmake_minimum_required(VERSION 3.1.3)
project(uc)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include(options)

if (MTR_PLUGINS AND (CMAKE_SYSTEM_NAME STREQUAL Emscripten))
    message(SEND_ERROR "Plugin-based build currently not supported for html5 platform")
    set(MTR_PLUGINS OFF)
endif()

set(CMAKE_C_FLAGS
 "${CMAKE_C_FLAGS} -Wall -Wextra -Wno-unused-parameter -Wshadow -Werror -mmmx \
 -msse -msse2 -mfpmath=sse"
)
if (MTR_MORE_WARNINGS)
    set(CMAKE_C_FLAGS
     "${CMAKE_C_FLAGS} -Wbad-function-cast -Wcast-qual \
     -Wdeclaration-after-statement -Wdouble-promotion -Wduplicated-cond \
     -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness \
     -Winit-self -Wlogical-op -Wmisleading-indentation -Wnull-dereference \
     -Wredundant-decls -Wshift-overflow=2 -Wswitch-default -Wuninitialized \
     -Wundef -Wvla"
)
endif()

if (MTR_PLUGINS)
    add_definitions("-DMTR_MOD_PLUGIN")
else()
    add_definitions("-DMTR_MOD_STATIC")
endif()

message(STATUS ${CMAKE_C_FLAGS})
message(STATUS ${CMAKE_C_FLAGS_RELEASE})
message(STATUS ${CMAKE_C_FLAGS_DEBUG})
