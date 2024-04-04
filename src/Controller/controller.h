#ifndef CPP3_SMARTCALC_V2_0_1_SRC_CONTROLLER_CONTROLLER_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_CONTROLLER_CONTROLLER_H_
#include "../Model/CalculatorModel.h"
#include "../Model/BankCalculator.h"
class Controller {
 public:
  Controller() = default;
  ~Controller() = default;
  double Calculation(std::string expression, double x);
  void Calculation_credit(BankCalculator::Credit_calc data, std::string &result);
 private:
  CalculatorModel calc_;
  BankCalculator credit_calc_;
};
#endif //CPP3_SMARTCALC_V2_0_1_SRC_CONTROLLER_CONTROLLER_H_
