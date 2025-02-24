// #include "rapidjson/document.h"
#include "models/3DArrayModel.cpp"
#include "models/RubiksCube.h"
#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>

using namespace Pistache;

void hello(const Rest::Request &request, Http::ResponseWriter response) {
  response.send(Http::Code::Ok, "world!");
}

int main(int argc, char *argv[]) {
  using namespace Rest;
  RubiksCube3dArray cube1;
  std::vector<RubiksCube::MOVE> moves = cube1.randomShuffle(8);
  for (int i = 0; i < moves.size(); i++) {
    std::cout << RubiksCube::getMoveNotation(moves[i]) << " ";
  }
  std::cout << '\n';
  for (RubiksCube::MOVE xm : moves) {
    std::cout << RubiksCube::getMoveNotation(xm) << " ";
  }
  std::cout << '\n';
  cube1.printState();

  Router router;   // POST/GET/etc. route handler
  Port port(8081); // Port to listen on
  Address addr(Ipv4::any(), port);
  std::shared_ptr<Http::Endpoint> endpoint =
      std::make_shared<Http::Endpoint>(addr);
  auto opts =
      Http::Endpoint::options().threads(1); // Number of threads for the server
  endpoint->init(opts);

  std::cout << "Server is initialized" << std::endl;
  Routes::Get(router, "/hello", Routes::bind(&hello));

  endpoint->setHandler(router.handler());
  std::cout << "Server is running..." << std::endl;
  endpoint->serve();

  // Optionally print shutdown message after server stops.
  std::cout << "Server is shut down" << std::endl;
  return 0;
}
