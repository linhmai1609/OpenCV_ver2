#include "CVHelper.h"


cv::Mat CVHelper::imageProcessing(cv::Mat image) {
	int morph_elem = 0;
	int morph_size = 1;
	int dilate_size = 2;
	int const max_operator = 4;
	int const max_elem = 2;
	int const max_kernel_size = 21;

	cv::Mat grey, denoised, morph, dilated, result;

	cv::GaussianBlur(image, grey, cv::Size(7, 7), 5, 5, cv::BORDER_DEFAULT);

	cv::fastNlMeansDenoising(grey, denoised, 10, 7, 21);

	cv::Mat element = cv::getStructuringElement(morph_elem, cv::Size(2 * morph_size + 1, 2 * morph_size + 1), cv::Point(morph_size, morph_size));
	cv::Mat element2 = cv::getStructuringElement(morph_elem, cv::Size(2 * dilate_size + 1, 2 * dilate_size + 1), cv::Point(dilate_size, dilate_size));

	cv::morphologyEx(denoised, morph, cv::MORPH_CLOSE, element);

	cv::dilate(morph, morph, element2);

	cv::adaptiveThreshold(morph, result, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY, 11, 2);

	//cv::threshold(morph, result, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);

	return result;
}

listCharacters CVHelper::createListCharacter(cv::Mat img, int threshold) {
	cv::Mat bw = threshold < 128 ? (img < threshold) : (img > threshold);
	cv::Mat labelImage(img.size(), CV_32S);
	int nLabels = connectedComponents(bw, labelImage, 4);
	listCharacters newList = listCharacters();

	std::vector<cv::Vec3b> colors(nLabels);
	colors[0] = cv::Vec3b(0, 0, 0);

	cv::Mat dst(img.size(), CV_8UC3);
	std::map<int, character> objMap;

	for (int r = 0; r < dst.rows; ++r) {
		for (int c = 0; c < dst.cols; ++c) {
			int label = labelImage.at<int>(r, c);
			cv::Vec3b &pixel = dst.at<cv::Vec3b>(r, c);
			objMap[label].addPoint(c, r);
		}
	}

	for (auto i = objMap.begin(); i != objMap.end(); ++i) {
		i->second.drawBoundingBox();
		newList.addNewCharacter(i->first, i->second);
	}
	return newList;
}
