#include "query_handler.hh"

using namespace Pistache;

bool parsed;

void QueryHandler::parseQuery(const Http::Request& request)
{
    g_json.reset();
    std::string query = request.resource();
    auto len = query.size();
    if (len < HEADER_SIZE || query.substr(0, HEADER_SIZE) != "/1/queries/\0")
      return;

    if (len > POPULAR_SIZE && query.substr(11, 8) == "popular/\0")
    {
      std::string size_str = "size";
      g_json.top(query.substr(POPULAR_SIZE, len - POPULAR_SIZE),
               request.query().get(size_str).get());
    }

    else if (len > COUNT_SIZE && query.substr(11, 6) == "count/\0")
      g_json.count(query.substr(COUNT_SIZE, len - COUNT_SIZE));
}

void QueryHandler::onRequest(const Http::Request& request,
                             Http::ResponseWriter writer)
{
    if (!parsed)
      g_json = ToJson(g_json.get_filename());
    parsed = true;
    parseQuery(request);
    auto s = g_json.get_str();
    if (s == "")
      writer.send(Http::Code::Not_Implemented, s);
    else
      writer.send(Http::Code::Ok, s);
}
