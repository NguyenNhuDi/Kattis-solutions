from sys import stdin
import heapq
import math

def main():
    n, k = map(int, input().split())

    pq = [0]
    heapq.heapify(pq)

    maxi = 0
    for i in range (n):
        time = int(input())

        while len(pq) > 0 and time >= pq[0]:
            top = heapq.heappop(pq)
        
        heapq.heappush(pq, time + 1000)
        maxi = max(len(pq), maxi)

    
    print(math.ceil(maxi / k))
        
    

if __name__ == '__main__':
    main()