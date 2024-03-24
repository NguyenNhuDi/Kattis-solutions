def lis(nums):
    if not nums:
        return []

    # Temporary arrays to store the LIS
    lis = [nums[0]]
    lis_lengths = [1]

    for num in nums[1:]:
        if num > lis[-1]:
            lis.append(num)
            lis_lengths.append(len(lis))
        else:
            l, r = 0, len(lis) - 1
            while l < r:
                m = (l + r) // 2
                if lis[m] < num:
                    l = m + 1
                else:
                    r = m
            lis[l] = num
            lis_lengths.append(l + 1)

    # Reconstruct the LIS using lis_lengths
    length = max(lis_lengths)
    longest_subsequence = []
    for i in range(len(nums) - 1, -1, -1):
        if lis_lengths[i] == length:
            longest_subsequence.append(i)
            length -= 1
            if length == 0:
                break

    return longest_subsequence[::-1]

def main():
    while True:
        try:
            n = int(input())

            nums = [int(x) for x in input().split()]

            ans = lis(nums)

            print(len(ans))

            for x in ans:
                print(x, end=' ')
            print()

        except EOFError:
            break
        
main()