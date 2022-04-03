import glob
import numpy as np 
from matplotlib import pyplot as plt

histogram = {}

for file in glob.glob('./histograms/*'):
    print('Reading %s', file)
    f = open(file, 'r')
    lines = f.readlines()
    for line in lines:
        nums = line.split(',')
        pattern_length = int(nums[0]) 
        if pattern_length in histogram:
            histogram[pattern_length] += int(nums[1])
        else:
            histogram[pattern_length] = int(nums[1])

print(histogram)

plt.bar(list(histogram.keys()), histogram.values())
plt.title("Pattern Length Histogram for All QASM Bench (2-10)")
plt.show()