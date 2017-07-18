#include "FilterWidget.h"

FilterWidget::FilterWidget(QWidget* parent)
	:QWidget(parent)
{

}

// ADD SOME Struct to initialize
void FilterWidget::Initialize()
{
	InitializeLayouts();
	InitializeFilterLayout();
	InitializeCustomFilterLayout();

}

void FilterWidget::InitializeLayouts()
{
	_main_layout = new QVBoxLayout(this);
	_main_layout->addStretch(1);
	
	_filter_select_layout = new QGridLayout();
	QGroupBox* filter_select_groupbox = new QGroupBox("Select Filter");
	_main_layout->addWidget(filter_select_groupbox);
	filter_select_groupbox->setLayout(_filter_select_layout);

	_custom_filter_select_layout = new QGridLayout();
	QGroupBox* custom_filter_select_groupbox = new QGroupBox("Custom Filter");
	_main_layout->addWidget(custom_filter_select_groupbox);
	custom_filter_select_groupbox->setLayout(_custom_filter_select_layout);


}

void FilterWidget::InitializeFilterLayout()
{
	for (int i = 0; i < Filters::numbe_of_filters; i++)
	{
		QRadioButton* button = new QRadioButton(Filter_names[i],this);
		_filter_select_layout->addWidget(button);
		button->show();
		if (i > 0 && i < Filters::numbe_of_filters)// Disable unimpolemented filter
			button->setEnabled(false); 

		connect(button, SIGNAL(toggled(bool)), this, SLOT(selectFilter(bool)));
	}
	QRadioButton* useCustomFilterButton = new QRadioButton("Custom Filter", this);
	_filter_select_layout->addWidget(useCustomFilterButton);
	useCustomFilterButton->show();
	connect(useCustomFilterButton,SIGNAL(toggled(bool)),this,SLOT(useCustomFilter(bool)));
	connect(this, SIGNAL(CustomFilterDone(Filter*)), this->parent()->parent(), SLOT(ApplyCustomFilter(Filter*)));
	connect(this, SIGNAL(FilterDone(Filters)), this->parent()->parent(), SLOT(ApplyFilter(Filters)));
	_use_custom_filter = false;
}

void FilterWidget::InitializeCustomFilterLayout()
{
	_custom_filter = new Filter();
	int width = 5;
	int height = 5;
	int center_x = 2;
	int center_y = 2;
	_custom_filter->InitializeFilter(width, height,center_x, center_y);
	char* spinbox_name = (char*)malloc(sizeof(char)*3);
	spinbox_name[2]= '\0';
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
		{
			QDoubleSpinBox* spinBox = new QDoubleSpinBox();
			spinBox->setRange(-10.0, 10.0);
			spinBox->setSingleStep(0.1);
			spinbox_name[0] = i + '0';
			spinbox_name[1] = j + '0';
			spinBox->setObjectName(spinbox_name);
			if (i == center_x && j == center_y)
				spinBox->setValue(1.0);
			else
				spinBox->setValue(0.0);
			_custom_filter_select_layout->addWidget(spinBox,i,j);
			spinBox->show();
			connect(spinBox,SIGNAL(valueChanged(double)),this,SLOT(updateFilter(double)));
		}
	delete spinbox_name;
}


void FilterWidget::updateFilter(double value)
{
	QDoubleSpinBox* sender_spinbox = (QDoubleSpinBox*)sender();
	std::string objectName = sender_spinbox->objectName().toStdString();
	int width = (int)objectName[0] - '0';
	int height = (int)objectName[1] - '0';

	_custom_filter->ChangeElement(width,height,value);
	if (_use_custom_filter)
		emit CustomFilterDone(_custom_filter);
}


void FilterWidget::useCustomFilter(bool toggled)
{
	_use_custom_filter = toggled;
	if (toggled)
	{
		emit CustomFilterDone(_custom_filter);
	}
}

void FilterWidget::selectFilter(bool toggled)
{
	if (toggled)
	{
		QRadioButton* sender_button = (QRadioButton*)sender();

		std::string text = sender_button->text().toStdString();
		for (int i = 0; i < Filters::numbe_of_filters; i++)
		{
			if (text == Filter_names[i])
			{
				_current_filter = (Filters)i;
				break;
			}
		}
		emit FilterDone(_current_filter);
	}
}
