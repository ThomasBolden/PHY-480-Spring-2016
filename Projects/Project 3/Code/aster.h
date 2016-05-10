#ifndef ASTER_H
#define ASTER_H
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>

class aster
{
public:
    // Properties
    double mass;
    double position[2];
    double velocity[2];
    double potentialE;
    double kineticE;

    // Initializers
    aster();
    aster(double M, double x, double y, double vx, double vy);

    // Functions
    double distance(aster neighbor);
    double GravitationalForce(aster neighbor, double G);
    double Acceleration(aster neighbor, double G);
    double KineticEnergy();
    double PotentialEnergy(aster &neighbor, double G, double epsilon);

};

#endif // ASTER_H