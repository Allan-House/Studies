books = ["Notes from a Dead House", "Crime and Punishment", "The Idiot"]
print(f"books            : {books}")

# ================================= Accessing =================================
print(f"books[0]         : {books[0]}")
print(f"books[2]         : {books[2]}")

# ================================= Adding =================================

# append(value) adds an item to the end of the list.
books.append("The Demons")
books.append("The Brothers Karamazov")
print("after append ×2  :", books)

# insert(index, value) insert an item at a given position.
books.insert(1, "Notes from Underground")
books.insert(4, "The Adolescent")
print("after insert ×2  :", books)

# ================================= Removing =================================

# pop(index) removes the item at given position in the list, and returns it.
last = books.pop()
print(f"pop()   returned : {last!r}")

second = books.pop(1)
print(f"pop(1)  returned : {second!r}")

print("after pop ×2     :", books)

# del statement removes an item by position
del books[2]
print("after del [2]    :", books)

# remove(val) removes the first item from the list whose value is equal to val.
books.remove("The Adolescent")
print("after remove()   :", books)

# clear() remove all items from the list
books.clear()
print("after clear()    :", books)

# ================================= Sorting =================================
print("Reseting list...")
books = [
    "Notes from a Dead House",
    "Notes from Underground",
    "Crime and Punishment",
    "The Idiot",
    "The Brothers Karamazov"
]
print(f"books            : {books}")

# sort() → None  |  sorts in place, alphabetical by default
books.sort()
print("after sort()     :", books)

# reverse() → None  |  reverses in place
books.reverse()
print("after reverse()  :", books)
