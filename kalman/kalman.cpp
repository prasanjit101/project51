// kalman filter implementation using cpp

#include "kalman.h"

#define PI 3.1415

using namespace std;


// functions
kalman::kalman() {}
kalman::~kalman() {}

void kalman::Init() {

    //  initialize variables
}
template <typename T>
void kalman::Predict(float dt, Matrix Q, float u) {
    
    Ex = Q * dt;
    // prediction 
    Matrix<T> A = Matrix(
        1, -dt,
        0, 1
    );
   
    Matrix<T> B = Matrix(dt, 0);
    
    x = A * x + B * u;  // current state

    Matrix<T> At = Matrix::transpose(A);

    P = A * P * At + Ex; // next covariance matrix
}

void kalman::Update(float z, Matrix P, float C) {
    // updation
    
    Matrix<T> Ez = Matrix(){
        1, 1,
        0, 0
    };
    Matrix<T> I = Matrix(
        1, 0,
        0, 1
    );

    Matrix<T> C = Matrix(1, 0);
    Matrix<T> Ct = Matrix::transpose(C);
    
    S = C * P * Ct + Ez;
    K = P * Ct * (Matrix::inverse(S)); // Kalman gain

    float y = z - x[0];
    x = x + Matrix(K[0], K[1]) * y; // updating state estimate
    
    P = (I - K * C) * P; // updating covariance matrix
}


