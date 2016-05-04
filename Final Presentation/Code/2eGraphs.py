'''
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		Project 2 - Schrodinger's Equation for two electrons in
					a three-dimensional harmonic oscillator well

		Part d)   -	Solving the 2-electron wavefunction of coordinate
					rho with varying omega_rho

					This program reads text files with normalized
					eigenvectors as a function of rho and graphs 
					the normalized dimensionless wavefunctions.

					Adjust the name of the file and graph as needed
					
					Wavefunctions are graphed and saved to png.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
'''

import math
import numpy as np 
from numpy import linalg as LA
import matplotlib.pyplot as plt 
from matplotlib import colors 

def getWavefunction(filename):

	file = open(filename, 'r')
	useful = file.readlines()

	rho = []
	u1 = []
	u2 = []
	u3 = []

	for line in useful:

		p, v1, v2, v3 = line.split()
		rho.append(float(p))
		u1.append(float(v1))
		u2.append(float(v2))
		u3.append(float(v3))

	rho = np.array(rho)
	u1 = np.array(u1)
	u2 = np.array(u2)
	u3 = np.array(u3)

	return rho, u1, u2, u3

x, y1, y2, y3 = getWavefunction('NormalWavefuncOmega0p01.txt')

fig , ax = plt.subplots(1) 

hfont = {'fontname':'Times New Roman','size':'14'}

plt.plot(x,y1,color='indianred',label="$u_0$",linewidth=2.0) 
plt.plot(x,y2,color='darkviolet',label="$u_1$",linewidth=2.0) 
plt.plot(x,y3,color='forestgreen',label="$u_2$",linewidth=2.0) 

ax.set_xlabel('Radial Coordinate $\\rho$',**hfont)
ax.set_ylabel("Wavefunction $|{u(\\rho)}|^2$",**hfont)
ax.legend(loc='upper right',fancybox='True',prop={'size':12})

plt.savefig('WavefunctionOmega0p01.png')
plt.show()









