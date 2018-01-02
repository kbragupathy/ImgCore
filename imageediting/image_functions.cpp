#include "image_functions.h"
#include <android/log.h>

void ImageEditor::sharpen(string inputImagePath, string outputImagePath, double alpha){

	Mat image = imread(inputImagePath);
	Mat new_image = Mat::zeros( image.size(), image.type() );

	cv::GaussianBlur(image,new_image, cv::Size(alpha, alpha), 0);


	//cv::addWeighted(image, 1.5, new_image, -0.5, 0, new_image);

	imwrite(outputImagePath,new_image);
	image.release();
	new_image.release();
}

void ImageEditor::adjustSaturation(string inputImagePath, string outputImagePath, double alpha){
	Mat src = imread(inputImagePath);
	Mat new_image = Mat::zeros( src.size(), src.type() );
	Mat img = Mat::zeros( src.size(), src.type() );

	cvtColor(src,img,CV_RGB2HSV);

	    int hue = 1;
	    int saturation = alpha - 255;
	    int value = 1;

	    for(int y=0; y<img.cols; y++)
	    {
	        for(int x=0; x<img.rows; x++)
	        {
	            int cur1 = img.at<Vec3b>(Point(y,x))[0];
	            int cur2 = img.at<Vec3b>(Point(y,x))[1];
	            int cur3 = img.at<Vec3b>(Point(y,x))[2];
	            cur1 += hue;
	            cur2 += saturation;
	            cur3 += value;

	            if(cur1 < 0) cur1= 0; else if(cur1 > 255) cur1 = 255;
	            if(cur2 < 0) cur2= 0; else if(cur2 > 255) cur2 = 255;
	            if(cur3 < 0) cur3= 0; else if(cur3 > 255) cur3 = 255;

	            img.at<Vec3b>(Point(y,x))[0] = cur1;
	            img.at<Vec3b>(Point(y,x))[1] = cur2;
	            img.at<Vec3b>(Point(y,x))[2] = cur3;
	        }
	    }

	    cvtColor(img,new_image,CV_HSV2RGB);
	    imwrite(outputImagePath,new_image);
	    src.release();
	    new_image.release();
	    img.release();
}

void ImageEditor::rotate(string inputImagePath, string outputImagePath){

	Mat image = imread(inputImagePath);
	Mat new_image = Mat::zeros( image.size(), image.type() );
	transpose(image, new_image);
	flip(new_image, new_image,1); //transpose+flip(1)=CW
	imwrite(outputImagePath,new_image);
	image.release();
	new_image.release();
	__android_log_print(ANDROID_LOG_DEBUG,"iamgefunctions","Inside rotate .. ");

}
void ImageEditor::adjustBrightness(string inputImagePath, string outputImagePath, double alpha){

	Mat image = imread(inputImagePath);
	Mat new_image = Mat::zeros( image.size(), image.type() );

	/// Initialize values
	__android_log_print(ANDROID_LOG_DEBUG,"iamgefunctions","alpha value %lf",alpha);

	image.convertTo(new_image, -1, 1, alpha);
	imwrite(outputImagePath,new_image);
	image.release();
	new_image.release();
	__android_log_print(ANDROID_LOG_DEBUG,"iamgefunctions","Inside AdjustBrightness, Contrast .. ");
}

void ImageEditor::adjustContrast(string inputImagePath, string outputImagePath, double alpha){

	Mat image = imread(inputImagePath);
	Mat new_image = Mat::zeros( image.size(), image.type() );

	/// Initialize values
	__android_log_print(ANDROID_LOG_DEBUG,"iamgefunctions","alpha value %lf",alpha);

	image.convertTo(new_image, -1, alpha, 0);

	imwrite(outputImagePath,new_image);
	image.release();
	new_image.release();
	__android_log_print(ANDROID_LOG_DEBUG,"iamgefunctions","Inside AdjustBrightness, Contrast .. ");
}

void ImageEditor::addText(string inputImagePath, string outputImagePath, string textToBeAdded){

	Mat image = imread(inputImagePath);

	int row = image.rows;
	int col = image.cols - 30;

	if(row >100){
		row -= 100;
	}

	if(col >200){
		row -=200;
	}
	__android_log_print(ANDROID_LOG_DEBUG,"iamgefunctions","Inside AdjustBrightness, row .. %d",row);

	putText(image, textToBeAdded.c_str(), cvPoint(100, 50),
			FONT_HERSHEY_PLAIN, 3, CV_RGB(204,255,0), 2.0);
	imwrite(outputImagePath,image);

	image.release();
}

