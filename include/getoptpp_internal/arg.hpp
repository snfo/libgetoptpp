#ifndef __GETOPTPP_ARG_HPP__
#define __GETOPTPP_ARG_HPP__

namespace getoptpp {

enum class arg : int {
  no,       // corresponds with "no_argument"
  required, // corresponds with "required_argument"
  optional, // corresponds with "optional_argument"
};

} // namespace getoptpp

#endif // __GETOPTPP_ARG_HPP__
