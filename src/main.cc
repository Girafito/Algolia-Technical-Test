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

  auto c_start = std::clock();
  Logs logs(argv[1]);
  auto c_parse = std::clock();
  std::string s1 = "2015-08-02";
  Timerange tr(s1);
  auto res = logs.count(tr);
  auto c_count = std::clock();
  size_t n = 5;
  auto top = logs.top(tr, n);
  auto c_end = std::clock();
  std::cout << res << std::endl;
  for (auto p: top)
    std::cout << p.first << " " << p.second << std::endl;
  std::cout << "Parsing time : "
            << 1000.0 * (c_parse - c_start) / CLOCKS_PER_SEC << std::endl
            << "Count time : "
            << 1000.0 * (c_count - c_parse) / CLOCKS_PER_SEC << std::endl
            << "Top time : "
            << 1000.0 * (c_end - c_count) / CLOCKS_PER_SEC << std::endl
            << "Total time : "
            << 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC << std::endl;
  return 0;
}
