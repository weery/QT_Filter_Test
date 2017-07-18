#include "Filter.h"

Filter::Filter()
{
}

Filter::~Filter()
{
	for (int i = 0; i < _width; i++)
	{
		delete filter[i];
		delete delta_x[i];
		delete delta_y[i];
	}

	delete filter;
	delete delta_x;
	delete delta_y;
}

void Filter::InitializeFilter(int width, int height, int centerx, int centery)
{
	_width = width;
	_height = height;
	_center_x = centerx;
	_center_y = centery;

	filter = new double*[_width];
	delta_x = new int*[_width];
	delta_y = new int*[_width];
	for (int i = 0; i < _width; i++)
	{
		filter[i] = new double[_height];
		delta_x[i] = new int[_height];
		delta_y[i] = new int[_height];
	}

	for (int i = 0; i < _width; i++)
		for (int j = 0; j < _height; j++)
		{
			filter[i][j] = 0;
			delta_x[i][j] = i - _center_x;
			delta_y[i][j] = j - _center_y;
		}
	filter[centerx][centery] = 1.0;
}

void Filter::ChangeElement(int x, int y, double value)
{
	if (x < _width && x >= 0 && y < _height && y >= 0)
	{
		double previous_value = filter[x][y];
		double delta_value = previous_value - value;
		if (delta_value < 0)
			delta_value = -delta_value;
		filter[x][y] = value;
		if (delta_value > max_delta_value)
			emit Filter_Changed();
	}
}


void Filter::CreateAverageFilter(Filter* filter_out)
{
	filter_out->InitializeFilter(3,3,1,1);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			filter_out->ChangeElement(i,j,1.0/9);
}