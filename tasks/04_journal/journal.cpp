#include "journal.hpp"
#include <string>

bool IsValidScore(int score) {
    return score >= 0 && score <= 100;
}

long long AddToSum(long long current_sum, int score) {
    return current_sum + score;
}

int NextMin(int current_min, int score, bool has_score) {
    if (!has_score) return score;
    return (score < current_min) ? score : current_min;
}

int NextMax(int current_max, int score, bool has_score) {
    if (!has_score) return score;
    return (score > current_max) ? score : current_max;
}

int NextPassed(int current_passed, int score) {
    if (score >= 60) {
        return current_passed + 1;
    }
    return current_passed;
}

double Average(long long sum, int count) {
    if (count == 0) return 0.0;
    return static_cast<double>(sum) / count;
}

std::string Verdict(int count, int passed, int min_score) {
    if (count == 0) return "empty";
    if (passed != count) return "debt";
    if (min_score >= 90) return "excellent";
    return "ok";
}
