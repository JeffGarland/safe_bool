// SPDX-License-Identifier: Boost Software License, Version 1.0.
// Copyright Jeff Garland 2025

#include <safe_bool/safe_bool.hpp>

// clang-format off

#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>

using namespace safe;

bool f( safe_bool sb) { return bool(sb); }

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
  safe_bool sb8{};
  REQUIRE( !sb8 ); // false
  bool b = f({});
  REQUIRE( !b ); // false
  safe_bool sb9 = sb7 && sb8;
  REQUIRE( !sb9 );
  safe_bool sb10 = sb7 || sb8;
  REQUIRE( sb10 );
  safe_bool sb11 = sb7 || (sb8 && sb10);
  REQUIRE( sb11 );

  // if ( sb4 < sb6 ) { println("good"); } // no conversion


}

