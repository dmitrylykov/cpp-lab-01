#pragma once

#include <string>

// "negative", "zero" или "positive".
std::string SignLabel(int value);

// "even" или "odd". Ноль — чётное.
// Отрицательные тоже бывают чётными: -4 — even.
std::string ParityLabel(int value);

// Балл 0..100:
//   0..59  -> "fail"
//   60..74 -> "pass"
//   75..89 -> "good"
//   90..100 -> "excellent"
// Вне диапазона -> "invalid".
std::string GradeLabel(int score);
