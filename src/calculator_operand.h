#ifndef CALCULATOR_OPERAND_H
#define CALCULATOR_OPERAND_H
#include "calculator.h"

struct CalculatorOperand;
typedef struct CalculatorOperand CalculatorOperand;

CalculatorOperand *calculator_operand_new(double number);
void calculator_operand_free(CalculatorOperand *operand);
void calculator_operand_add_digit(CalculatorOperand *operand,
				  char digit);
void calculator_operand_add_point(CalculatorOperand *operand);
void calculator_operand_back(CalculatorOperand *operand);
char *calculator_operand_str(CalculatorOperand *operand);
double calculator_operand_double(CalculatorOperand *operand);
#endif
