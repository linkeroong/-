/*学习opencv 第4章课后练习2
	我们想要创建一个函数，通过创建一个统计图象来让矩形区域内的像诉求和操作更有效率。
	这个统计图像的每个像素将储存从源点到它所包含矩形区域的所有像素值的和。
	这个图像也被称为“积分图”，通过使用积分图中四个点的值，我们可以得到它包含的矩形区域像素值的和。
a. 创建一个100x200单通道uchar图像，并使用随机数填充，创建一个100x200单通道浮点数并将所有成员置为0.
b. 按照定义计算积分图。
c. 考虑如何有效利用已经计算得到积分图加上新的数值来加速积分图计算，实现这个更高效的方法。
d. 使用积分图像快速计算原始图像中任意矩形的像素之和。
e. 考虑如何修改积分图像，以便可以幼小即算出一个45度旋转矩形的和。详细描述算法。
*/
#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
int main(int argc, char **argv) {
	cv::Mat1b int_image(200, 100);
	cv::Mat1f float_image(200, 100);
	cv::RNG rng(12345);
	//对uchar1类型的Mat填充0-255的随机值
	rng.fill(int_image, cv::RNG::UNIFORM, 0, 255);
	//对float1类型的Mat赋值0
	float_image = 0;
	cv::namedWindow("int_image",cv::WINDOW_AUTOSIZE);
	cv::imshow("int_image", int_image);
	//在opencv 3.4.5中可以imshow单通道浮点 在4.0.0中不可以imshow单通道浮点
	cv::namedWindow("float_image", cv::WINDOW_AUTOSIZE);
	cv::imshow("float_image", float_image);
	cv::waitKey(0);
}