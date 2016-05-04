/*
	aster class based on the planet class by M. Hjorth-Jensen (2016)
*/

#include "aster.h"


aster::aster()
{
	mass = 1.;
    position[0] = 1.;
    position[1] = 0.;
    velocity[0] = 0.;
    velocity[1] = 0.;
    potentialE = 0.;
    kineticE = 0.;
}


aster::body(double M, double x, double y, double vx, double vy)
{
	mass = M;
	position[0] = x;
	position[1] = y;
	velocity[0] = vx;
	velocity[1] = vy;
	potentialE = 0.; // is this line necessary ??
	kineticE = 0.;
}

double aster::distance(body neighbor)
{
	double x1,y1,x2,y2,dx,dy,r;

	x1 = this->position[0];
	y1 = this->position[1];

	x2 = neighbor.position[0];
	y2 = neighbor.position[1];

	dx = x1-x2;
	dy = y1-y2;

	r = sqrt(dx*dx + dy*dy);

	return r;
}

double aster::GravitationalForce(body neighbor, double G);
{
	double r = this->distance(neighbor);
	if(r!=0.0) return G*this->mass*neighbor.mass/(r*r);
	else return 0;
}

double aster::Acceleration(body neighbor, double G);
{
	double r = this->distance(neighbor);
    if(r!=0) return this->GravitationalForce(neighbor,G)/(this->mass*r);
    else return 0;
}

double aster::KineticEnergy();
{
	double velocity2 = (this->velocity[0]*this->velocity[0]) + (this->velocity[1]*this->velocity[1]);
    return 0.5*this->mass*velocity2;
}

double aster::PotentialEnergy(body &neighbor, double G, double epsilon);
{
	if(epsilon==0.0) return -G*this->mass*neighbor.mass/this->distance(neighbor);
    else return (G*this->mass*neighbor.mass/epsilon)*(atan(this->distance(neighbor)/epsilon) - (0.5*M_PI));
}