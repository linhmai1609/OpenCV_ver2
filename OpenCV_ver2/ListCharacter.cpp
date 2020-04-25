#include "ListCharacter.h"

//ListCharacters class method
void listCharacters::addNewCharacter(int position, character c) {
	mapOfCharacter[position] = c;
}

//void listCharacters::calculateMean_Point() {
//	if (!rawData) {
//		std::vector<int> numOfPoints;
//		for (auto a = this->mapOfCharacter.begin(); a != this->mapOfCharacter.end(); ++a) {
//			numOfPoints.push_back(a->second.setofPoints.size());
//		}
//		meanFPoint = std::accumulate(std::begin(numOfPoints), std::end(numOfPoints), 0.0) / std::size(numOfPoints);
//	}
//	else {
//		std::cout << "Raw data!\n";
//	}
//}

void listCharacters::calculateMean_Size() {
	if (!rawData) {
		std::vector<int> heightList, widthList;
		for (auto a = this->mapOfCharacter.begin(); a != this->mapOfCharacter.end(); ++a) {
			heightList.push_back(a->second.boundingBox.height);
			widthList.push_back(a->second.boundingBox.width);
		}

		meanFH = std::accumulate(std::begin(heightList), std::end(heightList), 0.0) / std::size(heightList);
		meanFW = std::accumulate(std::begin(widthList), std::end(widthList), 0.0) / std::size(widthList);
	}
	else {
		std::cout << "Raw data!\n";
	}
}

void listCharacters::calculateQ_Point() {
	if (!rawData) {
		std::vector<int> numOfPoints;
		for (auto a = this->mapOfCharacter.begin(); a != this->mapOfCharacter.end(); ++a) {
			numOfPoints.push_back(a->second.setofPoints.size());
		}
		std::sort(numOfPoints.begin(), numOfPoints.end());
		int mid_index = median(0, numOfPoints.size());
		QPoint[0] = numOfPoints[median(0, mid_index)];
		QPoint[1] = numOfPoints[median(mid_index + 1, numOfPoints.size())];
	}
}

void listCharacters::calculateQ_Size() {
	std::vector<int> heightList, widthList;
	for (auto a = this->mapOfCharacter.begin(); a != this->mapOfCharacter.end(); ++a) {
		heightList.push_back(a->second.boundingBox.height);
		widthList.push_back(a->second.boundingBox.width);
	}

	std::sort(heightList.begin(), heightList.end());
	std::sort(widthList.begin(), widthList.end());

	int mid_index_h = median(0, heightList.size());
	int mid_index_w = median(0, widthList.size());

	QH[0] = heightList[median(0, mid_index_h)];
	QH[1] = heightList[median(mid_index_h + 1, heightList.size())];

	QW[0] = widthList[median(0, mid_index_w)];
	QW[1] = widthList[median(mid_index_w + 1, widthList.size())];
	detectedQS = true;
}

void listCharacters::eliminateOutliers() {
	if (detectedQS) {
		rawData = false;
		std::set<int> killList;
		for (auto a = this->mapOfCharacter.begin(); a != this->mapOfCharacter.end(); ++a) {
			if (a->second.boundingBox.height > this->QH[1] || a->second.boundingBox.height < this->QH[0]
				|| a->second.boundingBox.width > this->QW[1] || a->second.boundingBox.width < this->QW[1]) {
				killList.insert(a->first);
			}
		}
		for (auto a = killList.begin(); a != killList.end(); ++a) {
			this->mapOfCharacter.erase(*a);
		}
	}
}

