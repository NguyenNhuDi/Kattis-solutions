john_aah = input()

doctor_aah = input()

john_counter = 0

for i in john_aah:
    john_counter += 1

for j in doctor_aah:
    john_counter-= 1

if john_counter < 0:
    print("no")
else:
    print("go")
