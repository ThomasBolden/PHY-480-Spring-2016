#ifndef ASTER_H
#define ASTER_H
#define _USE_MATH_DEFINES
#include <cmath>

class body
{
public:
    // Properties
    double mass;
    double position[3];
    double velocity[3];
    double potentialE;
    double kineticE;

    // Initializers
    body();
    body(double M, double x, double y, double z, double vx, double vy, double vz);

    // Functions
    double distance(body neighbor);
    double GravitationalForce(body neighbor, double Gconst);
    double Acceleration(body neighbor, double Gconst);
    double KineticEnergy();
    double PotentialEnergy(body &neighbor, double Gconst, double epsilon);

};

#endif // ASTER_H