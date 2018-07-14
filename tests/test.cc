#include <iostream>
#include <string>
#include <ctime>

#include <toJson.hh>

int main(int argc, char** argv)
{
  if (argc != 2)
  {
    std::cerr << "Usage: ./log_analyzer <TSV log file>" << std::endl;
    return 1;
  }

  auto c_start = std::clock();
  ToJson json = ToJson(argv[1]);
  auto c_parse = std::clock();

  std::string s = "2015-08";
  json.count(s);
  auto count_str = json.get_str();
  auto c_count = std::clock();
  json.reset();
  std::string n = "3";
  json.top(s, n);
  auto top_str = json.get_str();
  auto c_end = std::clock();
  std::cout << count_str << std::endl;
  std::cout << top_str << std::endl;
  std::cout << "Parsing time : "
            << 1000.0 * (c_parse - c_start) / CLOCKS_PER_SEC << std::endl
            << "Count Query time : "
            << 1000.0 * (c_count - c_parse) / CLOCKS_PER_SEC << std::endl
            << "Top Query time : "
            << 1000.0 * (c_end - c_count) / CLOCKS_PER_SEC << std::endl
            << "Total time : "
            << 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC << std::endl;

  return 0;
}
