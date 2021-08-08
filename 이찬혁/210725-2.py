splitList = []
creator = []
number = int(input("숫자를 입력하세요"))

if(number < 1 or number > 1000000):
    print("범위에 맞는 수를 입력하세요")
    exit()

for i in range(0, number):
    splitList.append(number-i)

for i in range(0, number):
    subtract = number - splitList[i]
    adder = 0
    spliter = list(map(int,str(subtract)))
    for i in range(0, len(spliter)):
        adder += spliter[i]

    if(subtract+adder == number):
        creator.append(subtract)

for i in range(len(creator)):
    print(creator[i])

if(len(creator)==0):
    print("0")