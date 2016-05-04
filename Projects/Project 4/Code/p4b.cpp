/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    Project 4 - The Ising Model

    Part b)   - Ising model of a 2x2 array of molecules.
                This code computes: the mean energy E, mean magnetization |M|,
                the specific heat Cv and the susceptibility χ as functions of 
                T using periodic boundary conditions for L = 2 in the x and y 
                directions. 

    Results are saved to a text file.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

#include <iostream>
#include <fstream>
#include <iomanip>

#include <string>
#include <time.h>

#import <random>
#include <cmath>
#include "lib.h"

using namespace std;

ofstream myfile;

/* 
  ======= Function to return indices of largest off-diagonal element =======
  Arguments:
  mat A - matrix
  int n - size of square matrix
  int *k - new row
  int *l - new column
*/