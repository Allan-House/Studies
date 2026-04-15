capitals = {
    'Argentina' : 'Buenos Aires',
    'Germany' : 'Berlin',
    'Iceland' : 'Reykjavik',
}
print(f"capitals                 : {capitals}")

# ================================= Accessing =================================
print(f"capitals['Germany']      : {capitals['Germany']}")

# get(key) returns the value for key in the dictionary
print(f"capitals.get('Iceland')  : {capitals.get('Iceland')}")

# =================================== Adding ===================================
capitals['Japan'] = 'Tokyo'
capitals['Russia'] = 'Moscow'

# ================================= Iterating =================================
print()
# items() returns a view object of the dictionary’s (key, value) pairs
print("Iterating over capitals using items() — each (country, capital) pair:")
print() # TODO: printing about the loop // items() use
for country, city in capitals.items():
    print(f"{country} - {city}")
print()
# keys() returns a view object of the dictionary’s keys.
# for country in capitals.keys():
#     print(f"{country}")

# values() returns a view object of the dictionary’s values.
# for capital in capitals.values():
    # print(f"{capital}")

# ================================== Removing ==================================

# pop(key, default=None): removes the item with the specified key and returns its value
ret = capitals.pop('Iceland')
print(f"pop('Iceland')  returned : {ret}")

# popitem(): removes and returns the last inserted (key, value) pair.
ret = capitals.popitem()
print(f"popitem()  returned      : {ret}")

print("after pop x2             : ", capitals)

# clear(): removes all (key, value) pairs from the dictionary.
capitals.clear()
print("after clear()            :", capitals)