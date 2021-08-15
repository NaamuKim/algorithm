if __name__ == '__main__':
    stack = []
    counts = int(input())
    for i in range(counts):
        answer = input()
        try:
            if answer == 0:
                stack.pop()
            else:
                stack.append(answer)
        except Exception:
            pass
    print(sum(stack))