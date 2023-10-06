import random

def move(size):
    print (size)
    s = size / 32
    return (random.randrange(0, s)) * 32

def random_primes_size(keysize):
    m = move(keysize / 4)
    first = keysize / 2 + m
    second = keysize / 2 - m
    return (first, second)

print (random_primes_size(2048))
    
