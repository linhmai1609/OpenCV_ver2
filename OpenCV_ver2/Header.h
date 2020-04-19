#pragma once
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<string>
#include<conio.h>
#include<vector>
#include<set>
#include <opencv2/core/core.hpp>
#include<fstream>
#include <numeric>

#include <opencv2/core/utility.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <map>
#include <vector>

#include <opencv2/photo.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

class point {
	friend class character;
protected:
	int x;
	int y;
public:
	point(int x, int y) {
		this->x = x;
		this->y = y;
	}

};

class character {
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

class listCharacters {
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
