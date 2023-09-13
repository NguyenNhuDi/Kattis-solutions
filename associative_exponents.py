# associative exponents

def main():
    nums = (int(x) for x in input().split())

    a, b, c = nums

    if a == 1 or c == 1:
        print("What an excellent example!")
        return 
    
    print("What an excellent example!" if b == c and c == 2 else "Oh look, a squirrel!")

main()
