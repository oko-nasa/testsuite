/**
 * test_suite.hpp -- A test suite set of macros.
 * <https://github.com/eiyashou/test_suite>
 *
 *  Copyright (c) 2021 eiyashou
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 *
 */

#ifndef __TEST_SUITE_HPP__
#define __TEST_SUITE_HPP__

#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

#define INI_TEST_SUITE()\
int main()\
{\
    struct test_case {\
        typedef std::string* (*func)(); std::string name; func f; };\
    struct test_error { int case_; std::string *error; };\
    std::vector<test_case> tests; std::vector<test_error> errors;

#define END_TEST_SUITE()\
    std::cout << "|" << std::setw(70) << std::setfill('-') << "" << "|\n";\
    int i = 0;\
    for(auto &test: tests)\
    {\
        std::cout << "|" << std::left << std::setw(65) << std::setfill('.') << test.name << ' ';\
        auto resp = test.f();\
        if(resp == nullptr)\
        {\
            std::cout << "OK!!|\n";\
        }\
        else\
        {\
            std::cout << "FAIL|\n";\
            errors.push_back({i, resp});\
        }\
        i++;\
    }\
    std::cout << "|" << std::setw(70) << std::setfill('-') << "" << "|\n";\
    for(auto &error: errors)\
    {\
        std::cout << "\n" << std::setw(std::log10(tests.size())+1) << std::right << std::setfill('0') << error.case_+1 << ". " << tests[error.case_].name << "\n   "\
            << *error.error << "\n";\
        delete error.error;\
    }\
    if(errors.size())\
    {\
        std::cout << "\nTotal: " << tests.size()-errors.size() << "/" << tests.size() << " passes.\n";\
    }\
    else\
    {\
        std::cout << "\nTotal: no errors.\n";\
    }\
}

#define INI_TEST_CASE(name) tests.push_back({name, []() -> std::string* {
#define END_TEST_CASE() return nullptr; }});

#define RETURN(txt) return new std::string(txt)
#define ASSERT(cond) if(!(cond)) return new std::string("error: '" + std::string(#cond) + "' is false.")


#endif /* __TEST_SUITE_HPP__ */
