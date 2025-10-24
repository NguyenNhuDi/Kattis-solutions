
def main():
    while True:
        n = int(input()) 

        if n == 0: 
            break
        words = [input() for i in range(n)]
        words.sort(key=lambda x:x[:2])

        for word in words:
            print(word)
        print()

if __name__ == '__main__':
    main()