#include "veh_model.h"

Vehicle::Vehicle(double init_x, double init_y, double init_psi, 
    double init_v, double init_a, double init_beta,
    double init_lf, double init_lr)
        : l(init_lf + init_lr), lf(init_lf), lr(init_lr),
            x(init_x), y(init_y), psi(init_psi), beta(init_beta),
            curvature(0.0), v(init_v), a(init_a), s(0.0), 
            delta(0.0), t(0.0), theta(init_beta + init_psi) {}

void Vehicle::setL(double val)
{
    l = val;
}

void Vehicle::updateTrajectory(double longitudinal_acceleration, double front_wheel_angle, double dt) 
{
    // Update acceleration and front wheel angle
    a = longitudinal_acceleration;
    delta = front_wheel_angle;
    // Update time
    t += dt; // Assuming time step of 1 second
    // Update velocity
    v += a * dt;
    // Update accumulated distance
    s += v * dt;
    // Update beta psi
    beta = std::atan((lr * std::tan(delta)) / l);
    psi += v * std::tan(beta) / lr;
    // Update curvature (assuming constant curvature for simplicity)
    curvature = std::tan(delta) / l;
    // Update position and orientation
    x += v * std::cos(psi) / std::cos(beta);
    y += v * std::sin(psi) / std::cos(beta);
    // theta
    theta = beta + psi;
}

void Vehicle::printState() 
{
    std::cout << "Vehicle State:" << std::endl;
    std::cout << "x: " << x << ", y: " << y << ", psi: " << psi << std::endl;
    std::cout << "Curvature: " << curvature << ", Velocity: " << v << ", Acceleration: " << a << std::endl;
    std::cout << "Accumulated Distance: " << s << ", Front Wheel Angle: " << delta << ", Time: " << t << std::endl;
}


// get
// get x
double Vehicle::getX() const
{
    return x;
}
// get y
double Vehicle::getY() const
{
    return y;
}
// get psi
double Vehicle::getPsi() const
{
    return psi;
}
// get theta
double Vehicle::getTheta() const
{
    return theta;
}
// get beta
double Vehicle::getBeta() const
{
    return beta;
}
// get curvature
double Vehicle::getCurve() const
{
    return curvature;
}
// get v
double Vehicle::getV() const
{
    return v;
}
// get a
double Vehicle::getAcc() const
{
    return a;
}
// get s
double Vehicle::getS() const
{
    return s;
}
// get delta
double Vehicle::getDelta() const
{
    return delta;
}
// get t
double Vehicle::getT() const
{
    return t;
}