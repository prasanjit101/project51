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

void kalman::Predict(float dt, Mat Q, float u) {
    
    Ex = Q * dt;
    // prediction 
    Mat A = Mat(
        1, -dt,
        0, 1
    );
   
    Mat B = Mat(dt, 0);
    
    x = A * x + B * u;  // current state

    Mat At = Mat::transpose(A);

    P = A * P * At + Ex; // next covariance matrix
}

void kalman::Update(float z, Mat P, float C) {
    // updation
    
    Mat Ez = Mat(
        1, 1,
        0, 0
    );
    Mat I = Mat(
        1, 0,
        0, 1
    );

    Mat C = Mat(1, 0);
    Mat Ct = Mat::transpose(C);
    
    S = C * P * Ct + Ez;
    K = P * Ct * (Mat::inverse(S)); // Kalman gain

    float y = z - x[0];
    x = x + Mat(K[0], K[1]) * y; // updating state estimate
    
    P = (I - K * C) * P; // updating covariance matrix
}

Mat Mat::transpose(vector<vector<int>> &b)
{
    if (b.size() == 0)
        return;

    vector<vector<int>> trans_vec(b[0].size(), vector<int>());

    for (int i = 0; i < b.size(); i++)
    {
        for (int j = 0; j < b[i].size(); j++)
        {
            trans_vec[j].push_back(b[i][j]);
        }
    }

    b = trans_vec; 
    return b;
}

Mat Mat::inverse(){
    // code for inversing a matrix
}
