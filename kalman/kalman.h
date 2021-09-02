#ifndef KALMAN_H
#define KALMAN_H

#include "matrix.h"
#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

template <class U>
class kalman
{
private:
    


public:

    //state transistion matrix
    Matrix<U> mT;
    // input control matrix
    Matrix<U> mC;
    // measurement matrix
    Matrix<U> mM;
    // measurement noise covariance 
    Matrix<U> mEz;
    // process noise covariance
    Matrix<U> mEx_;
    // state vector
    vector<U> x;
    // state covariance matrix
    Matrix<U> mP;
    // initialised state
    Matrix<U> Q_;

    kalman(Matrix<U>,Matrix<U>,Matrix<U>,Matrix<U>,Matrix<U>,Matrix<U>,Matrix<U>);
    virtual ~kalman();

    void Init(Matrix<U> T,Matrix<U> C,Matrix<U> M,Matrix<U> Ez,Matrix<U> Ex,Matrix<U> X,Matrix<U> P);

    void Predict(float dt,Matrix<float> Q_, float u);

    void Update(float z, Matrix<float> mP, float mC, Matrix<float> x);
    

};

#endif // KALMAN_H
