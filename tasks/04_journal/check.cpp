#include "journal.hpp"

#include <cmath>
#include <iostream>
#include <string>

namespace {

int g_failed = 0;

void Expect(bool condition, const std::string& name) {
    if (!condition) {
        std::cerr << "FAIL " << name << '\n';
        ++g_failed;
    }
}

void ExpectEq(const std::string& name, const std::string& got, const std::string& expected) {
    if (got != expected) {
        std::cerr << "FAIL " << name << ": got \"" << got << "\", expected \"" << expected << "\"\n";
        ++g_failed;
    }
}

bool Close(double left, double right) {
    return std::fabs(left - right) < 1e-9;
}

}  // namespace

int main() {
    Expect(IsValidScore(0), "score 0");
    Expect(IsValidScore(100), "score 100");
    Expect(IsValidScore(60), "score 60");
    Expect(!IsValidScore(-1), "score -1");
    Expect(!IsValidScore(101), "score 101");

    Expect(AddToSum(0, 10) == 10, "add 10");
    Expect(AddToSum(5, 0) == 5, "add 0");
    Expect(AddToSum(3000000000LL, 100) == 3000000100LL, "add keeps long long");

    Expect(NextMin(false, 0, 5) == 5, "min first");
    Expect(NextMin(true, 5, 3) == 3, "min smaller");
    Expect(NextMin(true, 3, 5) == 3, "min keeps");
    Expect(NextMin(true, -1, -4) == -4, "min negative");

    Expect(NextMax(false, 0, 5) == 5, "max first");
    Expect(NextMax(true, 5, 8) == 8, "max larger");
    Expect(NextMax(true, 8, 5) == 8, "max keeps");
    Expect(NextMax(true, -4, -1) == -1, "max negative");

    Expect(NextPassed(0, 60) == 1, "passed 60");
    Expect(NextPassed(0, 59) == 0, "passed 59");
    Expect(NextPassed(2, 100) == 3, "passed 100");
    Expect(NextPassed(2, 0) == 2, "passed 0");

    Expect(Close(Average(5, 2), 2.5), "average 5/2");
    Expect(Close(Average(2, 3), 2.0 / 3.0), "average 2/3");
    Expect(Close(Average(0, 1), 0.0), "average 0/1");
    Expect(Close(Average(3000000000LL, 3), 1000000000.0), "average large");

    ExpectEq("empty", Verdict(0, 0, 0), "empty");
    ExpectEq("empty ignores min", Verdict(0, 0, 100), "empty");
    ExpectEq("debt before excellent", Verdict(3, 2, 90), "debt");
    ExpectEq("excellent", Verdict(2, 2, 90), "excellent");
    ExpectEq("excellent 100", Verdict(1, 1, 100), "excellent");
    ExpectEq("ok", Verdict(2, 2, 89), "ok");
    ExpectEq("ok low", Verdict(4, 4, 60), "ok");
    ExpectEq("debt", Verdict(1, 0, 50), "debt");

    if (g_failed != 0) {
        std::cerr << g_failed << " failed\n";
        return 1;
    }
    std::cout << "ok\n";
    return 0;
}
