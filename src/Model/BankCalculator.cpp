#include "BankCalculator.h"
int BankCalculator::calculate_credit(BankCalculator::Credit_calc data, std::string &result) {
  int error = 0;
  if (!data.differentiated) {
    double coef = (data.interest_rate * pow(1 + data.interest_rate, data.term)) /
        (pow(1 + data.interest_rate, data.term) - 1);
    double monthlyPayment = data.sum * coef;
    double total = monthlyPayment * data.term;
    double overpayment = total - data.sum;
    result.append("Monthly Payment = ");
    result.append(std::to_string(monthlyPayment));
    result.append("\nOverpayment = ");
    result.append(std::to_string(overpayment));
    result.append("\nTotal Payment = ");
    result.append(std::to_string(total));
  } else {
    error = credit_differentiated(data, result);
  }
  return error;
}
int BankCalculator::credit_differentiated(BankCalculator::Credit_calc data, std::string &result) {
  int error = 0;
  double main_loan = data.sum / data.term;
  double loan_left = data.sum;
  double total = 0;
  result.clear();
  result.append("Monthly Payments:\n\n");
  for (int i = 0; i < data.term; i++) {
    double each_month_payment = main_loan + loan_left * data.interest_rate;
    loan_left -= main_loan;
    total += each_month_payment;
    char PaymentThisMonth[1000];
    sprintf(PaymentThisMonth, "%d. %.2lf\n", i + 1, each_month_payment);
    result.append(PaymentThisMonth);
  }
  double overpayment = total - data.sum;
  char payment_info[500];
  sprintf(payment_info, "\nOverpayment = %.2lf\nTotal Payment = %.2lf\n",
          overpayment, total);
  result.append(payment_info);
  return 0;
}
