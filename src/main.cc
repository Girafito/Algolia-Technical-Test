#include <iostream>
#include <string>
#include <ctime>

#include <pistache/endpoint.h>
#include "query_handler.hh"

using namespace Pistache;

ToJson g_json;

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    std::cerr << "Usage: ./log_analyzer <TSV log file>" << std::endl;
    return 1;
  }
  g_json.set_filename(argv[1]);
  Http::listenAndServe<QueryHandler>("*:8080");
  return 0;
}
