# Implement a merge sort with recursion
import csv

items = [6, 20, 8, 19, 56, 23, 87, 41, 49, 53]

def mergesort(dataset):
    if len(dataset) > 1:
        mid = len(dataset) // 2
        leftarr = dataset[:mid]
        rightarr = dataset[mid:]

        # TODO: recursively break down the arrays
        mergesort(leftarr)  # This makes algorithm go down until everything is splitted
        mergesort(rightarr) 

        # TODO: now perform the merging
        i=0 # index into the left array
        j=0 # index into the right array
        k=0 # index into merged array
        #mergedArray = []

        # TODO: while both arrays have content
        while i < len(leftarr) and j < len(rightarr):
            if leftarr[i] > rightarr[j]:
                dataset[k] = rightarr[j]
                j += 1
            else:
                dataset[k] = leftarr[i]
                i += 1
            k += 1

        # Altough we could use pop, recall it have to reoganize the memory: O(n)
        # Accessing directly just uses O(1)


        # TODO: if the left array still has values, add them
        if i < len(leftarr):
            dataset[k:] = leftarr[i:]
        elif j < len(rightarr):
            dataset[k:] = rightarr[j:]
        # TODO: if the right array still has values, add them
   # else:
        #return dataset


test1 = [1,2,3,4,5]
test2 = test1[2:]
test3 = test1
test1[-1] = 7
print(test1)
print(test2)
print(test3)


if __name__ == "__main__":
    print('Hello World')
    import_list = list()
    with open('Random_list.csv', newline='') as myfile:
        z = csv.reader(myfile)
        for row in z:
            import_list.extend([int(element) for element in row[0].split()])
            
    
# test the merge sort with data
#print(import_list)
#mergesort(import_list)
#print(import_list)
