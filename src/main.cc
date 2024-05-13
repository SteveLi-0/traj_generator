#include "matplotlibcpp.h"
#include "veh_model.h"

namespace plt = matplotlibcpp;

int main()
{
    Vehicle veh(0.0, 0.0, 0.0, 5);

    std::vector<double> acc(100, 0);
    std::vector<double> deltaf(100, 10.0 / 180.0 * M_PI);
    
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


    for (int i = 0; i < acc.size(); ++i)
    {
        veh.updateTrajectory(acc[i], deltaf[i]);
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
    plt::subplot(3, 1, 1);
    plt::plot(x, y);
    // 显示图形

    plt::subplot(3, 1, 2);
    plt::plot(s, theta);
    plt::subplot(3, 1, 3);
    plt::plot(s, curve);

    plt::show();

}