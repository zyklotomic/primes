import matplotlib.pyplot as plt
import numpy as np

with open('primes_list', 'r') as f:
    norm = 2
    count = 0
    for line in f:
        a,b = map(int, line.split())
