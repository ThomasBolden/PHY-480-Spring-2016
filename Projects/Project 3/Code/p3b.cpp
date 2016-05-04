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

#include <string>
#include <time.h>

//#import <random>
#include <cmath>
//#include "aster.h"
#include "planet.h"

using namespace std;

ofstream rk4file;
ofstream verletfile;

const double G = 4*M_PI*M_PI;

double RK4Solver(planet A, planet B){
	return 0;
}

double VerletSolver(planet A, planet B){

	double x,y,vx,vy;

	double r = A.distance(B);

	return  r;
}

int main(){

	// body Name(M, x, y, vx, vy)
	planet Sun(1.0,0.0,0.0,0.0,0.0);
	planet Earth(0.166e-06,0.21005,0.23395,-2.6507e-02,1.9969e-02);

	string rk4filename = "EarthSunRK4.txt";
	string verletfilename = "EarthSunVerlet.txt";

	rk4file.open(rk4filename);
	verletfile.open(verletfilename);

	double Verlet = VerletSolver(Sun, Earth);

	verletfile << Verlet;

	rk4file.close();
	verletfile.close();

	return 0;

}














