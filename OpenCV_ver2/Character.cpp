#include "Character.h"

//Character class method
void character::addPoint(int x, int y) {
	setofPoints.push_back(point(x, y));
}

void character::drawBoundingBox() {
	std::vector<int> setX, setY;
	for (auto a = setofPoints.begin(); a != setofPoints.end(); ++a) {
		setX.push_back(a->x);
		setY.push_back(a->y);
	}

	std::sort(setX.begin(), setX.end());
	std::sort(setY.begin(), setY.end());

	boundingBox = cv::Rect(setX.front()-3, setY.front()-3, std::abs(setX.front() - setX.back()) +6, std::abs(setY.front() - setY.back())+6 );
}
