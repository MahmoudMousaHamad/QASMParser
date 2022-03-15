def recognize_pattern(string: str, l: int) -> dict:
    # result dictionary
    result = {}

    # split string
    split_string = string.split(" ")
    print(split_string)

    # - given pattern length l, find the repetitive substrings of length l in the string s
    #     - construct a dictionary of substrings of length l as key and the number of times
    #     they are seen in s as the value.
    for i in range(len(split_string) - l + 1):
        substring = ' '.join(split_string[i:i+l])
        print(substring)
        if substring in result:
            result[substring]['count'] += 1
            result[substring]['indices'].append(i)
        else:
            result[substring] = {
                'count': 1,
                'indices': [i]
            }

    print(result)
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


# - define an initial string
string = "257 1 383 257 381 257 1 383 129 1 257 257 1 383 257"
# pattern length l
l = 4

result, new_string = recognize_pattern(string, l)

print('Pattern: ', result)
print('New string: ', new_string)

# Next deadline: 1 month and a half (late April) and mid July/ early August
    # ASPLOS: architecture system primary language operating systems
# TODO: Add feature to tool that dumps the strings collected into a file for later use.
# repeat the pattern search until the function does not find any more patterns.
# Two levels of stats
    # pattern lengths: 
    #   10, 20, ...
    #   2 - 10
# Histogram: we have this many patterns of length say 2, 3, ..., 10 run on all the QASM benchmark
    # count all cx operations