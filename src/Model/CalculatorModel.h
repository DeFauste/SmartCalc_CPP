//
// Created by topha on 26.03.2024.
//

#ifndef CPP3_SMARTCALC_V2_0_1_SRC_MODEL_CALCULATORMODEL_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_MODEL_CALCULATORMODEL_H_
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <stack>
#include <cstring>

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
	  {"+", 1, ARITHMETIC}, {"-", 1, ARITHMETIC}, {"x", 0, VALUE}, {"/", 2, ARITHMETIC},
	  {"*", 2, ARITHMETIC}, {"^", 3, ARITHMETIC}, {"mod", 3, ARITHMETIC}, {"(", 10, BRACKET},
	  {")", -10, BRACKET}, {"sin", 4, TRIGON}, {"cos", 4, TRIGON}, {"tan", 4, TRIGON},
	  {"asin", 4, TRIGON}, {"atan", 4, TRIGON}, {"ln", 4, TRIGON}, {"acos", 4, TRIGON},
	  {"log", 4, TRIGON}, {"sqrt", 4, TRIGON}
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
