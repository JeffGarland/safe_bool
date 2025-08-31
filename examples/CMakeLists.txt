# SPDX-License-Identifier: Boost Software License, Version 1.0.
# Copyright Jeff Garland 2025



set(ALL_EXAMPLES safe_bool_usage)

message("Examples to be built: ${ALL_EXAMPLES}")

add_executable(safe_bool_usage)
target_sources(safe_bool_usage PRIVATE safe_bool_usage.cpp)
target_link_libraries(safe_bool_usage PRIVATE safe_bool)
