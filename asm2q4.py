hashtable = [17,94,86,22,98,79,54,78]

newhashtable = []
totalI = 0
for i in hashtable:
    totalI += newhashtable.count(i % 7)
    newhashtable.append(i % 7)
print(hashtable)
print(newhashtable)
print(f"Q4b: average search till uncessessful search: {(7 + totalI) /7}")
#q4a

def q2hash(hash,i):
    return (hash + 3 * i) % 11

hashtablevalues = []
probinghash = [None] * 11
count = 0
for i in hashtable:
    newhash = i % 11
    newI = 1
    while newhash in hashtablevalues:
        newhash = q2hash(i,newI)
        newI += 1
    hashtablevalues.append(newhash)

for i in hashtablevalues:
    probinghash[i] = hashtable[hashtablevalues.index(i)]
print(probinghash)

for i in range(0,11):
    newI = 1
    count += 1
    newhash = i
    while probinghash[newhash] != None:
        newhash = q2hash(i,newI)
        newI += 1
        count += 1
print(f"Q4b: total searches: {count}")
print(f"Q4b: average search till uncessessful search: {count/11}")
#q4b

def q3hash(hash,i):
    return (hash % 11 + i * (2 - hash % 2)) % 11

hashtablevalues = []
probinghash = [None] * 11
count = 0
for i in hashtable:
    newhash = i % 11
    newI = 1
    while newhash in hashtablevalues:
        newhash = q3hash(i,newI)
        newI += 1
    hashtablevalues.append(newhash)

for i in hashtablevalues:
    probinghash[i] = hashtable[hashtablevalues.index(i)]
print(probinghash)

for i in range(0,11):
    newI = 1
    count += 1
    newhash = i
    while probinghash[newhash] != None:
        newhash = q3hash(i,newI)
        newI += 1
        count += 1
print(f"Q4c: total searches: {count}")
print(f"Q4c: average search till uncessessful search: {count/11}")
#q4c