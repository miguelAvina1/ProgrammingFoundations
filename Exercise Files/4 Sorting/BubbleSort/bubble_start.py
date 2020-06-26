# Bubble sort algorithm


def bubbleSort(dataset):
    iterations = 0
    # TODO: start with the array length and decrement each time
    upper_limit = len(dataset) - 1
    while(upper_limit != 0):
        for Idx in range(upper_limit):
            iterations += 1
            if dataset[Idx] > dataset[Idx+1]:
                # Swap
                temp = dataset[Idx+1]
                dataset[Idx+1] = dataset[Idx]
                dataset[Idx] = temp
        print("Current state: ", dataset)
        upper_limit -= 1
    return iterations 

    


def main():
    list1 = [50, 40, 35, 30, 25, 20, 15, 10, 5, 1, 25, 20, 15, 10, 5]
    iterations = bubbleSort(list1)
    print("Result: ", list1)
    print(iterations)


if __name__ == "__main__":
    main()
