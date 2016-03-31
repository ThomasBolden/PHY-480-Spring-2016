'''
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		Project 2 - Schrodinger's Equation for two electrons in
					a three-dimensional harmonic oscillator well

		Part b)   -	Comparing the dependency on rho and n to have
					four leading digits for the eigenvalues.
					This means for the lowest three eigenvalues,
					the computation returns at least
					(2.999,6.999,10.99)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
'''

import math
import numpy as np 
from numpy import linalg as LA
import matplotlib.pyplot as plt 
from matplotlib import colors 

rho = np.array([5.0,6.0,7.0,8.0,9.0,10.0])
n = np.array([200.0,250.0,300.0,350.0,400.0,450.0])
m , b = np.polyfit(rho,n,1)

fig , ax = plt.subplots(1) 

hfont = {'fontname':'Times New Roman','size':'14'}

plt.plot(rho,m*rho+b,color='black',label="$u_1$",linewidth=1.0) 
plt.plot(rho,n,ls='None',color='orange',marker='8',markeredgewidth=0.0)

plt.xlim(4.75,10.25)
plt.ylim(175,475) 

ax.set_xlabel('$\\rho_{{max}}$',**hfont)
ax.set_ylabel("Square Matrix Dimension $n$",**hfont)

plt.savefig('RhoDepend.png')
plt.show()