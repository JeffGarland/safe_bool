# SPDX-License-Identifier: Boost Software License, Version 1.0.
# Copyright Jeff Garland 2025


include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.8.0
)
FetchContent_MakeAvailable(Catch2)

include(Catch)

add_executable(safe_bool.tests.basic)
target_sources(safe_bool.tests.basic PRIVATE basic.test.cpp)
target_link_libraries(
    safe_bool.tests.basic
    PRIVATE safe_bool Catch2::Catch2WithMain
)

