# SPDX-License-Identifier: Boost Software License, Version 1.0.
# Copyright Jeff Garland 2025

cmake_minimum_required(VERSION 3.28...4.1)

project(
    safe_bool
    library
    DESCRIPTION "Type to replace C++ bool which is subject to bad conversions"
    LANGUAGES CXX
    VERSION 2.1.1
)

# [CMAKE.SKIP_TESTS]
option(
    SAFE_BOOL_BUILD_TESTS
    "Enable building tests and test infrastructure. Default: ${PROJECT_IS_TOP_LEVEL}. Values: { ON, OFF }."
    ${PROJECT_IS_TOP_LEVEL}
)

# [CMAKE.SKIP_EXAMPLES]
option(
    SAFE_BOOL_BUILD_EXAMPLES
    "Enable building examples. Default: ${PROJECT_IS_TOP_LEVEL}. Values: { ON, OFF }."
    ${PROJECT_IS_TOP_LEVEL}
)

option(
    SAFE_BOOL_INSTALL_CONFIG_FILE_PACKAGE
    "Enable creating and installing a CMake config-file package. Default: ${PROJECT_IS_TOP_LEVEL}. Values: { ON, OFF }."
    ${PROJECT_IS_TOP_LEVEL}
)

include(CTest)

add_subdirectory(src/beman/safe_bool)

if(SAFE_BOOL_BUILD_TESTS)
    add_subdirectory(tests/beman/safe_bool)
endif()

if(SAFE_BOOL_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()
