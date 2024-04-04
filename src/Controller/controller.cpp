#include "controller.h"

#include <utility>

double Controller::Calculation(std::string expression, double x) {
  double result = 0;
  calc_.calculate(std::move(expression), result, x);
  return result;
}
void Controller::Calculation_credit(BankCalculator::Credit_calc data, std::string &result) {
  credit_calc_.calculate_credit(data,result);
}
