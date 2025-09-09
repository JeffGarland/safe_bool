// SPDX-License-Identifier: Boost Software License, Version 1.0.
// Copyright Jeff Garland 2025

#include <safe_bool/safe_bool.hpp>

using namespace safe;

int main()
{
  float f = 1.5;
  bool b(f);
  safe_bool sb(f); //compile error
}
