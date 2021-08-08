student1 = [1,2,3,4,5]
student2 = [2,1,2,3,2,4,2,5]
student3 = [3,3,1,1,2,2,4,4,5,5]

def checker(answer):
    a1,a2,a3 = 0,0,0
    for i in range(len(answer)):
        s1 = i % len(student1)
        s2 = i % len(student2)
        s3 = i % len(student3)
        if int(answer[i]) == int(student1[s1]):
            a1 += 1
        if int(answer[i]) == int(student2[s2]):
            a2 += 1
        if int(answer[i]) == int(student3[s3]):
            a3 += 1

    print(a1, a2, a3)

if __name__ == '__main__':
    answer = input().split(' ')
    checker(answer)
