from sys import stdin

if __name__ == '__main__':

    vars = {}
    nums = {}

    for line in stdin:
        command = line.split()

        if command[0] == 'def':

            if command[1] in vars:
                del nums[vars[command[1]]]

            # storing the variable:
            vars[command[1]] = int(command[2]) 
            nums[int(command[2])] = command[1]

        elif command[0] == 'clear':
            vars = {}
            nums = {}

        elif command[0] == 'calc':
            out = 0
            add = True
            unknown = False
            for i, word in enumerate(command):
                if i == 0:
                    continue
                    
                if word == '+':
                    add = True
                    print('+', end=' ')
                elif word == '-':
                    add = False
                    print('-', end=' ')
                elif word == '=':
                    # print(command[out] if not unknown and out ielse 'unknown')
                    print('=', end = " ")

                    if out in nums and not unknown:
                        print(nums[out])
                    else:
                        print('unknown')
                else:
                    print(f'{word}', end=' ')
                    if word in vars:
                        out += vars[word] if add else -vars[word]
                    else:
                        unknown = True
