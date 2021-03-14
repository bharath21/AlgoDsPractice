def get_masked_string(string, substrings):
    masked_string = [False] * len(string)
    end = 0
    for i in range(len(string)):
        for sub_string in substrings:
            if(i+len(sub_string) <= len(string) and string[i:i+len(sub_string)] == sub_string):
                end = max(end, i+len(sub_string))
        masked_string[i] = end > i
    return masked_string


def embolden_substrings(string, substrings):
    if len(string) == 0 or len(substrings) == 0:
        return string
    masked_string = get_masked_string(string, substrings)
    print(masked_string)
    prev_value = masked_string[0]
    prev_index = 0
    tagged_string = ""

    for i in range(1, len(masked_string)):
        if masked_string[i] == prev_value:
            continue
        else:
            if prev_value == True:
                tagged_string += "<b>"+string[prev_index:i]+"</b>"
            else:
                tagged_string += string[prev_index:i]
            prev_value = masked_string[i]
            prev_index = i
    if prev_value == True:
        tagged_string += "<b>"+string[prev_index:]+"</b>"
    else:
        tagged_string += string[prev_index:]

    return tagged_string


print(embolden_substrings('abcxyz', ['abc', 'xyz']))
