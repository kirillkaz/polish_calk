#include "PolishCalk.h"
#include "stdlib.h"
#include <string>


std::vector<std::string>ParsOnCommonNumsAndSimvs(std::string stroke){
    std::vector<std::string> parsArray;
    int firstIndex=0;
    for (int i=0;i<stroke.length();i++){
        if (stroke[i] == ' '){//если встречаю пробел, то записываю число или символ в ячейку массива
            parsArray.push_back(stroke.substr(firstIndex,i-firstIndex));
            firstIndex = i+1;
        }
    }
    parsArray.push_back(stroke.substr(stroke.length()-1,1));
    return parsArray;
}

bool IsCorrectPolish(std::string stroke){
    if (stroke == "")return false;

    int countSimvs = 0;
    int countNums = 0;

    std::string ABC = " 1234567890*/+-";

    std::vector<std::string> parsArray = ParsOnCommonNumsAndSimvs(stroke);

    bool isSimv = false;
    //проверка символов
    for (int i = 0;i<stroke.length();i++){
        isSimv = false;
        for(int j =0;j<ABC.length();j++) if (ABC[j] == stroke[i]) isSimv = true;
    }

    if (parsArray.size() < 3) return false;

    if(isSimv == false) return false;
    //проверка кол-ва знаков и цифр
    for (int i=0;i<parsArray.size();i++){
        if((parsArray[i] == "+") || (parsArray[i] == "-") || (parsArray[i] == "*") || (parsArray[i] == "/")) countSimvs++;
        else if (parsArray[i] !=" ")countNums++;
    }

    if (countNums != (countSimvs+1)) return false;
    //провека первого и последнего символов
    if((parsArray[0] == "+") || (parsArray[0] == "-") || (parsArray[0] == "*") || (parsArray[0] == "/") || (parsArray[0] == " ")) return false;
    if((parsArray[1] == "+") || (parsArray[1] == "-") || (parsArray[1] == "*") || (parsArray[1] == "/") || (parsArray[1] == " ")) return false;
    if((parsArray[parsArray.size()-1] != "+") && (parsArray[parsArray.size()-1] != "-") && (parsArray[parsArray.size()-1] != "*") && (parsArray[parsArray.size()-1] != "/")) return false;


    return true;
}

std::string DoOperationsWithNums(std::string num1, std::string num2, std::string oper){
    std::string sum = "";
    double dnum1 = 0;
    double dnum2 = 0;
    double dsum = 0;

    if ((oper + num2) == "/0") return "0";

    dnum1 = atof(num1.c_str());
    dnum2 = atof(num2.c_str());

    if (oper == "+") dsum = dnum1 + dnum2;
    else if (oper == "-") dsum = dnum1 - dnum2;
    else if (oper == "*") dsum = dnum1 * dnum2;
    else dsum = dnum1 / dnum2;

    sum = std::to_string(dsum);
    return sum;
}

double CalkPolishStroke(std::string stroke){
    double sum = 0;
    int coutnOfSimvs = 0;
    if (!IsCorrectPolish(stroke)) return 0;
    else {
        std::vector<std::string> parsArray = ParsOnCommonNumsAndSimvs(stroke);

        for (int i =0; i<parsArray.size();i++){// считаю кол-во операций
            if ((parsArray[i] == "+") || (parsArray[i] == "-") || (parsArray[i] == "*") || (parsArray[i] == "/")) coutnOfSimvs++;
        }
        for(int i =0;i<coutnOfSimvs;i++){
            int index =0;
            while ((parsArray[index] != "+") && (parsArray[index] != "-") && (parsArray[index] != "*") && (parsArray[index] != "/")) index++;
            parsArray[index-2] = DoOperationsWithNums(parsArray[index-2],parsArray[index-1],parsArray[index]);
            //сдвигаю массив на 2 влево и освобождаю 2 ячейки
            for (int j = index-1;j<parsArray.size()-1;j++)
                parsArray[j]=parsArray[j+1];
            parsArray.pop_back();
            for (int j = index-1;j<parsArray.size()-1;j++)
                parsArray[j]=parsArray[j+1];
            parsArray.pop_back();
        }
        sum = atof(parsArray[0].c_str());
        return sum;
    }
}