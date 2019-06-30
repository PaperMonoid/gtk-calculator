#ifndef CALCULATOR_PRESENTER_H
#define CALCULATOR_PRESENTER_H
#include "calculator.h"

CalculatorPresenter *calculator_presenter_new(CalculatorView *view);
void calculator_presenter_free(CalculatorPresenter *presenter);
void calculator_presenter_add_digit(CalculatorPresenter *presenter,
				    char digit);
void calculator_presenter_add_point(CalculatorPresenter *presenter);
void calculator_presenter_set_operator(CalculatorPresenter *presenter,
				       CalculatorOperator operator);
void calculator_presenter_clear(CalculatorPresenter *presenter);
void calculator_presenter_back(CalculatorPresenter *presenter);
void calculator_presenter_compute(CalculatorPresenter *presenter);
#endif
