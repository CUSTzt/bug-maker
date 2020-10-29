#coding=utf-8
import numpy as np
import math
import matplotlib.pyplot as plt
fac = []
fac.append( 1 )
fac.append( 1 )
while( len( fac ) < 50 ):
    fac.append( fac[-1] * len( fac ) )
ex = np.linspace(-2, 4, 1000)
sinx = np.linspace(-2 * np.pi, 2 * np.pi, 1000)
ey = np.zeros( 1000 )
siny = np.zeros( 1000 )
for j in range(0, 40):
    ey = ey + abs( ex ) ** j / fac[j]
for index in range(len(ey)):
    if ex[index] < 0 :
        ey[index] = 1 / ey[index]
for j in range(1, 20):
    if j & 1:
        siny = siny + sinx ** (2 * j - 1) / fac[2 * j - 1]
    else:
        siny = siny - sinx ** (2 * j - 1) / fac[2 * j - 1]
plt.subplot(121)
plt.plot(ex, ey)
plt.subplot(122)
plt.plot(sinx, siny)
plt.show()