from sys import stdin
import math

def main():
    x1, y1, x2, y2, major_axis = map(float, input().split())
    semi_major_axis = major_axis /2
    a = semi_major_axis
    c = math.sqrt((x1 - x2)**2 + (y1 - y2)**2) / 2
    b = math.sqrt(a ** 2 - c ** 2)

    semi_minor_axis = b

    c_x = (x1 + x2) / 2
    c_y = (y1 + y2) / 2
    rad = math.atan2(y1 - y2, x1 - x2)
    rot_90 = rad + (math.pi / 2)

    ux = semi_major_axis * math.cos(rad)
    uy = semi_major_axis * math.sin(rad)
    vx = semi_minor_axis * math.cos(rot_90)
    vy = semi_minor_axis * math.sin(rot_90)

    h_width = math.sqrt(ux ** 2 + vx ** 2) 
    h_height = math.sqrt(uy ** 2 + vy ** 2)

    print(f'{c_x - h_width:.6f} {c_y - h_height:.6f} {c_x + h_width:.6f} {c_y + h_height:.6f}')

if __name__ == '__main__':
    main()
