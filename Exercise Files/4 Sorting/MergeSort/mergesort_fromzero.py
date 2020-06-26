import csv

def merge_sort(ls):
    if len(ls) > 1:
        middle = len(ls)//2
        left_part = ls[:middle]
        right_part = ls[middle:]

        merge_sort(left_part)
        merge_sort(right_part)

        #ls = list([0 for _ in range(len(ls))])
        #ls = []
        j = 0
        i = 0
        k = 0
        while i < len(left_part) and j < len(right_part):
            if left_part[i] <= right_part[j]:
                #ls.append(left_part[i]) # bad
                ls[k] = left_part[i]
                i += 1
            else:
                #ls.append(right_part[j])
                ls[k] = right_part[j]
                j += 1
            k += 1
        #print(ls)

        if i < len(left_part):
            ls[k:] = left_part[i:]
        else:
            ls[k:] = right_part[j:]
            
    


if __name__ == "__main__":
    print('Hello World')
    import_list = list()
    with open('Random_list.csv', newline='') as myfile:
        z = csv.reader(myfile)
        for row in z:
            import_list.extend([int(element) for element in row[0].split()])

    print(import_list)
    merge_sort(import_list)
    print(import_list)
