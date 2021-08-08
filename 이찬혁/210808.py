def finder(array, cont):
    max = int(0)
    sum = int(0)
    for i in range(len(array)-int(cont)+1):
        for z in range(int(cont)):
            sum+=int(array[i+z])
            if (sum > max):
                max = sum
        sum = int(0)
    return max

if __name__ == '__main__':
    count, cont = input().split(' ')
    data = input().split(' ')
    if(len(data)!=int(count)):
        print('길이가 맞지 않습니다')
        exit()
    print(finder(data, cont))

