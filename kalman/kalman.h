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
    // initialised state
    Matrix<float> Q_;

    kalman();
    virtual ~kalman();

    void Init();

    void Predict(float dt,Matrix<float> Q_, float u);

    void Update(float z, Matrix<float> mP, float mC, Matrix<float> x);
    

};

#endif // KALMAN_H
