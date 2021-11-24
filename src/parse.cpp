#include <getoptpp_internal/parse.hpp>

#include <getopt.h>

namespace getoptpp {

int parse(int argc, char *const argv[], const char *opt_string)
{
  return ::getopt(argc, argv, opt_string);
}

int parse(int argc, char *const *argv, const char *opt_string,
          const option *options, int *index)
{
  return ::getopt_long(argc, argv, opt_string,
                       (const struct ::option *)options, index);
}

int parse_long(int argc, char *const *argv, const char *opt_string,
               const option *options, int *index)
{
  return ::getopt_long_only(argc, argv, opt_string,
                            (const struct ::option *)options, index);
}

} // namespace getoptpp
