#ifndef KALMAN_HPP
#define KALMAN_HPP


#include <iostream>
#include "kalman.cpp"
#include<vector>

class Mat {
public:
    int n;
    int m;  
    
    Mat();
    float matrix() {
        vector<vector<float>> mat;
        return mat;
    }
}

class kalman
{
private:
    /* data */


public:

    //state transistion matrix
    Mat::matrix A_;
    // input control matrix
    Mat::matrix B_;
    // measurement matrix
    Mat::matrix C_;
    // measurement noise covariance 
    Mat::matrix Ez_;
    // process noise covariance
    Mat::matrix Ex_;
    // state vector
    vector<float> x_;
    // state covariance matrix
    Mat::matrix P_;


    kalman();
    virtual ~kalman();

    void Init ();

    void Predict();

    void Update();
    

};

#endif // KALMAN_HPP
