hashtable = [17,94,86,22,98,79,54,78]

newhashtable = []
totalI = 0
for i in hashtable:
    totalI += newhashtable.count(i % 7)
    newhashtable.append(i % 7)
print(hashtable)
print(newhashtable)
print("total unsuccessful search:", totalI)
print()
#q4a

newhashtable = []
totalI = 0
for i in hashtable:
    newhash = i % 11
    newI = 1
    while newhash in newhashtable:
        newhash = (newhash + 3 * newI) % 11
        newI += 1
    totalI += newI - 1
    print(newI - 1, end=" ")
    newhashtable.append(newhash)
print()
print(hashtable)
print(newhashtable)
print("total unsuccessful search:", totalI)
print()
#q4b

newhashtable = []
totalI = 0
for i in hashtable:
    newhash = i % 11
    newI = 1
    while newhash in newhashtable:
        newhash = (i % 11 + (2 - i % 2) * newI) % 11
        newI += 1
    totalI += newI - 1
    newhashtable.append(newhash)
    print(newI - 1, end=" ")
print()
print(hashtable)
print(newhashtable)
print("total unsuccessful search:", totalI)
#q4c