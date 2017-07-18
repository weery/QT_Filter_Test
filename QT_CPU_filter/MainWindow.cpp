#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
	:QMainWindow(parent)
{
	//_orig_image = QImage("./resources/images/image.png");
	_orig_image = QImage("D:/Programming/Master_Thesis/QT_CPU_convolution/QT_CPU_convolution/images/image.png");
	_image_filtered = new QImage(_orig_image.width(),
		_orig_image.height(), _orig_image.format());
	_label_image = new QLabel(this);
	_label_image->setPixmap(QPixmap::fromImage(_orig_image));
	_label_image->show();

	this->setCentralWidget(_label_image);

	_filter_dock_widget = new FilterDockWidget(this);
	this->addDockWidget(Qt::RightDockWidgetArea,_filter_dock_widget);
	_filter_dock_widget->Initialize();

	this->setAttribute(Qt::WA_DeleteOnClose);
}

void MainWindow::ApplyFilter(Filters filter)
{
	Apply_Filter::Apply_Predefined_Filter(_image_filtered, &_orig_image,filter);

	_label_image->setPixmap(QPixmap::fromImage(*_image_filtered));
}

void MainWindow::ApplyCustomFilter(Filter* custom_Filter)
{
	Apply_Filter::Apply_Custom_Filter(_image_filtered, &_orig_image, custom_Filter);

	_label_image->setPixmap(QPixmap::fromImage(*_image_filtered));
}