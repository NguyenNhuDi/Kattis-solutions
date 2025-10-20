from sys import stdin
import string 
from itertools import combinations

def make_triples(all_letters, words):
    
    out = []
    for d1 in combinations(all_letters, 6):
        if all_letters[0] not in d1:
            continue

        valid = True

        for word in words:
            a, b, c = word
            if not ((a in d1 and b not in d1 and c not in d1) \
            or (a not in d1 and b in d1 and c not in d1) \
            or (a not in d1 and b not in d1 and c in d1)):
                valid = False
                break

        if not valid:
            continue
        
        others = [c for c in all_letters if c not in d1]

        for d2 in combinations(others, 6):
            valid = True

            for word in words:
                a, b, c = word
                if not ((a in d2 and b not in d2 and c not in d2) \
                or (a not in d2 and b in d2 and c not in d2) \
                or (a not in d2 and b not in d2 and c in d2)):
                    valid = False
                    break

            if not valid:
                continue

            d3 = [c for c in others if c not in d2]

            if min(d2) >= min(d3):
                continue

            out.append((d1, d2, d3))

    return out

def main():
    n = int(input())
    words = []
    all_letters = set()

    #given abc, a, b, c must apear on seperate dices

    for i in range(n):
        word = input()

        if len(set(word)) != 3:
            print(0)
            return
        
        for c in word:
            all_letters.add(c)
        words.append(word)

    if len(all_letters) > 18:
        print(0)
        return 
    
    for c in string.ascii_lowercase:
        if len(all_letters) < 18:
            all_letters.add(c)

    all_letters = list(all_letters)

    ans = make_triples(all_letters, words)

    if len(ans) == 0:
        print(0)
    else:
        d1, d2, d3 = ans[0]
        print(''.join(d1), ''.join(d2), ''.join(d3))

if __name__ == '__main__':
    main()