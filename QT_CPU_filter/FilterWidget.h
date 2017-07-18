#pragma once

#include <QWidget>
#include <QBoxLayout>
#include <QGroupBox>
#include "Apply_Filter.h"
#include <QDoubleSpinBox>
#include <QRadioButton>

class FilterWidget : public QWidget
{
	Q_OBJECT
public:
	FilterWidget(QWidget* parent);

	void Initialize();

private:
	QBoxLayout* _main_layout;
	QGridLayout* _filter_select_layout;
	QGridLayout* _custom_filter_select_layout;

	Filter* _custom_filter;
	bool _use_custom_filter;
	Filters _current_filter;

	void InitializeLayouts();
	void InitializeCustomFilterLayout();
	void InitializeFilterLayout();

signals:
	void FilterDone(Filters);
	void CustomFilterDone(Filter*);

	public slots:
	void updateFilter(double value);
	void useCustomFilter(bool toggled);
	void selectFilter(bool toggled);
};