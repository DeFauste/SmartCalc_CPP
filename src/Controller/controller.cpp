#include "controller.h"

#include <utility>

double Controller::Calculation(std::string expression, double x) {
  double result = 0;
  model_.calculate(std::move(expression), result, x);
  return result;
}
