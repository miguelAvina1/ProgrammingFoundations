# demonstrate hashtable usage

hastTable = {"key1": 1, "Key2":2, "Key3":3}
# TODO: create a hashtable all at once
print(hastTable)

# TODO: create a hashtable progressively
hastTable2 = {k:v*2 for (k,v) in (zip(['Key1', 'Key2'], range(2)))}

print(hastTable2)
# TODO: try to access a nonexistent key


# TODO: replace an item


# TODO: iterate the keys and values in the dictionary
for key, value in hastTable2.items():
    print(f'Key: {key}, Value: {value}')
    print("Hey {}".format(key))
