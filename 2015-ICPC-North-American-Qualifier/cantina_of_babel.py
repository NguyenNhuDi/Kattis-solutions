class Person:
    def __init__(self) -> None:
        self.speak = ''
        self.understand = set()
        self.name = ''



al, ids, low, ans, s, visited = [], [], [], [], [], []
id, sCount = 0, 0

def dfs(index):

    global id, sCount, al, ids, low, ans, s, visited

    ids[index], low[index] = id, id
    id += 1

    s.append(index);
    visited[index] = True;

    for next in al[index]:
        if ids[next] == -1: 
            dfs(next)

        if visited[next]:
            low[index] = min(low[index], low[next])


    if ids[index] == low[index]:
        while 1:
            node = s.pop()
            visited[node] = False
            ans[node] = sCount

            if node == index:
                break

        sCount += 1

def tarjan(n):
    global id, sCount, al, ids, low, ans, s, visited


    for i in range(n):
        visited.append(False)
        ids.append(-1)
        low.append(0)
        ans.append(0)

    for i in range(n):
        if ids[i] == -1:
            dfs(i)
    

def main():

    global id, sCount, al, ids, low, ans, s, visited

    n = int(input())


    persons = []

    for i in range(n):
        temp = Person()

        inpoo = input().split()

        temp.speak = inpoo[1]
        temp.understand = set(inpoo[1:])
        temp.name = inpoo[0]

        persons.append(temp)

    al = [[] for i in range(n)]
    
    for i in range(n):
        for j in range(n):
            if i == j : continue

            if persons[i].speak in persons[j].understand:
                al[i].append(j)

            if persons[j].speak in persons[i].understand:
                al[j].append(i)

    tarjan(n)

    out = {}

    for i in ans:
        if i in out:
            out[i] += 1
        else:
            out[i] = 1

    maxi = 0
    for key in out:
        maxi = max(maxi, out[key])

    print(n - maxi)
                
main()