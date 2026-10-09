#include "labels.hpp"

#include <iostream>
#include <string>

namespace {

int g_failed = 0;

void ExpectEq(const std::string& name, const std::string& got, const std::string& expected) {
    if (got != expected) {
        std::cerr << "FAIL " << name << ": got \"" << got << "\", expected \"" << expected << "\"\n";
        ++g_failed;
    }
}

}  // namespace

int main() {
    ExpectEq("sign -3", SignLabel(-3), "negative");
    ExpectEq("sign -1", SignLabel(-1), "negative");
    ExpectEq("sign 0", SignLabel(0), "zero");
    ExpectEq("sign 4", SignLabel(4), "positive");

    ExpectEq("parity 0", ParityLabel(0), "even");
    ExpectEq("parity 2", ParityLabel(2), "even");
    ExpectEq("parity -4", ParityLabel(-4), "even");
    ExpectEq("parity 7", ParityLabel(7), "odd");
    ExpectEq("parity -3", ParityLabel(-3), "odd");

    ExpectEq("grade 0", GradeLabel(0), "fail");
    ExpectEq("grade 59", GradeLabel(59), "fail");
    ExpectEq("grade 60", GradeLabel(60), "pass");
    ExpectEq("grade 74", GradeLabel(74), "pass");
    ExpectEq("grade 75", GradeLabel(75), "good");
    ExpectEq("grade 89", GradeLabel(89), "good");
    ExpectEq("grade 90", GradeLabel(90), "excellent");
    ExpectEq("grade 100", GradeLabel(100), "excellent");
    ExpectEq("grade -1", GradeLabel(-1), "invalid");
    ExpectEq("grade 101", GradeLabel(101), "invalid");

    if (g_failed != 0) {
        std::cerr << g_failed << " failed\n";
        return 1;
    }
    std::cout << "ok\n";
    return 0;
}
