#pragma once

#include <pistache/endpoint.h>
#include "toJson.hh"

#define HEADER_SIZE 11
#define COUNT_SIZE 17
#define POPULAR_SIZE 19

extern ToJson g_json;

using namespace Pistache;

class QueryHandler : public Http::Handler {
    HTTP_PROTOTYPE(QueryHandler)

    public:
      /**
      * \brief The function triggered when a query is received
      */
      void onRequest(const Http::Request& request, Http::ResponseWriter writer);

    private:
      void parseQuery(const Http::Request& request);

      ToJson json_;
};
