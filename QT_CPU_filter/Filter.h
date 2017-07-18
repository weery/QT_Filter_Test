#pragma once

#include <QObject>



class Filter : public QObject
{
	Q_OBJECT
public:
	Filter();
	~Filter();

	

	void InitializeFilter(int width, int height, int centerx, int centery);

	double** filter;
	int** delta_x;
	int** delta_y;
	int _width, _height, _center_x, _center_y;
	const double max_delta_value = 0.05;
	static void CreateAverageFilter(Filter* filter_out);
private:

signals:
	void Filter_Changed();

public slots:
	void ChangeElement(int x, int y, double value);


};

namespace SpatialFilters
{
	static Filter AverageFilter;
}