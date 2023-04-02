statue = int(input())

printer = 1

day = 0

statues_made = 0

def print_statue(day):
    day += 1

    return day

def print_printer(number_to_print,number_of_printer):
    new = number_of_printer

    new += number_to_print

    return new

while statues_made < statue:

    if printer >= statue:
        statues_made += printer
        day = print_statue(day)

    elif printer < statue:

        if printer == 1:
            printer = print_printer(1,printer)
            day += 1

        elif printer > 1:

            printer = print_printer(printer,printer)

            day += 1

print(day)
