import matplotlib.pyplot as plt
import numpy as np

x,y = [],[]
with open('primes_list', 'r') as f:
    for line in f:
        a,b = map(int, line.split())
        x.append(a)
        y.append(b)

        # Append the conjugate and units
        if (b != 0):
            x.append(-a)
            y.append(-b)

            x.append(a)
            y.append(-b)

            x.append(-a)
            y.append(b)


            x.append(b)
            y.append(a)
            
            x.append(-b)
            y.append(-a)

            x.append(-b)
            y.append(a)

            x.append(b)
            y.append(-a)

plt.plot(x,y, 'bo', markersize=0.25)

plt.show()
