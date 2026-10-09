#include "types.hpp"

#include <cmath>
#include <iostream>
#include <limits>
#include <string>

namespace {

int g_failed = 0;

void Expect(bool condition, const std::string& name) {
    if (!condition) {
        std::cerr << "FAIL " << name << '\n';
        ++g_failed;
    }
}

bool Close(double left, double right) {
    return std::fabs(left - right) < 1e-9;
}

}  // namespace

int main() {
    Expect(DivideInts(5, 2) == 2, "DivideInts(5, 2) == 2");
    Expect(DivideInts(7, 7) == 1, "DivideInts(7, 7) == 1");
    Expect(DivideInts(-5, 2) == -2, "DivideInts(-5, 2) == -2");
    Expect(DivideInts(1, -2) == 0, "DivideInts(1, -2) == 0");

    Expect(Close(DivideAsDouble(5, 2), 2.5), "DivideAsDouble(5, 2) == 2.5");
    Expect(Close(DivideAsDouble(1, 2), 0.5), "DivideAsDouble(1, 2) == 0.5");
    Expect(Close(DivideAsDouble(-5, 2), -2.5), "DivideAsDouble(-5, 2) == -2.5");

    const long long k_int_min = std::numeric_limits<int>::min();
    const long long k_int_max = std::numeric_limits<int>::max();
    Expect(FitsInInt(0), "FitsInInt(0)");
    Expect(FitsInInt(k_int_min), "FitsInInt(min)");
    Expect(FitsInInt(k_int_max), "FitsInInt(max)");
    Expect(!FitsInInt(k_int_min - 1), "FitsInInt(min - 1)");
    Expect(!FitsInInt(k_int_max + 1), "FitsInInt(max + 1)");

    Expect(SumAsLongLong(2, 3) == 5, "SumAsLongLong(2, 3)");
    Expect(SumAsLongLong(-4, 4) == 0, "SumAsLongLong(-4, 4)");
    Expect(
        SumAsLongLong(2000000000, 2000000000) == 4000000000LL,
        "SumAsLongLong large positive"
    );
    Expect(
        SumAsLongLong(-2000000000, -2000000000) == -4000000000LL,
        "SumAsLongLong large negative"
    );

    if (g_failed != 0) {
        std::cerr << g_failed << " failed\n";
        return 1;
    }
    std::cout << "ok\n";
    return 0;
}
