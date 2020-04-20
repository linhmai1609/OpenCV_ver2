#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <vector>
#include<map>

bool validateCharacter(character, listCharacters);

class point {
	friend class character;
private:
	int x;
	int y;
public:
	point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};
class character {
	friend class listCharacters;
	friend bool validateCharacter(character, listCharacters);
private:
	std::vector<point> listOfPoints;
	cv::Rect boundingBox;
	int meanNoPoints;
	std::vector<int> Q;
public:
	void addPoint(point);
	void addBoundingBox();
};	

class listCharacters{
	friend bool validateCharacter(character, listCharacters);
private:
	std::map<int, character> mapOfCharacter;
	int meanFPoint, meanFW, meanFH;
	int QPoint[2], QH[2], QW[2];
public:
	void addNewCharacter(int, character);
	void calculateQ_Point();
	void calculateQ_Size();
	void calculateMean_Point();
	void calculateMean_Size();
};


