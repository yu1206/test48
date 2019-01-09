#include <iostream>
#include <vector>
#include<stdlib.h>
#include <time.h> 
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>  
#include <vector>

#include <opencv2\opencv.hpp>
#include <opencv2/highgui/highgui.hpp>    
#include <opencv2/core/core.hpp>

static std::vector<std::vector<cv::Point>> vctvctPoint;

cv::Mat org = cv::imread("E:\\yu1-plate-data\\4_��������-��������\\1-��E8C93Q.jpg", 1);

//cv::Mat org = cv::imread("E:\\new_����ģ�� - ����\\ͳ������\\2\\2624198-��BZ33.jpg", 1);

cv::Mat dst, maskImage,tempImg;
static std::vector<cv::Point> vctPoint;
static cv::Point ptStart = (-1, -1); //��ʼ�����
static cv::Point cur_pt = (-1, -1);  //��ʼ����ʱ�ڵ�
char temp[16];
int width = org.cols;
int height = org.rows;
FILE* file;





// ���� ����������״�������
void on_mouse13(int event, int x, int y, int flags, void *ustc)//event����¼����ţ�x,y������꣬flags��ק�ͼ��̲����Ĵ���    
{
	if (event == CV_EVENT_LBUTTONDOWN)
	{
		fprintf(file, "%f %f\n", x*1.0/width, y*1.0/height);
		std::cout << "x:" << x << " y:" << y << std::endl;
		ptStart = cv::Point(x, y);
		vctPoint.push_back(ptStart);
		cv::circle(org, ptStart, 1, cv::Scalar(255, 0, 255), CV_FILLED, CV_AA, 0);
		cv::imshow("src", org);
		//cv::putText(tmp, temp, ptStart, cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0, 0), 1, 8);
	}
	else if (event == CV_EVENT_MOUSEMOVE && (flags & CV_EVENT_FLAG_LBUTTON))
	{
		fprintf(file, "%f %f\n", x*1.0 / width, y*1.0 / height);
		std::cout << "x:" << x << " y:" << y << std::endl;
		cur_pt = cv::Point(x, y);
		cv::line(org, vctPoint.back(), cur_pt, cv::Scalar(0, 255, 0, 0), 1, 8, 0);
		cv::circle(org, cur_pt, 1, cv::Scalar(255, 0, 255), CV_FILLED, CV_AA, 0);
		cv::imshow("src", org);
		vctPoint.push_back(cur_pt);
		//cv::putText(tmp, temp, cur_pt, cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0, 0));
	}
	else if (event == CV_EVENT_LBUTTONUP)
	{
		fprintf(file, "%f %f\n", x*1.0 / width, y*1.0 / height);
		std::cout << "x:" << x << " y:" << y << std::endl;
		cur_pt = cv::Point(x, y);
		cv::line(org, ptStart, cur_pt, cv::Scalar(0, 255, 0, 0), 1, 8, 0);
		cv::circle(org, cur_pt, 1, cv::Scalar(255, 0, 255), CV_FILLED, CV_AA, 0);
		cv::imshow("src", org);
		vctPoint.push_back(cur_pt);
		vctvctPoint.push_back(vctPoint);
		//�ѵ㹹���������ν������
		const cv::Point * ppt[1] = { &vctPoint[0] };//ȡ������׵�ַ
		int len = vctPoint.size();
		int npt[] = { len };
		//	cv::polylines(org, ppt, npt, 1, 1, cv::Scalar(0,0, 0, 0), 1, 8, 0);	    
		//org.copyTo(maskImage);
		//cv::imshow("m", maskImage);
		//maskImage.setTo(cv::Scalar(0, 0, 0, 0));
		//cv::imshow("m1", maskImage);

		org.copyTo(dst);

		cv::fillPoly(dst, ppt, npt, 1, cv::Scalar(0, 0, 0));
		
		imwrite("1.jpg",dst);
		cv::imshow("m2", dst);

		//org.copyTo(dst, maskImage);
		//cv::imshow("��ͼ", dst);
		cv::waitKey(0);
	}
}

// ����������״�ĸ���Ȥ���� mask
void on_mouse14(int event, int x, int y, int flags, void *ustc)//event����¼����ţ�x,y������꣬flags��ק�ͼ��̲����Ĵ���    
{
	if (event == CV_EVENT_LBUTTONDOWN)
	{
		fprintf(file, "%f %f\n", x*1.0 / width, y*1.0 / height);
		std::cout << "x:" << x << " y:" << y << std::endl;
		ptStart = cv::Point(x, y);
		vctPoint.push_back(ptStart);
		cv::circle(org, ptStart, 1, cv::Scalar(255, 0, 255), CV_FILLED, CV_AA, 0);
		cv::imshow("src", org);
		//cv::putText(tmp, temp, ptStart, cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0, 0), 1, 8);
	}
	else if (event == CV_EVENT_MOUSEMOVE && (flags & CV_EVENT_FLAG_LBUTTON))
	{
		fprintf(file, "%f %f\n", x*1.0 / width, y*1.0 / height);
		std::cout << "x:" << x << " y:" << y << std::endl;
		cur_pt = cv::Point(x, y);
		cv::line(org, vctPoint.back(), cur_pt, cv::Scalar(0, 255, 0, 0), 1, 8, 0);
		cv::circle(org, cur_pt, 1, cv::Scalar(255, 0, 255), CV_FILLED, CV_AA, 0);
		cv::imshow("src", org);
		vctPoint.push_back(cur_pt);
		//cv::putText(tmp, temp, cur_pt, cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0, 0));
	}
	else if (event == CV_EVENT_LBUTTONUP)
	{
		fprintf(file, "%f %f\n", x*1.0 / width, y*1.0 / height);
		std::cout << "x:" << x << " y:" << y << std::endl;
		cur_pt = cv::Point(x, y);
		cv::line(org, ptStart, cur_pt, cv::Scalar(0, 255, 0, 0), 1, 8, 0);
		cv::circle(org, cur_pt, 1, cv::Scalar(255, 0, 255), CV_FILLED, CV_AA, 0);
		cv::imshow("src", org);
		vctPoint.push_back(cur_pt);
		vctvctPoint.push_back(vctPoint);
		//�ѵ㹹���������ν������
		const cv::Point * ppt[1] = { &vctPoint[0] };//ȡ������׵�ַ
		int len = vctPoint.size();
		int npt[] = { len };

		//cv::polylines(org, ppt, npt, 1, 1, cv::Scalar(0,0, 0, 0), 1, 8, 0);	    
		//cv::imshow("m", org);

		org.copyTo(maskImage);
		
		 maskImage.setTo(cv::Scalar(0, 0, 0));

		 cv::fillPoly(maskImage, ppt, npt, 1, cv::Scalar(255, 255, 255));

		//imwrite("1.jpg", dst);
		cv::imshow("m2", maskImage);

		org.copyTo(dst);
		dst.setTo(cv::Scalar(0, 0, 0));
		tempImg.copyTo(dst,maskImage);
		cv::imshow("��ͼ", dst);
		cv::imwrite("1.jpg",dst);
		cv::waitKey(0);
	}
}
int test48(int argc, char *argv[])
{
	tempImg = org.clone();
	file = fopen("1.txt", "wt");
	//�����
	cv::namedWindow("src");//����һ��img����    
	cv::setMouseCallback("src", on_mouse13, 0);//���ûص�����    
	cv::imshow("src", org);
	cv::waitKey(0);

	//fclose(file);

	return 0;
}






