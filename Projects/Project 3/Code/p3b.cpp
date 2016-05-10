/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    Project 3 - Modeling the Solar System

    Part b)   - The Earth-Sun System.
    			This program solves for the position over time using both the 
    			the velocity verlet algorithm and fourth or Runge-Kutta. 

    Results are saved to two text files, one for verlet and one for RK4.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
#define _USE_MATH_DEFINES

#include <iostream>
#include <fstream>
#include <iomanip>

#include <list>
#include <vector>
#include <tuple>        // std::tuple, std::get, std::tie, std::ignore
#include <string>

//#import <random>
//#include <armadillo>
#include <cmath>
#include "aster.h"

using namespace std;
//using namespace arma;

ofstream rk4file;
ofstream verletfile;

const double G = 4*M_PI*M_PI;

double RK4Solver(aster A, aster B){
	return 0.0;
}

// takes planets and returns list of new vectors

void VerletSolver(aster A, aster B){

	string verletfilename = "EarthSunVerlet.txt";

	verletfile.open(verletfilename);

	double max_time = 5.0; // years

	double nstep = 5e3; // integration points

	double h = max_time / nstep;

	//coordinates = ;

	// need vector space for all positions , 
	// 2 columns (x & y)
	// n rows, one for each planet
	// then a 1xn column veoctor for velocity

	double mA = A.mass;

	double mB = B.mass;

	double x,y,vx,vy,dvx,dvy,dx,dy,dr,dvdx,dvdy,vdx,vdy,r;
	

	for(int i=0; i<nstep; i++){

		r = A.distance(B);

		double x1[2] = {A.position};

		cout << x1 << endl;

		//cout << r << endl;

		/*

		x = B.position[0];

		y = B.position[1];

		vx = B.velocity[0];

		vy = B.velocity[1];

		dvx = G*x/(r*r*r);

		dvy = G*y/(r*r*r);

		dx = x - vx*h + 0.5*h*h*dvx;

	 	dy = y - vy*h + 0.5*h*h*dvy;

		dr = sqrt(dx*dx+dy*dy);

		dvdx = -G*mA*mB*dx/(dr*dr*dr); // from drdrdr

		dvdy = -G*mA*mB*dy/(dr*dr*dr);

		vdx = vx + 0.5*h*(dvdx+dvx);

		vdy = vy + 0.5*h*(dvdy+dvy);

		B.position[0] = dx;

		B.position[1] = dy;

		B.velocity[0] = vdx;

		B.velocity[1] = vdy;

		verletfile << x << '\t' << y << endl;

		// cout << r << endl;

		*/

	}

	return;
}

int main(){

	// body Name(M, x, y, vx, vy)
	aster Sun(1.0,0.0,0.0,0.0,0.0);
	aster Earth(3.040e-06,-9.7933E-01,-1.9876E-01,-2.6507e-02,1.9969e-02);

	string rk4filename = "EarthSunRK4.txt";

	rk4file.open(rk4filename);
	//verletfile.open(verletfilename);

	VerletSolver(Sun, Earth);

	//verletfile << Verlet;

	rk4file.close();
	verletfile.close();

	return 0;

}














