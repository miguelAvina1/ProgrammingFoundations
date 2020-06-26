# use recursion to implement a countdown counter

level = 0

def countdown(x, level):
    level += 1
    if x < 0:
        print("Done")
        return
    else:
        print(x)
        countdown(x-1, level)
        print(f"Current level:{level}")


countdown(5, level)
