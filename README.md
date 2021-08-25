
# testsuite.hpp

A small header I made for testing. It's just a handful of macros.

## Usage

A single test suite MUST also be a single entry point, so each test suite must be in a different source file.
Test suites are initialized like this:

```c++

#include "./test_suite.hpp"

INI_TEST_SUITE()


INI_TEST_CASE("Name Test Case")

ASSERT(1, 2);
return new std::string("Wow you failed here."); // You may also return a pointer to a std::string ONLY if there's an error.

END_TEST_CASE()


INI_TEST_CASE("Trivial pass test")

END_TEST_CASE()


END_TEST_SUITE()

```
