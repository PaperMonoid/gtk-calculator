#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <gtk/gtk.h>

struct CalculatorView;
typedef struct CalculatorView CalculatorView;

enum CalculatorOperator { Addition, Subtraction, Multiplication, Division };
typedef enum CalculatorOperator CalculatorOperator;

struct CalculatorPresenter;
typedef struct CalculatorPresenter CalculatorPresenter;
#endif
