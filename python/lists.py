nums = [10, 20, 30]
print(f"nums             : {nums}")

# ===== Accessing ==============================================================
print(f"nums[0]          : {nums[0]}")
print(f"nums[2]          : {nums[2]}")

# ===== Adding =================================================================

# append(value) adds an item to the end of the list.
nums.append(40)
nums.append(50)
print("after append ×2  :", nums)

# insert(index, value) insert an item at a given position.
nums.insert(1, 15)
nums.insert(4, 35)
print("after insert ×2  :", nums)

# ===== Removing ===============================================================

# pop(index) removes the item at given position in the list, and returns it.
last = nums.pop()
print(f"pop()   returned : {last}")

second = nums.pop(1)
print(f"pop(1)  returned : {second}")

print("after pop ×2     :", nums)

# del statement removes an item by position
del nums[2]
print("after del [2]    :", nums)

# remove(val) removes the first item from the list whose value is equal to val.
nums.remove(35)
print("after remove()   :", nums)

# clear() remove all items from the list
nums.clear()
print("after clear()    :", nums)
