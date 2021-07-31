#ifndef KALMAN_H
#define KALMAN_H


#include <iostream>
#include <vector>

using namespace std;

template <typename T> //using T for int 
class Mat {
private:
    T n;
    T m;
    
public:
    Mat(T a,T b){
        n=a;m=b;
    };
    vector <vector<float>> mat;

    void setMatrix(vector<vector<float>> A) {
        mat=A;
    }
    float getMatrix(){
        return mat;
    }

    void transpose();
    void inverse();
};

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

#endif // KALMAN_H
