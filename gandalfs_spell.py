#gandalf's spell

key = input()
key = list(key)
input = [str (x) for x in input().split()]


appeared = set()
dic = {}


def main():
    if len(key) != len(input):
        print("False")
        return
    
    for i in range(len(key)):
        c = key[i]
        
        if c not in dic and input[i] in appeared:
            print("False")
            return
        
        if c in dic and dic[c] != input[i]:
            print("False")
            return
        else:
            dic[c] = input[i]
    
        appeared.add(input[i])
    print("True")
             
main()
