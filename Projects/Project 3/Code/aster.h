#ifndef ASTER_H
#define ASTER_H
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>

class body
{
public:
    // Properties
    double mass;
    double position[2];
    double velocity[2];
    double potentialE;
    double kineticE;

    // Initializers
    body();
    body(double M, double x, double y, double vx, double vy);

    // Functions
    double distance(body neighbor);
    double GravitationalForce(body neighbor, double G);
    double Acceleration(body neighbor, double G);
    double KineticEnergy();
    double PotentialEnergy(body &neighbor, double G, double epsilon);

};

#endif // ASTER_H