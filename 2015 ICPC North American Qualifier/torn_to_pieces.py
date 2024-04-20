INF = 0xfffffffffffff

def dijkstra(s, e, al):
    dist = {key : INF for key in al}
    visited = {key : False for key in al} 
    dist[s] = 0
    path = {key : key for key in al}

    while True:
        mini = INF
        mItem = ''

        for key in dist:
            if dist[key] < mini and not visited[key]:
                mItem = key
                mini = dist[key]

        if mItem == '': break

        visited[mItem] = True

        for next in al[mItem]:
            if dist[next] > dist[mItem] + 1 and not visited[next]:
                dist[next] = dist[mItem] + 1
                path[next] = mItem

    out_path = []
    cNode = e

    while 1:
        if path[cNode] == cNode: break

        out_path.append(cNode)
        cNode = path[cNode]

    out_path.append(cNode)

    return dist, out_path

def main():
    n = int(input())

    al = {}

    for _ in range(n):
        inpoo = [str(x) for x in input().split()]

        s = inpoo[0]

        for i in inpoo[1:]:
            if s in al: al[s].add(i)
            else: al[s] = {i}

            if i in al: al[i].add(s)
            else: al[i] = {s}

    s, e = input().split()

    if s not in al or e not in al:
        print("no route found")
        return

    dist, path = dijkstra(s,e, al)

    if dist[e] == INF: print("no route found")
    else:
        for i in reversed(path):
            print(i, end=' ')
        print()


main()