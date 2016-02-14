# -*- coding: utf-8 -*-
"""
Created on Sun Feb 14 00:10:43 2016

@author: Thomas
"""

# testing testing 123

import math
import matplotlib.pyplot as plt

def convert(rawdata):
    
    x = []
    u = []
    v = []
    
    file = open(rawdata , 'r')
    valid_data = file.readlines()[3:]
    
    for line in valid_data:
        
        xuv = line.split()
        x.append(float(xuv[0])) 
        u.append(float(xuv[1])) 
        v.append(float(xuv[2]))
        
    file.close()

    return x, u, v
    
x10 , u10 , v10 = convert('n=10')
x100 , u100 , v100 = convert('n=100')
x1000 , u1000 , v1000 = convert('n=1000')

exact = []

for value in x1000:
    
    f = 1.0-(1-math.exp(-10))*value-math.exp(-10*value)
    
    exact.append(f)

hfont = {'fontname':'Courier'}

fig , ax = plt.subplots(1) 

ax.plot(x10,v10,'g-',label='n=10, v(x)')
ax.plot(x100,v100,'b-',label='n=100, v(x)')
ax.plot(x1000,v1000,'m-',label='n=1000, v(x)')
ax.plot(x1000,exact,'k--',label='Exact , u(x)')
ax.set_xlabel('x',**hfont)
ax.set_ylabel('u(x)',**hfont) 
ax.legend(loc='lower left',fancybox='True')
ax.set_title('Comparing Solutions for Various Step Sizes',**hfont) 
ax.grid()
plt.show()
