#pragma once

#include "Filter.h"
#include <QImage>

enum Filters
{
	average,
	gradient_h,
	gradient_v,
	numbe_of_filters,
};

static char* Filter_names[] =
{
	"Average",
	"Gradient Horizontal",
	"Gradient Vertical",

	"End Of Filters",
};


struct Apply_Filter
{
	static void Apply_Predefined_Filter(QImage* image_out, QImage* image_in, Filters filter)
	{
		Filter* predefinedFilter = new Filter();
		switch (filter)
		{
		case average:
			Filter::CreateAverageFilter(predefinedFilter);
			break;
		default:
			break;
		}
		Apply_Custom_Filter(image_out, image_in, predefinedFilter);
		delete predefinedFilter;
	}

	static void Apply_Custom_Filter(QImage* image_out, QImage* image_in, Filter* custom_filter)
	{
		int width = image_in->width();
		int height = image_in->height();
		for (int i  = 0; i < width; i++)
			for (int j = 0; j < height; j++)
			{
				double r_value = 0;
				double g_value = 0;
				double b_value = 0;
				for (int x = 0; x < custom_filter->_width; x++)
				{
					for (int y = 0; y < custom_filter->_height; y++)
					{
						int x_pos = i - custom_filter->delta_x[x][y];
						int y_pos = j - custom_filter->delta_y[x][y];
						if (x_pos >= 0 && x_pos < width && y_pos >= 0 && y_pos < height)
						{
							r_value += image_in->pixelColor(x_pos, y_pos).red() * custom_filter->filter[x][y];
							g_value += image_in->pixelColor(x_pos, y_pos).green() * custom_filter->filter[x][y];
							b_value += image_in->pixelColor(x_pos, y_pos).blue() * custom_filter->filter[x][y];
						}
					}
				}
				image_out->setPixel(i,j,qRgb((int)r_value,(int)g_value,(int)b_value));
			}
	}

private:

};