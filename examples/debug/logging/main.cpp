#include <EngineToolkit/debug/log.hpp>

using namespace EngineToolkit;

int main() {
  Log::debug("main", "hello, world");

  Log::verbose("main info", "this is a verbose system message");
  Log::warning("main warning", "something went wrong");
  Log::error("main error", "oh no, this is an error");
  return 0;
}