//
// Created by balajiv on 27/5/17.
//

#ifndef CURTAIN_IMAGE_FUNCTIONS_H
#define CURTAIN_IMAGE_FUNCTIONS_H
#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <math.h>
#include <cstring>
#include <opencv2/opencv.hpp>
#include <algorithm>
#include <fstream>
#include <dirent.h>
#include <string.h>
#include <algorithm>


using namespace std;
using namespace cv;

class ImageEditor{

	bool isdebug;
	string cachepath;
public:

	ImageEditor(bool isdebug){
		this->isdebug = isdebug;
	}

	void sharpen(string inputImagePath, string outputImagePath, double alpha);
	void adjustBrightness(string inputImagePath, string outputImagePath, double alpha);
	void adjustContrast(string inputImagePath, string outputImagePath, double alpha);
	void adjustSaturation(string inputImagePath, string outputImagePath, double alpha);
	void rotate(string inputImagePath, string outputImagePath);
	void addText(string inputImagePath, string outputImagePath, string textToBeAdded);

};

#endif //CURTAIN_CURT_FUNCTIONS_H
