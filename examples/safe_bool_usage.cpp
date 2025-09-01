// SPDX-License-Identifier: Boost Software License, Version 1.0.
// Copyright Jeff Garland 2025

#include <safe_bool/safe_bool.hpp>
#include <print>

// initial impl: https://godbolt.org/z/a8Y3nvenc 

using namespace safe;

// output
// size bool: 1
// size safe_bool: 1
// good
// good
// good
// good
// good

int main()
{

  using std::println;
  println("size bool: {}", sizeof(bool));
  println("size safe_bool: {}", sizeof(safe_bool));

  //hits deleted constructor
  //safe_bool sb1("bar"); 
  //safe_bool sb2{"bar"};
  //safe_bool sb3 = "bar"; 
  //safe_bool sb3 = 1; //int
  safe_bool sb4(true);
  if (sb4) { println( "good"); }
  safe_bool sb5; //false
  if (!sb5) { println( "good"); }
  safe_bool sb6 = true;
  if (sb6) { println("good"); }
  if ( sb4 == sb6 ) { println("good"); }
  if ( sb4 != sb5 ) { println("good"); }
  // if ( sb4 < sb6 ) { println("good"); } // no conversion
  
}  
