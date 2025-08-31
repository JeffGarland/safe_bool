# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

set(ALL_EXAMPLES safe_bool_usage)

message("Examples to be built: ${ALL_EXAMPLES}")

add_executable(safe_bool_usage)
target_sources(safe_bool_usage PRIVATE safe_bool_usage.cpp)
target_link_libraries(safe_bool_usage PRIVATE safe_bool)
