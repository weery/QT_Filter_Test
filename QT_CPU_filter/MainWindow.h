#pragma once

#include <QMainWindow>
#include <QLabel>
#include <QImage>
#include "FilterDockWidget.h"
#include <QObject>

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	MainWindow(QWidget* parent = 0);

private:
	QImage _orig_image;
	QImage* _image_filtered;
	QLabel* _label_image;

	FilterDockWidget* _filter_dock_widget;

	public slots:
	void ApplyFilter(Filters filters);
	void ApplyCustomFilter(Filter* custom_filter);
};