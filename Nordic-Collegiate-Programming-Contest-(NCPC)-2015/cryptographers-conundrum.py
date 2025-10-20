from sys import stdin

def main():
    inpoo = input()

    counter = 0
    for i, c in enumerate(inpoo):
        if i % 3 == 0 and c != "P":
            counter += 1
        
        if i % 3 == 1 and c != "E":
            counter += 1
        
        if i % 3 == 2 and c != "R":
            counter += 1

    print(counter)

if __name__ == '__main__':
    main()