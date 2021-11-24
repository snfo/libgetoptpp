#include <getoptpp_internal/option.hpp>

#include <getopt.h>

namespace getoptpp {

const char *option::arg()
{
  return ::optarg;
}

int option::ind()
{
  return ::optind;
}

int option::err()
{
  return ::opterr;
}

int option::opt()
{
  return ::optopt;
}

} // namespace getoptpp
