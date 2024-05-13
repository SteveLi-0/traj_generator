#include "matplotlibcpp.h"
#include "veh_model.h"
#include "ControlSeq.h"

namespace plt = matplotlibcpp;

int main()
{
    Vehicle veh(0.0, 0.0, 0.0, 3);

    // std::vector<double> acc(100, 0);
    // std::vector<double> deltaf(100, 10.0 / 180.0 * M_PI);
    ControlSeq ctrlseq(1000, 0.01);

    ctrlseq.setAcc(0, 1);
    ctrlseq.setDeltaf(5 / 180.0 * M_PI, 2);

    // for (auto i : ctrlseq.delta_f_) std::cout << i << ", ";

    // 数据
    std::vector<double> x;
    std::vector<double> y;
    std::vector<double> s;
    std::vector<double> theta;
    std::vector<double> curve;
    std::vector<double> v;
    std::vector<double> a;
    std::vector<double> delta;
    std::vector<double> t;


    for (int i = 0; i < ctrlseq.getSize(); ++i)
    {
        veh.updateTrajectory(ctrlseq.acc_[i], ctrlseq.delta_f_[i]);
        // std::cout << acc[i] << delta[i] << std::endl;
        // veh.printState();
        x.push_back(veh.getX());
        y.push_back(veh.getY());
        s.push_back(veh.getS());
        theta.push_back(veh.getTheta());
        curve.push_back(veh.getCurve());
        v.push_back(veh.getV());
        a.push_back(veh.getAcc());
        delta.push_back(veh.getDelta());

    }

    // plt
    // 绘制折线图
    plt::figure();
    plt::subplot(2, 3, 1);
    plt::plot(x, y);
    plt::title("x-y");
    // 显示图形
    plt::subplot(2, 3, 2);
    plt::plot(s, theta);
    plt::title("s-theta");

    plt::subplot(2, 3, 3);
    plt::plot(s, curve);
    plt::title("s-curve");

    plt::subplot(2, 3, 4);
    plt::plot(s, v);
    plt::title("s-v");

    plt::subplot(2, 3, 5);
    plt::plot(s, a);
    plt::title("s-a");

    plt::subplot(2, 3, 6);
    plt::plot(s, delta);
    plt::title("s-delta");


    plt::show();

}