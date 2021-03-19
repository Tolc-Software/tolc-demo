#include "Demo/demo.hpp"
#include <algorithm>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>
#include <iterator>

namespace Demo {

int add(int a, int b) { return a + b; }

int sum(std::vector<int> const &numbers) {
  return std::accumulate(numbers.begin(), numbers.end(), 0);
}

std::map<std::string, int> merge(std::map<std::string, int> const &m1,
                                 std::map<std::string, int> const &m2) {

  std::map<std::string, int> out;
  for (auto const &m : {m1, m2}) {
    out.insert(m.begin(), m.end());
  }
  return out;
}

std::set<std::string> difference(std::set<std::string> const &s1,
                                 std::set<std::string> const &s2) {
  std::set<std::string> difference;
  std::set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(),
                      std::inserter(difference, difference.begin()));
  return difference;
}

} // namespace Demo
