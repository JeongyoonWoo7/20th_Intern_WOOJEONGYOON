#include <opencvtest/opencvtest.hpp>
#include <iostream>
using namespace cv;


using namespace cv;
using namespace std;

namespace opencvtest {

    void processImage(const string &image_path) {
        Mat img = imread(image_path, IMREAD_COLOR);

        Mat img_blur;
        GaussianBlur(img, img_blur, Size(7, 7), 0);

        Mat green_mask, green_image, img_hsv;
        Mat red_mask, red_mask_1, red_mask_2, red_image;
        Mat blue_mask, blue_image;

        Scalar lower_green(35, 50, 50);
        Scalar upper_green(85, 255, 255);
        Scalar lower_red_1(0, 50, 50);
        Scalar upper_red_1(10, 255, 255);
        Scalar lower_red_2(170, 50, 50);
        Scalar upper_red_2(180, 255, 255);
        Scalar lower_blue(100, 50, 50);
        Scalar upper_blue(130, 255, 255);

        cvtColor(img, img_hsv, COLOR_BGR2HSV);

        inRange(img_hsv, lower_green, upper_green, green_mask);


        inRange(img_hsv, lower_red_1, upper_red_1, red_mask_1);
        inRange(img_hsv, lower_red_2, upper_red_2, red_mask_2);
        bitwise_or(red_mask_1, red_mask_2, red_mask);

        
        inRange(img_hsv, lower_blue, upper_blue, blue_mask);

        bitwise_and(img, img, green_image, green_mask);
        bitwise_and(img, img, red_image, red_mask);
        bitwise_and(img, img, blue_image, blue_mask);

        imshow("HSV Image", img_hsv);
        imshow("Green Mask", green_mask);
        imshow("Green Image", green_image);
        imshow("Red Mask", red_mask);
        imshow("Red Image", red_image);
        imshow("Blue Mask", blue_mask);
        imshow("Blue Image", blue_image);

        waitKey(0);
    }

} 

int main() {
    std::string image_path = "/home/jy/colcon_ws/src/opencvtest/ball.png";
    opencvtest::processImage(image_path);
    return 0;
}

