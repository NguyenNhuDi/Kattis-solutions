#sun and moon

sun = (int(x) for x in input().split())
moon = (int(x) for x in input().split())

lSun, sun_length = sun
lMoon, moon_length = moon

nsun = sun_length - lSun
nmoon = moon_length - lMoon

out = 0
while True:

    if nsun == nmoon and nmoon == 0:
        print(out)
        break

    if nsun == 0:
        nsun = sun_length


    if nmoon == 0:
        nmoon = moon_length

    nsun -= 1
    nmoon -= 1
    out += 1
  

