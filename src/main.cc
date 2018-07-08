#include <iostream>
#include "logs.hh"

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    std::cerr << "Usage: ./log_analyzer <TSV log file>" << std::endl;
    return 1;
  }

  Logs logs(argv[1]);
  return 0;
}
