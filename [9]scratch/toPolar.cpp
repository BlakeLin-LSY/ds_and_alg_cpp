#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
    // Sample (x, y) coordinates
    std::vector<cv::Point> points = {
        cv::Point(100, 100),
        cv::Point(150, 150),
        cv::Point(200, 100),
        cv::Point(250, 150),
        cv::Point(300, 100)};

    cv::Mat image = cv::Mat::zeros(400, 400, CV_8UC3); // Create a blank image

    for (const cv::Point &point : points)
    {
        cv::circle(image, point, 3, cv::Scalar(0, 255, 0), -1); // Draw points on the image
    }

    std::vector<cv::Vec3f> circles;
    cv::HoughCircles(image, circles, cv::HOUGH_GRADIENT, 1, 20, 100, 30, 0, 0);

    for (const cv::Vec3f &circle : circles)
    {
        cv::Point center(cvRound(circle[0]), cvRound(circle[1]));
        int radius = cvRound(circle[2]);

        // Draw the circle center
        cv::circle(image, center, 3, cv::Scalar(0, 0, 255), -1);
        // Draw the circle outline
        cv::circle(image, center, radius, cv::Scalar(0, 0, 255), 2);

        std::cout << "Circle center: (" << center.x << ", " << center.y << "), Radius: " << radius << std::endl;
    }

    cv::imshow("Detected Circles", image);
    cv::waitKey(0);

    return 0;
}