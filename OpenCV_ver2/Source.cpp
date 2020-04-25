#include "Header.h"
#include "ListCharacter.h"
#include "CVHelper.h"

int main() {
	std::set<int> a= { 1,2,3 };
	a.insert(1);
	a.insert(4);
	for (auto b = a.begin(); b != a.end(); ++b) {
		std::cout << *b << " ";
	}
	std::cin.ignore();
	
	/*img = cv::imread("D:/Personal/Repos/OCR_Nom/nlp_prep_modules/lvt001.jpg");

	cv::resize(img, img, cv::Size(), 1, 1, cv::INTER_LINEAR);
	cv::cvtColor(img, img, cv::COLOR_BGR2GRAY);*/

	return 0;
}