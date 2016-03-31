'''
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		Project 2 - Schrodinger's Equation for two electrons in
					a three-dimensional harmonic oscillator well

		Part b)   -	Plotting the number of transformations required
					to diagonalize a square matrix of size n.
					The trendline was T = n
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
'''

import math
import numpy as np 
from numpy import linalg as LA
import matplotlib.pyplot as plt 
from matplotlib import colors 

n = np.array([50,100,150,200,250,300,350,400,450,500])
T = np.array([4139,17293,39377,70538,110646,160133,\
			  218405,284916,361794,447415])

x = []
i = 50

while i <= 500:
	x.append(i)
	i += 1

i = np.array(i)
p = []
q = []

for value in x:
	p.append(value*value)
	q.append(value*value*value)

z = np.polyfit(n,T,2)
f = np.poly1d(z)

print(f)

fig , ax = plt.subplots(1) 

hfont = {'fontname':'Times New Roman','size':'14'}

plt.plot(x,f(x),color='black',label="$T = 1.808n^2 - 9.926n + 178$",linewidth=1.0) 
plt.plot(x,p,color='darkgray',label="$T = n^2$",linewidth=2.0) 
#plt.plot(x,q,color='gainsboro',label="$T = n^3$",linewidth=1.0) 
plt.plot(n,T,ls='None',color='crimson',marker='8',markeredgewidth=0.0)

plt.ylim(0,460000)
plt.xlim(25,525) 

ax.set_ylabel('Transformations',**hfont)
ax.set_xlabel("Square Matrix Dimension $n$",**hfont)
ax.legend(loc='center left',fancybox='True',prop={'size':12})

plt.savefig('TvsN.png')
plt.show()