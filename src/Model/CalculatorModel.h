#ifndef CPP3_SMARTCALC_V2_0_1_SRC_MODEL_CALCULATORMODEL_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_MODEL_CALCULATORMODEL_H_
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <stack>
#include <cstring>
#include "Dictionary.h"
class CalculatorModel {
 public:
  typedef enum {
    OK = 0,
    ERROR_INPUT = 1,
    ERROR_SIZE = 2,
    ERROR_MEMORY = 3,
    DIV_ZERO = 4,
    ERROR_CALC = 5
  } E_INPUT_ERROR;
  typedef enum {
    VALUE,
    ARITHMETIC,
    BRACKET,
    TRIGON
  } TYPE_LEXEME;
  typedef struct {
    std::string name;
    int priority;
    TYPE_LEXEME type;
  } Operation;
 private:
  double x_ = 0;
  const std::vector<Operation> ARRAY_OPERATIONS_ = {
      {LEXEMA_X, 0, VALUE}, {LEXEMA_PLUS, 1, ARITHMETIC}, {LEXEMA_MINUS, 1, ARITHMETIC}, {LEXEMA_DIV, 2, ARITHMETIC},
      {LEXEMA_MUL, 2, ARITHMETIC}, {LEXEMA_POW, 3, ARITHMETIC}, {LEXEMA_MOD, 3, ARITHMETIC},
      {LEXEMA_L_BRACK, 10, BRACKET},
      {LEXEMA_R_BRACK, -10, BRACKET}, {LEXEMA_SIN, 4, TRIGON}, {LEXEMA_COS, 4, TRIGON}, {LEXEMA_TAN, 4, TRIGON},
      {LEXEMA_ASIN, 4, TRIGON}, {LEXEMA_ATAN, 4, TRIGON}, {LEXEMA_LN, 4, TRIGON}, {LEXEMA_ACOS, 4, TRIGON},
      {LEXEMA_LOG, 4, TRIGON}, {LEXEMA_SQRT, 4, TRIGON}
  };

  Operation find_string_in_operations(char *dest);
  int strclear(char *str);
  int arithmetic(double a, double b, std::string name_operation, double &result);
  int trigonometric(double a, std::string name_operation, double &result);
  int pair_operation(std::stack<double> &value, std::stack<Operation> &operation);
  int solo_operation(std::stack<double> &value, std::stack<Operation> &operation);
  int parser_string_to_expression(std::string expr, std::vector<Operation> &operation);
  int calculate_expression(std::string src, double &result);
  double round(double d);
 public:
  int calculate(std::string src, double &resul, double x);
};

#endif //CPP3_SMARTCALC_V2_0_1_SRC_MODEL_CALCULATORMODEL_H_
