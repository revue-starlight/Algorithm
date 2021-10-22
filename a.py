import random


T = 7
print(T)

for _ in range(T):
    n = 10 ** 5
    print(n)

    print(' '.join( map(str, [ random.randint(10, 17) for _ in range(n) ]) ))