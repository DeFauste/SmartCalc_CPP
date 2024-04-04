#include <gtest/gtest.h>
#include "../Controller/controller.h"

class CalculatorControllerTest : public ::testing::Test {
 protected:
  Controller calculator_;
};

TEST_F(CalculatorControllerTest, Test_1) {
  double result  = calculator_.Calculation("(2+3)*5^2", 0);
  ASSERT_DOUBLE_EQ(result, 125.0);
}

TEST_F(CalculatorControllerTest, Test_3) {
  double result  = calculator_.Calculation("(-12.3)+4", 0);
  ASSERT_NEAR(result, -8.3, 1e-6);
}

TEST_F(CalculatorControllerTest, Test_4) {
  double result  =  calculator_.Calculation("(12)+(-12.00006)", 0);
  ASSERT_NEAR(result, -0.00006, 1e-6);
}

TEST_F(CalculatorControllerTest, Test_5) {
  double result  =  calculator_.Calculation("(-(-(-10)))-(-(-10))", 0);

  ASSERT_NEAR(result, -20, 1e-6);
}

TEST_F(CalculatorControllerTest, Test_6) {
  double result  =  calculator_.Calculation("(-1.2)-1.2-2.4-4.8", 0);
  ASSERT_NEAR(result, -9.6, 1e-6);
}

TEST_F(CalculatorControllerTest, Test_7) {
  double result  =  calculator_.Calculation("(12)*(-1.0006)", 0);
  ASSERT_NEAR(result, -12.0072, 1e-6);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}