#include <iostream>
#include <string>
#include <ctime>

#include "logs.hh"
#include "timerange.hh"

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    std::cerr << "Usage: ./log_analyzer <TSV log file>" << std::endl;
    return 1;
  }

//  auto c_start = std::clock();
  Logs logs(argv[1]);
//  auto c_parse = std::clock();
  std::string s1 = "2015-08-03";
  Timerange tr(s1);
  auto res = logs.count(tr);
//  auto c_end = std::clock();
  std::cout << res << std::endl;
/*  std::cout << "Parsing time : "
            << 1000.0 * (c_parse - c_start) / CLOCKS_PER_SEC << std::endl
            << "Parsing time : "
            << 1000.0 * (c_end - c_parse) / CLOCKS_PER_SEC << std::endl;
*/
  return 0;
}
