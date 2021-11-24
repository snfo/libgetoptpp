#include <iostream>
#include <string>

#include <getoptpp>

static const char *exec_name;

static void show_usage(bool err)
{
  auto &out = !err ? std::cout : std::cerr;
  out << "Usage: " << exec_name << " OPTION...\n";
  if (!err) {
    out << "Options:\n"
        << "  -1 ARG, --option1=ARG     An option that requires an argument\n"
        << "  -2 [ARG], --option2[=ARG] An option with an optional argument\n"
        << "  -3, --option3             An option with no arguments\n"
        << "  -4 ARG, --option4=ARG     An option that requires an argument\n"
        << "  -h, --help                Print this text\n";
    std::exit(EXIT_SUCCESS);
  }
  std::exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
  using namespace getoptpp;

  const getoptpp::option options[] = {
    // option1 and option2 show the traditional way of defining options with
    // getopt, which is still supported with getoptpp.
    {"option1", arg::required, nullptr, '1'},
    {"option2", arg::optional, nullptr, '2'},

    // option3 is an example of one of the option struct's overloaded
    // constructors. Here, `arg' is implicitly set to "no" and `flag'
    // is implicitly set to null.
    {"option3", '3'},

    // Again, `flag' is implicitly set to null.
    {"option4", '4', arg::required},

    // Instead of {"help", no_argument, NULL, 'h'}
    {"help", 'h'},

    // A final sentinel option is still required to terminate the array, but
    // the default constructor can be used with no arguments instead of
    // explicitly setting everything to null and zero yourself.
    {},
  };

  std::string option1_arg;
  std::string option2_arg = "default_option2_arg";
  bool option3_flag = false;
  std::string option4_arg;

  exec_name = argv[0];

  int opt;
  while ((opt = parse(argc, argv, "1:2::34:h", options, nullptr)) != -1) {
    switch (opt) {
    case '1':
      option1_arg = option::arg();
      break;
    case '2': {
      const char *arg = option::arg();
      if (arg && *arg)
        option2_arg = arg;
      break;
    }
    case '3':
      option3_flag = true;
      break;
    case '4':
      option4_arg = option::arg();
      break;
    case 'h':
      show_usage(false);
    default:
      show_usage(true);
    }
  }

  std::cout << "option1_arg=\"" << option1_arg << "\"\n";
  std::cout << "option2_arg=\"" << option2_arg << "\"\n";
  std::cout << std::boolalpha << "option3_flag=" << option3_flag << '\n';
  std::cout << "option4_arg=\"" << option4_arg << "\"\n";
  return 0;
}
