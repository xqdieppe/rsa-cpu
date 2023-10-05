import random

def sub(sx, x, sy, y):
    print(sx, sy)
    if (sx == -1 and sy == -1):
        if abs(x) >= abs(y):
            return -1, abs((abs(x) - abs(y)))
        else:
            return 1, abs((abs(y) - abs(x)))

    if (sx == 1 and sy == 1):
        print('------');
        print(x, y);
        print('------');
        if abs(x) >= abs(y):
            return 1, abs(abs(x) - abs(y))
        else:
            return -1, abs(abs(y) - abs(x))
    
    if (sx == 1 and sy == -1):
        return 1, abs(abs(x) + abs(y))
    
    if (sx == -1 and sy == 1):
            return -1, abs(abs(x) + abs(y))

def random_sign():
    if random.random() < 0.5:
        return 1
    else:
        return -1

def rand_var():
    nbr = random.randrange(0, 20)
    return (random_sign(), nbr)

def sub_tester(n):
    i = 0

    while (i < n):
        sx0, x0 = rand_var()
        sy0, y0 = rand_var()
        x = sx0 * x0
        y = sy0 * y0
        ss0, s0 = sub(sx0, x0, sy0, y0)
        s_ = ss0 * s0
        s = x - y
        if ((s == s_) == False):
            print (x, y, s, s_)
        i = i + 1

def egcd_main(sx, x, slx, lastx, quotient):
    qx = quotient*abs(x)
    tmpsx, tmpx = sub(slx, lastx, sx, qx)
    print(tmpsx);
    slx, lastx = sx, abs(x)
    sx, x = tmpsx, abs(tmpx)
    return sx, x, slx, lastx;


def egcd(a, b):
    lastremainder, remainder = abs(a), abs(b)
    x, lastx, y, lasty = 0, 1, 1, 0
    sx, slx, sy, sly = 1, 1, 1, 1

    while remainder:
        savedremainder = remainder
        (quotient, remainder) = divmod(lastremainder, remainder)
        lastremainder = savedremainder
        sx, x, slx, lastx = egcd_main(sx, x, slx, lastx, quotient)
        #print ("-----");
        #print (sx);
        #print (slx);
        #print ("-----");
        sy, y, sly, lasty = egcd_main(sy, y, sly, lasty, quotient)
    return lastremainder, slx * lastx * (-1 if a < 0 else 1), sly * lasty * (-1 if b < 0 else 1)

print (egcd(13, 7))
#sub_tester(20000)
