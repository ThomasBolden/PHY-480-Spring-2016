import matplotlib.pyplot as plt
import numpy as np
import math
from matplotlib import colors

def getplots(filename):
	
	x = []
	y = []

	file = open(filename , 'r')
	useful = file.readlines()

	for line in useful:

		xpos , ypos = line.split()
		x.append(float(xpos))
		y.append(float(ypos))
	
	x = np.array(x)
	y = np.array(y)
	#m , b = np.polyfit(t,c,1)
	
	return x,y

x,y = getplots('EarthSunVerlet.txt')

fig , ax = plt.subplots(1) 

hfont = {'fontname':'Times New Roman','size':'14'}

#plt.plot(x,y,ls='None',color='lightskyblue',marker='8',label="$\Delta$ Absorbance",markeredgewidth=0.0)
plt.plot(x,y,'r-',label="Fit Line",linewidth=2.0)
#plt.plot(t15,m15*t15+b15,'k-')

#ax.set_title('Absorbtion in D$_2$O Solution During Reaction Using H$_2$O as a Reference\n',**hfont)
ax.set_xlabel('$x$ position (AU)',**hfont)
ax.set_ylabel("$y$ position (AU)",**hfont)
#ax.legend(loc='center right',fancybox='True',prop={'size':12})

plt.savefig('EarthSun.png')
plt.show()