#pragma once

#include <map>
#include <set>
#include <string>
#include <vector>

namespace Demo {
int add(int a, int b);
int sum(std::vector<int> const &numbers);
std::map<std::string, int> merge(std::map<std::string, int> const &m1,
                                 std::map<std::string, int> const &m2);
std::set<std::string> difference(std::set<std::string> const &s1,
                                 std::set<std::string> const &s2);
}
