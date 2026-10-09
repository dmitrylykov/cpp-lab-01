#include "labels.hpp"
#include <string>

// Этот файл нужно реализовать.
// Сигнатуры в labels.hpp менять нельзя.

std::string SignLabel(int value) {
    if (value < 0) {
        return "negative";
    } else if (value == 0) {
        return "zero";
    } else {
        return "positive";
    }
}

std::string ParityLabel(int value) {
    if (value % 2 == 0) {
        return "even";
    } else {
        return "odd";
    }
}

std::string GradeLabel(int score) {
    if (score < 0 || score > 100) {
        return "invalid";
    } else if (score >= 0 && score <= 59) {
        return "fail";
    } else if (score >= 60 && score <= 74) {
        return "pass";
    } else if (score >= 75 && score <= 89) {
        return "good";
    } else {
        return "excellent";
    }
}
