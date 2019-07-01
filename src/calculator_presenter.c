#include "calculator_view.h"
#include "calculator_presenter.h"

struct CalculatorPresenter {
  CalculatorView *view;
};

CalculatorPresenter *calculator_presenter_new(CalculatorView *view)
{
  CalculatorPresenter *presenter = malloc(sizeof(CalculatorPresenter));
  presenter->view = view;
  return presenter;
}

void calculator_presenter_free(CalculatorPresenter *presenter)
{
  free(presenter);
}

void calculator_presenter_add_digit(CalculatorPresenter *presenter,
				    char digit)
{
  char digits[] = { digit, '\0'};
  calculator_view_result_changed(presenter->view, digits);
}

void calculator_presenter_add_point(CalculatorPresenter *presenter)
{
  calculator_view_result_changed(presenter->view, "point");
}

void calculator_presenter_set_operator(CalculatorPresenter *presenter,
				       CalculatorOperator operator)
{
  calculator_view_result_changed(presenter->view, "operator");
}

void calculator_presenter_clear(CalculatorPresenter *presenter)
{
  calculator_view_result_changed(presenter->view, "");
}

void calculator_presenter_back(CalculatorPresenter *presenter)
{
  calculator_view_result_changed(presenter->view, "<-");
}

void calculator_presenter_compute(CalculatorPresenter *presenter)
{
  calculator_view_result_changed(presenter->view, "foo");
}
