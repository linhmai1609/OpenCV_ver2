#include "Header.h"

//Object class
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

	boundingBox = cv::Rect(setX.front(), setY.front(), std::abs(setX.front() - setX.back()), std::abs(setY.front() - setY.back()));
}

void listCharacters::addNewCharacter(int position, character c) {
	mapOfCharacter[position] = c;
}