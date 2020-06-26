from random import randint 
from random import seed
import csv


def bubble_sort(ls):
    iterations = 0
    length = len(ls)
    for _ in range(len(ls)):
        for i in range(1, length):
            iterations += 1
            if ls[i-1] > ls[i]:
                temp = ls[i-1]
                ls[i-1] = ls[i]
                ls[i] = temp
        length -= 1
    return iterations



if __name__ == "__main__":
    print("Bubble Sort Algorithm")
    seed(1)                 
    random_list = [randint(0, 100) for _ in range(15)]
    with open('Random_list.csv', 'w', newline='') as csvfile:
        writer = csv.writer(csvfile, delimiter = ' ')
        writer.writerow(random_list)

    print(random_list)


iterations = bubble_sort(random_list)

print(random_list)
print(iterations)