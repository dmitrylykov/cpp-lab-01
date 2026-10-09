#include "journal.hpp"
#include <iostream>
#include <string>
#include <iomanip>

int main() {
    std::string name;
    if (!(std::cin >> name)) {
        return 0;
    }

    int n = 0;
    if (!(std::cin >> n)) {
        return 0;
    }

    if (n < 0) {
        std::cout << "invalid count" << std::endl;
        return 1;
    }

    long long sum = 0;
    int min_score = 0;
    int max_score = 0;
    int passed = 0;
    bool has_score = false;

    for (int i = 0; i < n; ++i) {
        int score = 0;
        std::cin >> score;

        if (!IsValidScore(score)) {
            std::cout << "invalid score" << std::endl;
            return 1;
        }

        min_score = NextMin(min_score, score, has_score);
        max_score = NextMax(max_score, score, has_score);
        has_score = true;

        sum = AddToSum(sum, score);
        passed = NextPassed(passed, score);
    }

    std::cout << "name: " << name << "\n";
    std::cout << "count: " << n << "\n";
    std::cout << "sum: " << sum << "\n";

    if (n > 0) {
        std::cout << "average: " << std::fixed << std::setprecision(2) << Average(sum, n) << "\n";
        std::cout << "min: " << min_score << "\n";
        std::cout << "max: " << max_score << "\n";
    } else {
        std::cout << "average: n/a\n";
        std::cout << "min: n/a\n";
        std::cout << "max: n/a\n";
    }

    std::cout << "passed: " << passed << "\n";
    std::cout << "failed: " << (n - passed) << "\n";
    std::cout << "verdict: " << Verdict(n, passed, min_score) << "\n";

    return 0;
}
