import matplotlib.pyplot as plt
import numpy as np

def recognize_pattern(string: str, l: int) -> dict:
    # result dictionary
    result = {}

    # split string
    split_string = string.split(" ")

    # - given pattern length l, find the repetitive substrings of length l in the string s
    #     - construct a dictionary of substrings of length l as key and the number of times
    #     they are seen in s as the value.
    for i in range(len(split_string) - l + 1):
        substring = ' '.join(split_string[i:i+l])
        if substring in result:
            result[substring]['count'] += 1
            result[substring]['indices'].append(i)
        else:
            result[substring] = {
                'count': 1,
                'indices': [i]
            }

    filtered_result = {}

    # filter dictionary
    for (pattern, info) in result.items():
        if info['count'] >= 2:
            filtered_result[pattern] = info

    # construct new string with repeated patterns removed
    for (pattern, info) in filtered_result.items():
        locations = info['indices']
        for i in locations:
            split_string = split_string[:i] + split_string[i+l:]


    # return a dictionary where the key is the pattern and the value is a dictionary
    #  that has two values
    #     - count: the number of times it was repeated >= 2.
    #     - locations: an array of indeces where the pattern occurred
    return filtered_result, ' '.join(split_string)

collected_patterns_f = open("collected_patterns.txt", "w")
lines = tuple(open("cx_ops.txt", 'r'))
counts = [0]*9

for line in lines:
    # skip QASM file name lines
    if line[0] == '.':
        continue
    # pattern lengths from 2 to 10
    for l in range (2, 11):
        print("Starting pattern length = ", l)
        # run pattern lookup for first time
        patterns, new_string = recognize_pattern(line, l)
        # Dump collected patterns into a file for later use and update histogram array
        for (pattern, info) in patterns.items():
            collected_patterns_f.write(pattern + '\n')
            # update histogram
            counts[l-2] += info["count"]

        # keep running pattern lookup until no patterns are found
        while patterns:
            patterns, new_string = recognize_pattern(new_string, l)
            # Dump collected patterns into a file for later use and update histogram array
            for (pattern, info) in patterns.items():
                collected_patterns_f.write(pattern + '\n')
                # update histogram
                counts[l-2] += info["count"]
        print(counts)


# Next deadline: 1 month and a half (late April) and mid July/ early August
    # ASPLOS: architecture system primary language operating systems
# repeat the pattern search until the function does not find any more patterns.
# Two levels of stats
    # pattern lengths: 
    #   10, 20, ...
    #   2 - 10
# Histogram: we have this many patterns of length say 2, 3, ..., 10 run on all the QASM benchmark
    # count all cx operations
