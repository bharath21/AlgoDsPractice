nums = [1, 2, 3, 4]
print()
prefix = [1]*len(nums)
suffix = [1]*len(nums)
for i in range(1, len(nums)):
    prefix[i] = nums[i-1]*prefix[i-1]
for i in range(len(nums)-2, -1, -1):
    suffix[i] = nums[i+1]*suffix[i+1]
print(prefix)
print(suffix)
output = []
for i in range(len(nums)):
    output.append(prefix[i]*suffix[i])
print(output)
