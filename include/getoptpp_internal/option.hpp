#ifndef __GETOPTPP_OPTION_HPP__
#define __GETOPTPP_OPTION_HPP__

#include <getoptpp_internal/arg.hpp>

namespace getoptpp {

class option {
public:
  // The following static methods map directly to the global
  // variables optarg, optind, opterr, and optopt respectively.
  static const char *arg();
  static int ind();
  static int err();
  static int opt();

  option() = default;

  option(const char *long_name) : long_name_{long_name} {}

  option(const char *long_name, int short_name)
      : long_name_{long_name}, short_name_{short_name}
  {
  }

  option(const char *long_name, int short_name, enum arg has_arg)
      : long_name_{long_name}, arg_{has_arg}, short_name_{short_name}
  {
  }

  // Traditional getopt style option definition:
  option(const char *long_name, enum arg has_arg, int *flag, int short_name)
      : long_name_{long_name},
        arg_{has_arg},
        flag_{flag},
        short_name_{short_name}
  {
  }

private:
  // NOTE: The following variables must be declared in the following order!
  //       A pointer to this object must be able to be casted to a pointer to
  //       the OG `option' struct from the C getopt library.
  const char *long_name_ = nullptr;
  enum arg arg_ = arg::no;
  int *flag_ = nullptr;
  int short_name_ = 0;
};

} // namespace getoptpp

#endif // __GETOPTPP_OPTION_HPP__
