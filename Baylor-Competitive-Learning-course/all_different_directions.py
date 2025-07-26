from sys import stdin
import math

def rads(x):
    return x * math.pi / 180

def dist(a, b):
    return (((a[0] - b[0])) ** 2 + ((a[1] - b[1]) ** 2)) ** 0.5

if __name__ == '__main__':
    count = 0
    coords = []
    for line in stdin:
        if count == 0:
            count = int(line)
            coords = []
        else:
            angle = 360 * 100

            inpoo = line.split()

            x = float(inpoo[0])
            y = float(inpoo[1])

            for i in range(2, len(inpoo), 2):
                if inpoo[i] == 'start' or inpoo[i] == 'turn':
                    angle += float(inpoo[i + 1])
                else:
                    r = float(inpoo[i + 1])

                    x += r * math.cos(rads(angle % 360))
                    y += r * math.sin(rads(angle % 360))
            
            coords.append((x, y))

            count -= 1

            if count == 0:
                avg_x = 0
                avg_y = 0

                for i in coords:
                    avg_x += i[0]
                    avg_y += i[1]
                
                avg_x /= len(coords)
                avg_y /= len(coords)

                maxi = -1
                for i in coords:
                    maxi = max(maxi, dist((avg_x, avg_y), i))

                print(f'{avg_x} {avg_y} {maxi}')
                