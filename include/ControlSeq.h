#pragma once
#include <iostream>
#include <cmath>
#include <vector>

class ControlSeq
{
private:
    /* data */
    int n_;
    double dt_;

public:
    std::vector<double> acc_;
    std::vector<double> delta_f_;

    ControlSeq(int n=100, double dt = 0.01);
    ~ControlSeq();

    void setAcc(double acc=1, int index = 0);

    void setDeltaf(double df = 15 / 180 * M_PI, int index = 0);

    int getSize() const;
};
