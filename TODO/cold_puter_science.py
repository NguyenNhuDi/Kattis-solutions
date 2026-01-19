from sys import stdin

def main():
    n = input()
    nums = [i for i in input().split() if int(i) < 0]
    print(len(nums))

if __name__ == '__main__':
    main()