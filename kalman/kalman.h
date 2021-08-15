include "matrix.h"

#ifndef KALMAN_H
#define KALMAN_H

#include "matrix.h"
#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

class kalman
{
private:
    /* data */


public:

    //state transistion matrix
    Matrix<float> mT;
    // input control matrix
    Matrix<float> mC;
    // measurement matrix
    Matrix<float> mM;
    // measurement noise covariance 
    Matrix<float> mEz;
    // process noise covariance
    Matrix<float> mEx_;
    // state vector
    vector<float> x;
    // state covariance matrix
    Matrix<float> mP;


    kalman();
    virtual ~kalman();

    void Init();

    void Predict(float dt, Q_, float u);

    void Update(float z, P_, float C);
    

};

#endif // KALMAN_H
