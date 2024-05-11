import numpy as np
from scipy.stats import norm
import matplotlib.pyplot as plt
 
STAGE_NUMBER = 11
PROBABILITY = .5
factorial = np.math.factorial

def p(k):

    return (factorial(STAGE_NUMBER)/(factorial(k)* factorial(STAGE_NUMBER - k)))*(PROBABILITY**k)*(1-PROBABILITY)**(STAGE_NUMBER-k)

print(p(0), p(1), p(2), p(3), p(4), p(5), p(6), p(7), p(8), p(9), p(10), p(11))

plt.bar(list(range(1, 13)), list(map(p,list(range(0,12)))), alpha=0.6, color='r')



n, p = 12, .5  # number of trials, probability of each trial
s = np.random.binomial(n, p, 20000)

print(s)
# Fit a normal distribution to
# the data:
# mean and standard deviation
mu, std = norm.fit(s) 

# Plot the histogram.
plt.hist(s, bins=12, density=True, alpha=0.6, color='b')

# Plot the PDF.
xmin, xmax = plt.xlim()
x = np.linspace(xmin, xmax, 100)
p = norm.pdf(x, mu, std)
 
plt.plot(x, p, 'k', linewidth=2)
title = "Fit Values: {:.2f} and {:.2f}".format(mu, std)
plt.title(title)
 
plt.show()