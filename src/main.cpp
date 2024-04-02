#include <iostream>
#include "./Model/CalculatorModel.h"
int main() {
  std::vector<CalculatorModel::Operation> vector;
  CalculatorModel calculator_model;
  double result = 0;
  calculator_model.calculate_expression("(7-(1+1))*3-(2+(1+1))+15/(7-(1+1))*3-(2+(1+1))", result);
  std::cout << result<< std::endl;
  return 1;
}