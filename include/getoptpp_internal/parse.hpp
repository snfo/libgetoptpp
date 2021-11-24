#ifndef __GETOPTPP_PARSE_HPP__
#define __GETOPTPP_PARSE_HPP__

namespace getoptpp {

class option;

// Behaves exactly like getopt(3)
int parse(int argc, char *const argv[], const char *opt_string);

// Behaves exactly like getopt_long(3)
int parse(int argc, char *const *argv, const char *opt_string,
          const option *options, int *index = nullptr);

// Behaves exactly like getopt_long_only(3)
int parse_long(int argc, char *const *argv, const char *opt_string,
               const option *options, int *index = nullptr);

} // namespace getoptpp

#endif // __GETOPTPP_PARSE_HPP__
