#include <iostream>
#include "PolishCalk.h"
#include <gtest/gtest.h>
#include <vector>

int main() {
    std::cout<<CalkPolishStroke("17 11 20 + * 10 /");
    RUN_ALL_TESTS();
    return 0;
}
TEST(PolishCalk,CalkPolishStroke){
    double result = 52.7;
    double resultTest = CalkPolishStroke("17 11 20 + * 10 /");
    EXPECT_EQ(result,resultTest);

    result = 3;
    resultTest = CalkPolishStroke("1 2 +");
    EXPECT_EQ(result,resultTest);

    result = 0;
    resultTest = CalkPolishStroke("");
    EXPECT_EQ(result,resultTest);

    result = 185;
    resultTest = CalkPolishStroke("15 10 2 + * 5 +");
    EXPECT_EQ(result,resultTest);
}

TEST(PolishCalk,DoOperationsWithNums){
    std::string result = "10.000000";
    std::string resultTest = DoOperationsWithNums("2","8","+");
    EXPECT_EQ(result,resultTest);

    result = "0";
    resultTest = DoOperationsWithNums("2","0","/");
    EXPECT_EQ(result,resultTest);

    result = "5.000000";
    resultTest = DoOperationsWithNums("25","5","/");
    EXPECT_EQ(result,resultTest);

    result = "5.000000";
    resultTest = DoOperationsWithNums("10","5","-");
    EXPECT_EQ(result,resultTest);

    result = "25.000000";
    resultTest = DoOperationsWithNums("5","5","*");
    EXPECT_EQ(result,resultTest);
}

TEST(PolishCalk,ParsOnCommonNumsAndSimvs){
    std::string stroke = "20 21 22 + * 10 /";
    std::vector<std::string> parsArrTest = ParsOnCommonNumsAndSimvs(stroke);
    std::vector<std::string> parsArr;
    parsArr.push_back("20");
    parsArr.push_back("21");
    parsArr.push_back("22");
    parsArr.push_back("+");
    parsArr.push_back("*");
    parsArr.push_back("10");
    parsArr.push_back("/");
    EXPECT_EQ(parsArr,parsArrTest);
}

TEST(PolishCalk,IsCorrectPolish){
    std::string stroke = "20 21 22 + * 10 /";
    bool isCorrectTest = IsCorrectPolish(stroke);
    bool isCorrect = true;
    EXPECT_EQ(isCorrect,isCorrectTest);

    stroke = "";
    isCorrectTest = IsCorrectPolish(stroke);
    isCorrect = false;
    EXPECT_EQ(isCorrect,isCorrectTest);

    stroke = "10";
    isCorrectTest = IsCorrectPolish(stroke);
    isCorrect = false;
    EXPECT_EQ(isCorrect,isCorrectTest);

    stroke = "/";
    isCorrectTest = IsCorrectPolish(stroke);
    isCorrect = false;
    EXPECT_EQ(isCorrect,isCorrectTest);

    stroke = "/ 10 20";
    isCorrectTest = IsCorrectPolish(stroke);
    isCorrect = false;
    EXPECT_EQ(isCorrect,isCorrectTest);

    stroke = "hello world!";
    isCorrectTest = IsCorrectPolish(stroke);
    isCorrect = false;
    EXPECT_EQ(isCorrect,isCorrectTest);

    stroke = "20 21 22 + * 10 / ";
    isCorrectTest = IsCorrectPolish(stroke);
    isCorrect = false;
    EXPECT_EQ(isCorrect,isCorrectTest);
}
