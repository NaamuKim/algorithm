numbers_sum = []
numbers_filtered = []
maxnumber = 0

count = int(input('입력 받을 숫자 갯수를 입력하세요'))
if(count <= 3 or count >= 100):
    print("입력범위에 맞는 수를 입력해주세요")
    exit()
numbers = input().split(' ')

for i in range (0,count):
    adder = 0
    n = int(numbers[i])
    while n > 0 :
        adder +=n %10
        n//=10
    numbers_sum.append(adder)

for i in range(0, count):
    if(numbers_sum[i]>maxnumber):
        maxnumber=numbers_sum[i]

numbers_max = list(filter(lambda x: numbers_sum[x] == maxnumber, range(0,count)))

for i in range(len(numbers_max)):
    numbers_filtered.append(numbers[numbers_max[i]])

print(max(numbers_filtered))
