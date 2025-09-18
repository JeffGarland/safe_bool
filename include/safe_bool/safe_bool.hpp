// SPDX-License-Identifier: Boost Software License, Version 1.0.
// Copyright Jeff Garland 2025

#ifndef SAFE_BOOL_HPP
#define SAFE_BOOL_HPP

// clang-format off

#if __cplusplus < 202002L
  #error "safe_bool requires C++20 or later"
#endif

#include <concepts>

namespace safe {

  template<typename T>
  concept non_bool_integral = std::integral<T> && !std::same_as<bool, T>;

/** This class is a drop in replacement for regular bool that prevents
 *  any of the strange integral conversions allowed by C++. It is
 *  somewhat astonishing to learn that all the following compiles:
 *@code
     bool b = "false"; // sets to true
     safe_bool b = "false"; // compile error
     bool b1 = 1.5f;   // wut would it mean?
     // more https://godbolt.org/z/jY61zEzns
 *@endcode
 *   Some warnings help, but the compilers aren't consistent.
 *   The language should have a profile that eliminates these, but
 *   until then if you really want a bool in an interface this class
 *   is a better option causing the ridiculous conversions to fail
 *   at compile time.
 */
class safe_bool
{
    bool value = false;
 public:
    constexpr safe_bool() = default;
    constexpr ~safe_bool() = default;
    constexpr safe_bool(const safe_bool&) = default;
    constexpr safe_bool(bool v) noexcept : value(v) {} //not explicit for operator=
    constexpr safe_bool(non_bool_integral auto) = delete ("integral conversion denied");
    constexpr safe_bool(float) = delete("float conversion denied");
    constexpr safe_bool(char*) = delete; // char* conversion
    constexpr safe_bool& operator=(const safe_bool& other) = default;

    constexpr explicit operator bool() const noexcept { return value; }

    constexpr bool operator==(const safe_bool&) const = default;
    template<typename B>
    constexpr bool operator==(B b) const
      requires std::is_same_v<bool, B>
    { return b == this->value; }

    constexpr safe_bool operator&&(const safe_bool& other) const noexcept {
       return safe_bool(this->value && other.value);
    }
    constexpr safe_bool operator||(const safe_bool& other) const noexcept {
       return safe_bool(this->value || other.value);
    }
};  


} // namespace safe

#endif // SAFE_BOOL_HPP
