'''
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		Project 2 - Schrodinger's Equation for two electrons in
					a three-dimensional harmonic oscillator well

		Part d)   -	Solving the 2-electron wavefunction of coordinate
					rho with varying omega_rho
					
					Wavefunctions are graphed and saved to png.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
'''

import math
import numpy as np 
from numpy import linalg as LA
import matplotlib.pyplot as plt 
from matplotlib import colors 

def getWavefunction(n,omega_r,p,filename):

	rho = []
	u1 = []
	u2 = []
	u3 = []

	h = p / n
	e = -1.0/(h^2)

	i = 0

	return rho, u1, u2, u3
