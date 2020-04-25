#include "Header.h"
#include "ListCharacter.h"
#include "CVHelper.h"

int main() {
		
	cv::Mat img = cv::imread("D:/Personal/Repos/OCR_Nom/nlp_prep_modules/lvt001.jpg");

	cv::resize(img, img, cv::Size(), 1, 1, cv::INTER_LINEAR);
	cv::cvtColor(img, img, cv::COLOR_BGR2GRAY);

	CVHelper helper;
	img = helper.imageProcessing(img);

	listCharacters list = helper.createListCharacter(img, 100);

	list.drawAllBoundingBoxes(img);
	return 0;
}