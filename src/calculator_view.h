#ifndef CALCULATOR_VIEW_H
#define CALCULATOR_VIEW_H
#include "calculator.h"

CalculatorView* calculator_view_new();
void calculator_view_free(CalculatorView *view);
void calculator_view_show(CalculatorView *view);
void calculator_view_result_changed(CalculatorView *view, const char *result);
#endif
