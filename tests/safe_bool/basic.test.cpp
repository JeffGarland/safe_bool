// SPDX-License-Identifier: Boost Software License, Version 1.0.
// Copyright Jeff Garland 2025

#include <beman/safe_bool/safe_bool.hpp>


// clang-format off

#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>

TEST_CASE("safe bool construction", "[constructors]") {
    bool triggered = false;


    REQUIRE(triggered == false);
}

