#include "calculator_view.h"
#include "calculator_presenter.h"
#include "calculator_operand.h"

struct CalculatorPresenter {
  CalculatorView *view;
  CalculatorOperand *first;
  CalculatorOperand *second;
  CalculatorOperator operator;
};

CalculatorPresenter *calculator_presenter_new(CalculatorView *view)
{
  CalculatorPresenter *presenter = malloc(sizeof(CalculatorPresenter));
  presenter->first = calculator_operand_new(0.0);
  presenter->second = calculator_operand_new(0.0);
  presenter->operator = None;
  presenter->view = view;
  return presenter;
}

void calculator_presenter_free(CalculatorPresenter *presenter)
{
  calculator_operand_free(presenter->first);
  calculator_operand_free(presenter->second);
  free(presenter);
}

void calculator_presenter_add_digit(CalculatorPresenter *presenter,
				    char digit)
{
  calculator_operand_add_digit(presenter->second, digit);

  char *result = calculator_operand_str(presenter->second);
  calculator_view_result_changed(presenter->view, result);
}

void calculator_presenter_add_point(CalculatorPresenter *presenter)
{
  calculator_operand_add_point(presenter->second);

  char *result = calculator_operand_str(presenter->second);
  calculator_view_result_changed(presenter->view, result);
}

void calculator_presenter_set_operator(CalculatorPresenter *presenter,
				       CalculatorOperator operator)
{
  if (presenter->operator == None) {
    calculator_operand_free(presenter->first);
    presenter->first = presenter->second;
    presenter->second = calculator_operand_new(0.0);
    presenter->operator = operator;

    char *result = calculator_operand_str(presenter->second);
    calculator_view_result_changed(presenter->view, result);
  } else {
    presenter->operator = operator;
  }
}

void calculator_presenter_clear(CalculatorPresenter *presenter)
{
  calculator_operand_free(presenter->first);
  calculator_operand_free(presenter->second);
  presenter->first = calculator_operand_new(0.0);
  presenter->second = calculator_operand_new(0.0);
  presenter->operator = None;

  char *result = calculator_operand_str(presenter->second);
  calculator_view_result_changed(presenter->view, result);
}

void calculator_presenter_back(CalculatorPresenter *presenter)
{
  calculator_operand_back(presenter->second);

  char *result = calculator_operand_str(presenter->second);
  calculator_view_result_changed(presenter->view, result);
}

void calculator_presenter_compute(CalculatorPresenter *presenter)
{
  double first = calculator_operand_double(presenter->first);
  double second = calculator_operand_double(presenter->second);

  switch (presenter->operator) {
  case Addition:
    first += second;
    break;
  case Subtraction:
    first -= second;
    break;
  case Multiplication:
    first *= second;
    break;
  case Division:
    first /= second;
    break;
  }
  calculator_operand_free(presenter->second);
  presenter->second = calculator_operand_new(first);
  presenter->operator = None;

  char *result = calculator_operand_str(presenter->second);
  calculator_view_result_changed(presenter->view, result);
}
