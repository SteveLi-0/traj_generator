#include "veh_model.h"

int main()
{
    Vehicle veh(0.0, 0.0, 0.0);

    std::vector<double> acc(10, 1);
    
    for (auto i : acc)
    {
        veh.updateTrajectory(i, 0.0);
        veh.printState();
    }


}