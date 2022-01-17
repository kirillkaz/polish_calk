#ifndef POLISH_CALK_POLISHCALK_H
#define POLISH_CALK_POLISHCALK_H

#include <iostream>
#include <vector>

//проверка строки на корректность
bool IsCorrectPolish(std::string stroke);

//парсинг строки в массив с числами и знаками (сложение, умножение и тп)
std::vector<std::string>ParsOnCommonNumsAndSimvs(std::string stroke);

//проведение операции с числами в формате string
std::string DoOperationsWithNums(std::string num1, std::string num2, std::string oper);

//подсчет строки в формате польской записи
double CalkPolishStroke(std::string stroke);

#endif //POLISH_CALK_POLISHCALK_H