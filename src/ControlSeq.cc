#include "ControlSeq.h"

ControlSeq::ControlSeq(int n, double dt) : n_(n), dt_(dt) 
{
    acc_.resize(n, 0);
    delta_f_.resize(n, 0);
}
ControlSeq::~ControlSeq() {}

void ControlSeq::setAcc(double acc, int index)
{
    if (index == 0)
    {
        for (int i = 0; i < n_ / 2; ++i)
        {
            acc_[i] = acc;
        }
        for (int i = n_ / 2; i < n_; ++i)
        {
            acc_[i] = -acc;
        }
    }
    else if (index == 1)
    {
        for (int i = 0; i < n_; ++i)
        {
            acc_[i] = acc;
        }
    }
}

void ControlSeq::setDeltaf(double df, int index)
{
    if (index == 0)
    {
        for (int i = 0; i < n_ / 2; ++i)
        {
            delta_f_[i] = df;
        }
        for (int i = n_ / 2; i < n_; ++i)
        {
            delta_f_[i] = -df;
        }
    }
    else if (index == 1)
    {
        for (int i = 0; i < n_; ++i)
        {
            delta_f_[i] = df;
        }
    }
    else if (index == 2)
    {
        double t = 0.0; 
        for (int i = 0; i < n_; ++i)
        {

            delta_f_[i] = df * sin(t);
            t += M_PI / 128.0;
        }
    }
}

int ControlSeq::getSize() const
{
    return n_;
}
