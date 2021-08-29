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
template <typename U>
void Predict(float dt, Matrix<U> Q, float u) {
    
    Matrix<U> Ex = Q * dt;
    // prediction 
    // Matrix<U> A({{1, -dt},{0, 1}});
   // A should be jacobians of x

    Matrix<U> B({dt, 0});
    
    Matrix<U> x = A * x + B * u;  // current state

    Matrix<U> At = A.transpose();

    Matrix<U> P = (A * P) * At + Ex; // next covariance matrix
}

template <typename U>
void Update(float z, Matrix<U> P, Matrix<U> C, Matrix<U> x) {
    // updation
    
    Matrix<U> Ez({{1, 1},{0, 0}});
    Matrix<U> I({{1,0},{0,1}});

    Matrix<U> Ct = C.transpose(); // C is jaconians of x[0]
    
    Matrix<U> S = (C * P) * Ct + Ez;
    Matrix<U> K = (P * Ct) * (S.inverse()); // Kalman gain

    float y = z - x[0];
    x = x + Matrix<U>(K[0], K[1]) * y; // updating state estimate
    
    P = (I - K * C) * P; // updating covariance matrix
}


