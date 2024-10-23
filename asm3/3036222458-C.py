import sys

def input_vector():
    n, m = map(int, input().split())
    v = [[0] * n for _ in range(n)]
    
    for _ in range(m):
        a, b, t = map(int, input().split())
        v[a][b] = t
        v[b][a] = t
    return v

def input_constraints(n):
    return list(map(int, input().split()))

def mindist(dist, visited):
    min_val = sys.maxsize
    min_index = 0
    
    for i in range(len(dist)):
        if dist[i] <= min_val and not visited[i]:
            min_val = dist[i]
            min_index = i
    return min_index

def dijkstra(s, d, v, lockdown):
    dist = [sys.maxsize] * len(v)
    visited = [False] * len(v)
    dist[s] = 0
    
    for _ in range(len(v)):
        index = mindist(dist, visited)
        visited[index] = True
        
        for j in range(len(v)):
            if (not visited[j] and v[index][j] and 
                dist[index] != sys.maxsize and 
                dist[index] + v[index][j] < dist[j]):
                
                temp = dist[index] + v[index][j]
                if temp >= lockdown[j] and dist[index] != sys.maxsize:
                    continue
                dist[j] = temp
    
    return -1 if dist[d] == sys.maxsize else dist[d]

def main():
    v = input_vector()
    lockdown = input_constraints(len(v))
    s, d = map(int, input().split())
    print(dijkstra(s, d, v, lockdown))

if __name__ == "__main__":
    main()
