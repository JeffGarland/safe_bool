// SPDX-License-Identifier: Boost Software License, Version 1.0.
// Copyright Jeff Garland 2025

#include <safe_bool/safe_bool.hpp>

// clang-format off

#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>

using namespace safe;

TEST_CASE("safe bool construction,comparison, conversion", "[constructors-comparison]") {

  safe_bool sb4(true);
  REQUIRE( sb4 == true );
  safe_bool sb5; //false
  REQUIRE( !sb5 );
  safe_bool sb6 = true; //copy-assign
  REQUIRE( sb6 );
  REQUIRE( sb4 == sb6 );
  REQUIRE( sb4 != sb5 );
  safe_bool sb7 = sb6;
  REQUIRE( sb7 );
 // if ( sb4 < sb6 ) { println("good"); } // no conversion


}

