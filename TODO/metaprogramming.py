from sys import stdin

def main():

    vars = {}

    for line in stdin:
        command = line.split()
        if command[0] == 'define':
            vars[command[2]] = int(command[1])
        else:
            if command[1] not in vars or command[3] not in vars:
                print('undefined')
            else:
                l = vars[command[1]]
                r = vars[command[3]]
                op = command[2]
                if op == '<':
                    print('true' if l < r else 'false')
                elif op == '>':
                    print('true' if l > r else 'false')
                else:
                    print('true' if l == r else 'false')

if __name__ == '__main__':
    main()