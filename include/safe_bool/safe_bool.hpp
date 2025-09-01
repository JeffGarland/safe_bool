// SPDX-License-Identifier: Boost Software License, Version 1.0.
// Copyright Jeff Garland 2025

#ifndef SAFE_BOOL_HPP
#define SAFE_BOOL_HPP


#include <concepts>

namespace safe {

class safe_bool
{
    bool value = false;
 public:
    constexpr safe_bool() = default;
    constexpr ~safe_bool() = default;
    constexpr safe_bool(const safe_bool&) = default; //not explicit for operator=
    constexpr safe_bool(bool v) noexcept : value(v) {}
    safe_bool(std::integral auto) = delete; // rm integral conversions
    safe_bool(char*) = delete; //crush char* conversion
    constexpr explicit operator bool() const noexcept { return value; }
    constexpr bool operator==(const safe_bool&) const = default;
};  


} // namespace safe

#endif // SAFE_BOOL_HPP
