def egcd(a, b):
    lastremainder, remainder = abs(a), abs(b)
    x, lastx, y, lasty = 0, 1, 1, 0
    signx = 1; signy = 1; signlastx = 1; signlasty = 1;

    while remainder:
        lastremainder, (quotient, remainder) = remainder, divmod(lastremainder, remainder)
       
        tmpx = lastx - quotient*x
        lastx = x
        x = tmpx
        
        tmpy = lasty - quotient*y
        lasty = y
        y = tmpy
    return lastremainder, lastx * (-1 if a < 0 else 1), lasty * (-1 if b < 0 else 1)

print (egcd(12, 7))
