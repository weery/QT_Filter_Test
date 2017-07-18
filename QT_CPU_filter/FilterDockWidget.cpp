#include "FilterDockWidget.h"

FilterDockWidget::FilterDockWidget(QWidget* parent)
	:QDockWidget(parent)
{
	filter_Widget = new FilterWidget(this);
	filter_Widget->showMaximized();
	this->setWidget(filter_Widget);
}

void FilterDockWidget::Initialize()
{
	filter_Widget->Initialize();
}