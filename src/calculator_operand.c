#include "calculator_operand.h"
#include <math.h>

struct CalculatorOperand {
  char *number;
  int length;
  int hasPoint;
  int hasSign;
};

CalculatorOperand *calculator_operand_new(double number)
{
  CalculatorOperand *operand = malloc(sizeof(CalculatorOperand));
  operand->number = malloc(33);

  if (number == 0.0) {
    operand->number[0] = '0';
    operand->number[1] = '\0';
    operand->hasPoint = 0;
    operand->hasSign = 0;
    operand->length = 1;
  } else {
    sprintf(operand->number, "%f", number);
    operand->hasSign = number < 0;
    operand->hasPoint = round(number) == number;
    operand->length = strlen(operand->number);
  }
  return operand;
}

void calculator_operand_free(CalculatorOperand *operand)
{
  free(operand->number);
  free(operand);
}

void calculator_operand_add_digit(CalculatorOperand *operand,
				  char digit)
{
  if (operand->length == 1) {
    if (operand->number[0] == '0' || operand->number[0] == '-') {
      if (digit != '0') {
	operand->number[0] = digit;
      }
      return;
    }
  }
  if (operand->length < 33) {
    operand->number[operand->length] = digit;
    operand->number[++operand->length] = '\0';
  }
}


void calculator_operand_add_point(CalculatorOperand *operand)
{
  if (operand->hasPoint) {
    return;
  }
  if (operand->length < 30) {
    operand->number[operand->length] = '.';
    operand->number[++operand->length] = '\0';
  }
}


void calculator_operand_back(CalculatorOperand *operand)
{
  if (operand->length == 1) {
    operand->number[0] = '0';
    operand->number[1] = '\0';
    operand->hasPoint = 0;
    operand->length = 1;
  } else {
    if (operand->number[--operand->length] == '.') {
      operand->hasPoint = 0;
    }
    operand->number[operand->length] = '\0';
  }
}

char *calculator_operand_str(CalculatorOperand *operand)
{
  return operand->number;
}

double calculator_operand_double(CalculatorOperand *operand)
{
  return atof(operand->number);
}
