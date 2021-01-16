---
name: Bug report
about: Create a report to help us improve
title: "[BUG]"
labels: bug
assignees: srydell

---

**Describe the bug**
A clear and concise description of what the bug is.

**To Reproduce**
Steps to reproduce the behavior:
1. Add this `C++` code to `include/Demo/demo.hpp`:
```cpp
int f();
```
2. Run `cmake -S. -Bbuild -DPYTHON_EXECUTABLE=$(which python3)`
3. See error:

**Expected behavior**
A clear and concise description of what you expected to happen.

**Desktop (please complete the following information):**
 - OS: [e.g. MacOS]
- CMake version: [output from `cmake --version`]

**Additional context**
Add any other context about the problem here.
