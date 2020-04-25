#pragma once
#include "Header.h"
#include "ListCharacter.h"
#include "Character.h"

class CVHelper {
public:
	CVHelper() {  };

	listCharacters createListCharacter(cv::Mat, int);
	cv::Mat imageProcessing(cv::Mat);
};