// A C++ library that will
// be used across languages
#include <string>

namespace Hello {
  std::string cppFunction(std::string const &name) {
    return "Hello " + name + "!\n";
  }
}
