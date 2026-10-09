#pragma once

// Целочисленное частное. В тестах b != 0.
int DivideInts(int a, int b);

// Частное как дробное число. 5 и 2 дают 2.5, а не 2.
double DivideAsDouble(int a, int b);

// true, если value помещается в int, включая обе границы.
bool FitsInInt(long long value);

// Сумма двух int. Считать её нужно в long long:
// 2000000000 + 2000000000 не помещается в int.
long long SumAsLongLong(int a, int b);
