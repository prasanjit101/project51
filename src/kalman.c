#include<stdio.h>
#include<math.h>


struct Estimates {
    double P_est, X_est;
};

typedef struct Estimates Struct;
// kalman filter function ,i.e, all equations 
// func name (float or int objects)
// resultng equations and results.
// need to make the covariances in python

Struct kf(double P_prev, double X_est_prev, float Q, float R, float Y,int dim) {
    //for loop
        // equations
    //return results
    // need to think about transistion, control and meas matrices
    // initializing variables like kalman gain and all
    Struct s;
    float K, P_temp, X_temp_est;
    double P, X_est_last, X_est;
    for (int i=0;i<dim;i++) {
        // initial values of states
        P = 0.0;
        X_est_last = 0.0;
        X_temp_est = X_est_last;
        P_temp = P_prev + Q;
        //kalman gain
        K = P_temp * (1.0/(P_temp + R));

        // estimates
        X_est = X_temp_est + K * (Y - X_temp_est);
        P = (1 - K) * P_temp;
        X_est_last = X_est;
        

    }
    
    s.P_est = P;
    s.X_est = X_est_last;
    return s;

}

