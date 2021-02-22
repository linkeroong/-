/*ѧϰopencv ��4�¿κ���ϰ2
	������Ҫ����һ��������ͨ������һ��ͳ��ͼ�����þ��������ڵ�������Ͳ�������Ч�ʡ�
	���ͳ��ͼ���ÿ�����ؽ������Դ�㵽�������������������������ֵ�ĺ͡�
	���ͼ��Ҳ����Ϊ������ͼ����ͨ��ʹ�û���ͼ���ĸ����ֵ�����ǿ��Եõ��������ľ�����������ֵ�ĺ͡�
a. ����һ��100x200��ͨ��ucharͼ�񣬲�ʹ���������䣬����һ��100x200��ͨ���������������г�Ա��Ϊ0.
b. ���ն���������ͼ��
c. ���������Ч�����Ѿ�����õ�����ͼ�����µ���ֵ�����ٻ���ͼ���㣬ʵ���������Ч�ķ�����
d. ʹ�û���ͼ����ټ���ԭʼͼ����������ε�����֮�͡�
e. ��������޸Ļ���ͼ���Ա������С�����һ��45����ת���εĺ͡���ϸ�����㷨��
*/
#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
int main(int argc, char **argv) {
	cv::Mat1b int_image(200, 100);
	cv::Mat1f float_image(200, 100);
	cv::RNG rng(12345);
	//��uchar1���͵�Mat���0-255�����ֵ
	rng.fill(int_image, cv::RNG::UNIFORM, 0, 255);
	//��float1���͵�Mat��ֵ0
	float_image = 0;
	cv::namedWindow("int_image",cv::WINDOW_AUTOSIZE);
	cv::imshow("int_image", int_image);
	
	for (int i = 0; i <= 10; i++) {
		for (int j = 0; j <= 10; j++)
		{

			cout << (int)int_image.at<uchar>(i, j) << "\t";
		}
		cout << endl;
	}
	cout << "---------------------------------------------------------------------------------------" << endl;
	//���ڵ�ͨ�������Mat�������ͼ
	for (int i = 0; i <=199; i++) {
		for (int  j = 0; j <= 99; j++)
		{

			float_image.at<float>(i, j) = cv::sum(int_image.rowRange(0, i+1).colRange(0, j+1))[0];
		}
	}


	for (int i = 0; i <= 10; i++) {
		for (int j = 0; j <= 10; j++)
		{

			cout << float_image.at<float>(i, j)<<"\t" ;
		}
		cout << endl;
	}
	cout <<"---------------------------------------------------------------------------------------"<< endl;
	//ʹ�û��ּ�����������е�����֮��
	//�磺ָ������start(3,3)  end(6,6)
	long sum = float_image.at<float>(6-1, 6-1) - float_image.at<float>(6-1, 3 - 1) - float_image.at<float>(3 - 1, 6-1) + float_image.at<float>(3 - 1, 3 - 1);
	cout << sum << endl;
	float_image /= float_image.at<float>(199, 99);


	//��opencv 3.4.5�п���imshow��ͨ������ ��4.0.0�в�����imshow��ͨ������
	cv::namedWindow("float_image", cv::WINDOW_AUTOSIZE);
	cv::imshow("float_image", float_image);
	cv::waitKey(0);
}