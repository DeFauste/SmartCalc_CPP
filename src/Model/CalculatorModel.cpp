#include "CalculatorModel.h"

#include <utility>

int CalculatorModel::arithmetic(double a, double b, std::string name_operation, double &result) {
  int ret = OK;
  if (LEXEMA_PLUS == name_operation) {
    result = a + b;
  } else if (LEXEMA_MINUS == name_operation) {
    result = a - b;
  } else if (LEXEMA_MUL == name_operation) {
    result = a * b;
  } else if (LEXEMA_POW == name_operation) {
    result = pow(a, b);
  } else if (LEXEMA_MOD == name_operation) {
    result = fmod(a, b);
  } else if (LEXEMA_DIV == name_operation) {
    if (b != 0)
      result = a / b;
    else
      ret = DIV_ZERO;
  }
  return ret;
}
int CalculatorModel::trigonometric(double a, std::string name_operation, double &result) {
  int ret = OK;
  if (LEXEMA_SIN == name_operation) {
    result = sin(a);
  } else if (LEXEMA_COS == name_operation) {
    result = cos(a);
  } else if (LEXEMA_TAN == name_operation) {
    result = tan(a);
  } else if (LEXEMA_ASIN== name_operation) {
    result = asin(a);
  } else if (LEXEMA_ACOS == name_operation) {
    result = acos(a);
  } else if (LEXEMA_ATAN== name_operation) {
    result = atan(a);
  } else if (LEXEMA_LN== name_operation) {
    result = log(a);
  } else if (LEXEMA_LOG == name_operation) {
    result = log10(a);
  } else if (LEXEMA_SQRT == name_operation) {
    result = sqrt(a);
  }
  if (std::isnan(result) || std::isinf(result)) {
    ret = ERROR_CALC;
  }
  return ret;
}

int CalculatorModel::parser_string_to_expression(std::string expr, std::vector<Operation> &operation) {
  int ret = OK;
  Operation contain;
  if (expr.length() <= 255 && expr.length() != 0) {
    char buffer[256] = {'\0'};
    int i_buf = 0;
    for (int i = 0; i < expr.length(); i++) {
      buffer[i_buf] = expr[i];
      if (((expr[i] >= '0' && expr[i] <= '9') ||
          ((expr[i] == '-' || expr[i] == '+') &&
              expr[i + 1] >= '0' && expr[i + 1] <= '9' && operation.size() == 0) ||
          (!contain.name.empty() && contain.name == "(" &&
              (expr[i] == '-' || expr[i] == '+'))) &&
          i_buf == 0) {
        contain = {};
        char *nstr = &expr[i];
        char *estr = &expr[i];
        double d = strtod(nstr, &estr);
        i += (strlen(nstr) - strlen(estr)) - 1;
        operation.push_back({std::to_string(d), 0, VALUE});
      } else {
        contain = find_string_in_operations(buffer);
        i_buf++;
        if (contain.name != "false") {
          i_buf = 0;
          operation.push_back(contain);
          strclear(buffer);
        }
      }
    }
  }
  return ret;
}
CalculatorModel::Operation CalculatorModel::find_string_in_operations(char *dest) {
  Operation ret{"false", 0, VALUE};
  for (const Operation &op : ARRAY_OPERATIONS_) {
    int check = dest == op.name;
    if (check == 1) {
      ret = op;
      break;
    }
  }
  return ret;
}

int CalculatorModel::strclear(char *str) {
  int ret = 1;
  if (str) {
    for (int i = 0; str[i] != 0; i++) {
      str[i] = '\0';
    }
    ret = 0;
  }
  return ret;
}
int CalculatorModel::calculate_expression(std::string src, double &result) {
  int ret = OK;

  std::vector<Operation> operation_vector;
  parser_string_to_expression(std::move(src), operation_vector);
  std::stack<double> value;
  std::stack<Operation> operation;

  for (const Operation &item : operation_vector) {
    if (!operation.empty() && item.type != VALUE && item.type != BRACKET && item.priority <= operation.top().priority) {
      if (operation.top().type == ARITHMETIC && value.size() > 1) {
        ret = pair_operation(value, operation);
      } else if (operation.top().type == TRIGON && !value.empty()) {
        ret = solo_operation(value, operation);
      }
    }

    if (item.name == LEXEMA_R_BRACK) {
      while (!operation.empty()) {
        if (operation.top().name == LEXEMA_L_BRACK) {
          operation.pop();
          break;
        }
        if (operation.top().type == ARITHMETIC) {
          ret = pair_operation(value, operation);
        } else if (operation.top().type == TRIGON) {
          ret = solo_operation(value, operation);
        }
      }
      continue;
    }

    if (item.type == VALUE) {
      if (item.name == LEXEMA_X) {
        value.push(x_);
      } else {
        value.push(std::stod(item.name));
      }
    } else {
      operation.push(item);
    }
  }
  while (!operation.empty()) {
    if (operation.top().type == ARITHMETIC) {
      ret = pair_operation(value, operation);
    } else if (operation.top().type == TRIGON) {
      ret = solo_operation(value, operation);
    }
  }
  result = round(value.top());
  return ret;
}
int CalculatorModel::pair_operation(std::stack<double> &value, std::stack<Operation> &operation) {
  int ret = OK;
  double b = value.top();
  value.pop();
  double a = value.top();
  value.pop();
  double result = 0;
  ret = arithmetic(a, b, operation.top().name, result);
  operation.pop();
  value.push(result);
  return ret;
}
int CalculatorModel::solo_operation(std::stack<double> &value, std::stack<Operation> &operation) {
  int ret = OK;
  double a = value.top();
  value.pop();
  double result = 0;
  ret = trigonometric(a, operation.top().name, result);
  operation.pop();
  value.push(result);
  return ret;
}
double CalculatorModel::round(double d) {
  return std::floor(d * std::pow(10, 6))/ std::pow(10,6);
}
int CalculatorModel::calculate(std::string src, double &resul, double x) {
  x_ = x;
  return calculate_expression(src, resul);
}

