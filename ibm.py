# array of strings
listOfStrings = ["z", "cde", "bc"]
for i in range(0, 10):
    first = listOfStrings[i]
    for j in range(i, len(listOfStrings)):
        if(first > listOfStrings[j]):
            listOfStrings[i] = listOfStrings[j]
            listOfStrings[j] = first
print(listOfStrings)


def foo(k):
    k.clear()


l = ["a", "z"]
foo(l)
print(l)



def getRecords(httpRequest):
