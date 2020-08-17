# searching for an item in an unordered list
# sometimes called a Linear search

# declare a list of values to operate on
items = [6, 20, 8, 19, 56, 23, 87, 41, 49, 53]

def find_item(item, itemlist):
    for index, n in enumerate(itemlist):
        if n == item:
            return index
    return None


print(find_item(87, items))
print(find_item(250, items))
