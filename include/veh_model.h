#pragma once
#include <iostream>
#include <cmath>
#include <vector>

class Vehicle {
private:
    // Vehicle state variables
    double l;         // wheel base
    double lf;
    double lr;
    double x;        // x-coordinate in global frame
    double y;        // y-coordinate in global frame
    double psi;      // yaw angle (heading)
    double beta;     // cg. side slip angle
    double curvature;// curvature of the trajectory
    double v;        // velocity
    double a;        // acceleration
    double s;        // accumulated distance
    double delta;    // front wheel angle
    double t;        // time
    double theta;

public:
    // Constructor
    // Vehicle(double init_x, double init_y, double init_psi, 
    // double init_v, double init_a, double init_beta,
    // double init_lf, double init_lr);
    Vehicle(double init_x, double init_y, double init_psi, 
                    double init_v = 0, double init_a = 0, double init_beta = 0, 
                    double init_lf = 1.25, double init_lr = 1.25);
    void setL(double val);

    // Method to update vehicle trajectory
    void updateTrajectory(double longitudinal_acceleration, double front_wheel_angle, double dt = 0.1);
    // Method to print vehicle state
    void printState();

    // get x
    double getX() const;
    // get y
    double getY() const;
    // get psi
    double getPsi() const;
    // get theta
    double getTheta() const;
    // get beta
    double getBeta() const;
    // get curvature
    double getCurve() const;
    // get v
    double getV() const;
    // get a
    double getAcc() const;
    // get s
    double getS() const;
    // get delta
    double getDelta() const;
    // get t
    double getT() const;
};
