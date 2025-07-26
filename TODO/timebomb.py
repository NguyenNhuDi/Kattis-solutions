# Timebomb

from sys import stdin
import math


def read_word(x):
    lb = 0
    rb = 3
    
    s = '*'
    b = ' '
    zero =  [[s, s, s],
            [s, b, s],
            [s, b, s],
            [s, b, s],
            [s, s, s]]
    
    one =  [[b, b, s],
            [b, b, s],
            [b, b, s],
            [b, b, s],
            [b, b, s]]
    
    two =  [[s, s, s],
            [b, b, s],
            [s, s, s],
            [s, b, b],
            [s, s, s]]
    
    three =    [[s, s, s],
                [b, b, s],
                [s, s, s],
                [b, b, s],
                [s, s, s]]
    
    four =  [[s, b, s],
             [s, b, s],
             [s, s, s],
             [b, b, s],
             [b, b, s]]

    five =  [[s, s, s],
             [s, b, b],
             [s, s, s],
             [b, b, s],
             [s, s, s]]
    
    six =  [[s, s, s],
            [s, b, b],
            [s, s, s],
            [s, b, s],
            [s, s, s]]
    
    seven =  [[s, s, s],
              [b, b, s],
              [b, b, s],
              [b, b, s],
              [b, b, s]]
    
    eight =  [[s, s, s],
              [s, b, s],
              [s, s, s],
              [s, b, s],
              [s, s, s]]
    
    nine =   [[s, s, s],
              [s, b, s],
              [s, s, s],
              [b, b, s],
              [s, s, s]]
    

    num = ''

    while rb <= len(x[0]):
        char = [row[lb:rb] for row in x]
        if char == zero:
            num += '0'
        elif char == one:
            num += '1'
        elif char == two:
            num += '2'
        elif char == three:
            num += '3'
        elif char == four:
            num += '4'
        elif char == five:
            num += '5'
        elif char == six:
            num += '6'
        elif char == seven:
            num += '7'
        elif char == eight:
            num += '8'
        elif char == nine:
            num += '9'
        else:
            return False

        lb += 4
        rb += 4

    return True if  int(num) % 6 == 0 else False 



word = [[] for i in range(5)]

counter = 0
for line in stdin:
    for i in line:
        if i != '\n' and i != '\r':
            word[counter].append(i)

    counter += 1

print('BEER!!' if read_word(word) else 'BOOM!!')
