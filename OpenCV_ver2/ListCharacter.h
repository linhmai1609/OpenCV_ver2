#pragma once
#include "Header.h"
#include "Character.h"
#include "Function.h"

#include <map>

class listCharacters {
	friend bool validateCharacter(character, listCharacters);
protected:
	bool rawData;
	bool detectedQP, detectedQS;
	std::map<int, character> mapOfCharacter;
	int meanFPoint, meanFW, meanFH;
	int QPoint[2], QH[2], QW[2];
public:
	listCharacters() {
		rawData = true;
		detectedQP = false;
		detectedQS = false;
	};
	void addNewCharacter(int, character);
	void calculateQ_Point();
	void calculateQ_Size();
	//void calculateMean_Point();
	void calculateMean_Size();
	void eliminateOutliers();
};