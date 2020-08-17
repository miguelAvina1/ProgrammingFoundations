# searching for an item in an ordered list
# this technique uses a binary search


items = [6, 8, 19, 20, 23, 41, 49, 53, 56, 87]

def binarysearch(item, itemlist):
    # get the list size
    listsize = len(itemlist) - 1
    # start at the two ends of the list
    lowerIdx = 0
    upperIdx = listsize

    while lowerIdx <= upperIdx:
        
        # TODO: calculate the middle point
        middlePointIdx = (upperIdx + lowerIdx)//2

        # TODO: if item is found, return the index
        if itemlist[middlePointIdx] == item:
            return middlePointIdx
        else:
            if (itemlist[middlePointIdx] > item):  # esta a la mitad izquierda
                upperIdx = middlePointIdx - 1
            else:                                   # esta a la mitad derecha
                lowerIdx = middlePointIdx + 1
        # TODO: otherwise get the next midpoint


    if lowerIdx > upperIdx:
        return None


print(binarysearch(23, items))
print(binarysearch(87, items))
print(binarysearch(250, items))
