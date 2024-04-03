#ifndef CPP3_SMARTCALC_V2_0_1_SRC_CONTROLLER_CONTROLLER_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_CONTROLLER_CONTROLLER_H_
#include "../Model/CalculatorModel.h"
class Controller {
 public:
  Controller() = default;
  ~Controller() = default;
  double Calculation(std::string expression, double x);
 private:
  CalculatorModel model_;
};
#endif //CPP3_SMARTCALC_V2_0_1_SRC_CONTROLLER_CONTROLLER_H_
