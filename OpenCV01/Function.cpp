#include "Header.h"

void character::addPoint(point x) {
	listOfPoints.push_back(x);
}

void character::addBoundingBox() {
	std::vector<int> X, Y;
	for (auto i = listOfPoints.begin(); i != listOfPoints.end(); ++i) {
		X.push_back(i->x);
		Y.push_back(i->y);
	}

	std::sort(X.begin(), X.end());
	std::sort(Y.begin(), Y.end());
	this->boundingBox = cv::Rect(X.front(), Y.front, 
		std::abs(X.front()-X.back()), std::abs(Y.front()-Y.back()) );
}

void listCharacters::addNewCharacter(int position, character c) {
	mapOfCharacter[position] = c;
}

