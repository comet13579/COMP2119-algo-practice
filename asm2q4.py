hashtable = [17,94,86,22,98,79,54,38]

linkedlisthash = [None] * 7
def q1hash(hash):
    return hash % 7
for i in range(7):
    linkedlisthash[i] = []
for i in hashtable:
    newhash = i % 7
    linkedlisthash[newhash].append(i)
print(linkedlisthash)
print(f"Q4a: average search till uncessessful search: {(7 + 8) /7}")
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