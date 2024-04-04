#ifndef CPP3_SMARTCALC_V2_0_1_SRC_MODEL_BANKCALCULATOR_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_MODEL_BANKCALCULATOR_H_
#include "string"
#include "cmath"
class BankCalculator {
 public:
  typedef struct credit_calc {
    double sum;
    int term;
    double interest_rate;
    bool differentiated;
  } Credit_calc;
  BankCalculator() = default;
  ~BankCalculator() = default;
  int calculate_credit(Credit_calc data, std::string &result);
 private:
  int credit_differentiated(Credit_calc data, std::string &result);
};

#endif //CPP3_SMARTCALC_V2_0_1_SRC_MODEL_BANKCALCULATOR_H_
