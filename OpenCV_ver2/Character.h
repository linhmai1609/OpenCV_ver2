#pragma once
#include "Header.h"
#include "Point.h"

#include<vector>

class character {
	friend class listCharacters;
protected:
	std::vector<point> setofPoints;
	cv::Rect boundingBox;
public:
	void addPoint(int, int);
	void drawBoundingBox();
	cv::Rect getBoundingBox() {
		return boundingBox;
	}
};
