# Find the greatest common denominator of two numbers
# using Euclid's algorithm


def gcd(a, b):
    a1 = max(a, b)
    b1 = min(a, b)
    reminder = a1 % b1
    while(reminder):
        a1 = b1
        b1 = reminder
        reminder = a1 % b1
    return b1
    

        
# try out the function with a few examples
print(gcd(60, 96))  # should be 12
print(gcd(20, 8))   # should be 4
