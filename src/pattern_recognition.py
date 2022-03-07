def recognize_pattern(string: str, l: int) -> dict:
    # result dictionary
    result = {}

    # split string
    split_string = string.split(" ")

    # - given pattern length l, find the repetitive substrings of length l in the string s
    #     - construct a dictionary of substrings of length l as key and the number of times
    #     they are seen in s as the value.
    for i in range(len(split_string) - l):
        substring = ' '.join(split_string[i:i+l])
        if substring in result:
            result[substring]['count'] += 1
            result[substring]['indeces'].append(i)
        else:
            result[substring] = {
                'count': 1,
                'indeces': [i]
            }

    filtered_result = {}

    # filter dictionary
    for (pattern, info) in result.items():
        if info['count'] >= 2:
            filtered_result[pattern] = info

    # construct new string with repeated patterns removed
    for (pattern, info) in filtered_result.items():
        locations = info['indeces']
        for i in locations:
            split_string = split_string[:i] + split_string[i+l:]


    # - return a dictionary where the key is the pattern and the value is a dictionary
    #  that has two values
    #     - count: the number of times it was repeated >= 2.
    #     - locations: an array of indeces where the pattern occurred
    return filtered_result, ' '.join(split_string)


# - define an initial string
string = "257 1 383 257 381 257 1 383 129 1 257 257 1 383"
# pattern length l
l = 3

result, new_string = recognize_pattern(string, l)

print('Pattern: ', result)
print('New string: ', new_string)