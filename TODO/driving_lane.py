import sys
from math import inf

N = 255
minDist = [[inf for _ in range(N)] for _ in range(N)]
len = [0] * N
S = [0] * N
C = [0] * N

n, m = map(int, input().split())
k, r = map(int, input().split())
for i in range(1, n+1):
    len[i] = int(input())
for i in range(1, n):
    S[i], C[i] = map(int, input().split())

minDist[0][1] = 0
for i in range(1, n+1):
    for j in range(1, m+1):
        maxLaneChanges = len[i] // k
        for l in range(max(1, j-maxLaneChanges), min(m, j+maxLaneChanges)+1):
            laneChanges = abs(l-j)
            distCurve = 0
            if i > 1:
                distCurve = S[i-1] + C[i-1]*l
            minDist[i][j] = min(minDist[i][j], laneChanges*(l+r) + len[i]-laneChanges*l + distCurve + minDist[i-1][l])

print(minDist[n][1])

