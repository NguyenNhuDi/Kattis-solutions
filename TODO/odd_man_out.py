def main():
    n = int(input())

    for i in range(n):
        nums = {}

        _ = input()

        for x in input().split():

            if x in nums: nums[x] += 1
            else: nums[x] = 1

        for key in nums:
            if nums[key] == 1:
                print(f'case #{i+1}: {key}')
                break


main()