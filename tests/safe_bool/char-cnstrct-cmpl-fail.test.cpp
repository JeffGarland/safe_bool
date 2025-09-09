// SPDX-License-Identifier: Boost Software License, Version 1.0.
// Copyright Jeff Garland 2025

#include <safe_bool/safe_bool.hpp>

using namespace safe;

int main()
{
  bool b('a');
  safe_bool sb('a'); //compile error
}
