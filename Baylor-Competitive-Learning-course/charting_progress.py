from sys import stdin

def main():

    pos = -1
    for line in stdin:
        val = line.split('\n')[0]

        length = len(val)

        if pos == -1:
            pos = length - 1
        
        if len(val) == 0:
            pos = -1
            print()
            continue
        
        out = ['.' for i in range(length)]
        for i in range(length):
            if val[i] == '*':
                out[pos] = '*'
                pos -= 1
        print(''.join(out))

if __name__ == '__main__':
    main()