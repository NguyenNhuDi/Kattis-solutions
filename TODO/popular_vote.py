import math
import queue

def main():
    t = int(input())

    for _ in range(t):
        n = int(input())

        tVote = 0
        cHighest = -1
        cNum = -1

        tie = False
        for i in range(n):
            vote = int(input())

            tVote += vote
            
            if vote > cHighest:
                tie = False
                cHighest = vote
                cNum = i + 1
            elif vote == cHighest:
                tie = True
        
        if tie:
            print('no winner')
        else:
            if cHighest > tVote / 2:
                print(f'majority winner {cNum}')
            else:
                print(f'minority winner {cNum}')



main()
