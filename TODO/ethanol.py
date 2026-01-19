from sys import stdin

def main():
    n = int(input())
    
    if n == 1:
        print('  H')
        print('  |')
        print('H-C-OH')
        print('  |')
        print('  H')
    elif n == 2:
        print('  H H')
        print('  | |')
        print('H-C-C-OH')
        print('  | |')
        print('  H H')       
    elif n == 3:
        print('  H H H')
        print('  | | |')
        print('H-C-C-C-OH')
        print('  | | |')
        print('  H H H')
    elif n == 4:
        print('  H H H H')
        print('  | | | |')
        print('H-C-C-C-C-OH')
        print('  | | | |')
        print('  H H H H') 
    elif n == 5:
        print('  H H H H H')
        print('  | | | | |')
        print('H-C-C-C-C-C-OH')
        print('  | | | | |')
        print('  H H H H H')               
    elif n == 6:
        print('  H H H H H H')
        print('  | | | | | |')
        print('H-C-C-C-C-C-C-OH')
        print('  | | | | | |')
        print('  H H H H H H')  
    elif n == 7:
        print('  H H H H H H H')
        print('  | | | | | | |')
        print('H-C-C-C-C-C-C-C-OH')
        print('  | | | | | | |')
        print('  H H H H H H H')  
    elif n == 8:
        print('  H H H H H H H H')
        print('  | | | | | | | |')
        print('H-C-C-C-C-C-C-C-C-OH')
        print('  | | | | | | | |')
        print('  H H H H H H H H') 
    elif n == 9:
        print('  H H H H H H H H H')
        print('  | | | | | | | | |')
        print('H-C-C-C-C-C-C-C-C-C-OH')
        print('  | | | | | | | | |')
        print('  H H H H H H H H H') 
    elif n == 10:
        print('  H H H H H H H H H H')
        print('  | | | | | | | | | |')
        print('H-C-C-C-C-C-C-C-C-C-C-OH')
        print('  | | | | | | | | | |')
        print('  H H H H H H H H H H') 
if __name__ == '__main__':
    main()