include "matrix.h"

#ifndef KALMAN_H
#define KALMAN_H

using namespace std;

template <typename T> //using T for int 

class kalman
{
private:
    /* data */


public:

    //state transistion matrix
    template <typename T>
    Matrix<T>::Matrix A_;
    // input control Matrix
    Matrix<T>::Matrix B_;
    // measurement Matrix
    Matrix<T>::Matrix C_;
    // measurement noise covariance 
    Matrix<T>::Matrix Ez_;
    // process noise covariance
    Matrix<T>::Matrix Q_;
    // state vector
    vector<float> x_;
    // state covariance Matrix
    Matrix<T>::Matrix P_;



    kalman();
    virtual ~kalman();

    void Init();

    void Predict(float dt, Q_, float u);

    void Update(float z, P_, float C);
    

};

#endif // KALMAN_H
