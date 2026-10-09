#pragma once

#include <string>

// Балл зачтён, если он от 0 до 100 включительно.
bool IsValidScore(int score);

// Прибавить балл к сумме. Сумма живёт в long long.
long long AddToSum(long long sum, int score);

// Новый минимум.
// Если has_score == false, текущего минимума ещё нет: верните score.
int NextMin(bool has_score, int current_min, int score);

// Новый максимум. Правило то же, что у NextMin.
int NextMax(bool has_score, int current_max, int score);

// Сколько баллов стало >= 60 после добавления score.
int NextPassed(int passed, int score);

// Среднее. count в тестах всегда > 0.
// Делить нужно как дробное число: сумма 2 и count 3 дают 0.666..., не 0.
double Average(long long sum, int count);

// Итог журнала. Проверять условия нужно именно в этом порядке:
//   count == 0            -> "empty"
//   passed != count       -> "debt"      (есть балл ниже 60)
//   min_score >= 90       -> "excellent"
//   иначе                 -> "ok"
std::string Verdict(int count, int passed, int min_score);
