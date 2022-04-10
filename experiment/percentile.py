import numpy as np

patterns_count_map = {}

f = open('./patterns_file.txt')
lines = f.readlines()
for line in lines:
    components = line.split(',')
    pattern_count = int(components[0])
    pattern = tuple(int(i) for i in components[1].split()) 
    pattern_length = len(pattern)

    if pattern_length in patterns_count_map:
        if pattern in patterns_count_map:
            patterns_count_map[pattern_length][pattern] += pattern_count
        else:
            patterns_count_map[pattern_length][pattern] = pattern_count
    else:
        patterns_count_map[pattern_length] = {pattern: pattern_count}

# print(patterns_count_map)

min_counts = [0]*9

for i in range(2, 11):
    min_counts[i-2] = np.percentile(list(patterns_count_map[i].values()), 99) if i in patterns_count_map else 0

print('Patterns with 80 percentile must have at lease the following count: ', min_counts)

# filter to get the patterns with at least the acquired number of counts
f = open('final_patterns.txt', 'w')
new_patterns = {}
for (length, patterns_counts) in patterns_count_map.items():
    for (pattern, count) in patterns_counts.items():
        if count >= min_counts[length - 2]:
            f.write(str(pattern) + '\n')
            if length in new_patterns:
                new_patterns[length][pattern] = count
            else:
                new_patterns[length] = {pattern: count}

# print("Patterns that make up 99% of all occurances for per pattern length ", new_patterns)