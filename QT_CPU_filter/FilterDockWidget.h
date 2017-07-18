#pragma once

#include <QDockWidget>
#include "FilterWidget.h"

class FilterDockWidget : public QDockWidget
{
public:
	FilterDockWidget(QWidget* parent = 0);

	void Initialize();
private:
	FilterWidget* filter_Widget;
};