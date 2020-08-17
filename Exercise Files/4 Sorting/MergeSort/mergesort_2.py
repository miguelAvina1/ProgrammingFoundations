


def merge_sort(in_numbers):     
    if len(in_numbers) > 1:
        
        left_part = in_numbers[:len(in_numbers)//2]
        right_part = in_numbers[len(in_numbers)//2:]

        merge_sort(left_part)
        merge_sort(right_part)

        i = 0 #index for left
        j = 0 #index for right
        k = 0 #index for in_numbers

        while(i < len(left_part) and j < len(right_part)):
            if (left_part[i] < right_part[j]):
                in_numbers[k] = left_part[i]
                i += 1
            else:
                in_numbers[k] = right_part[j]
                j += 1
            k += 1

        if (i < len(left_part)):
            in_numbers[k:] = left_part[i:]
        elif (j < len(right_part)):
            in_numbers[k:] = right_part[j:]








if __name__ == '__main__':
    ls = [3,5,7,85,3,2,45,8]
    print(ls)


    merge_sort(ls)
    print(ls)

