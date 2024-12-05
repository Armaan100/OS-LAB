# Vector
- it is a dynamic array that can grow or shrink in size.
- provides random access to the elements and supports efficient insertion and deletion at the end

## Library: 
- <vector>

## Constructors: 
- vector()
- vector(size)
- vector(size, value)

## Capacity Functions:
- size()    ->  returns the number of elements
- empty()   ->  check if the vector is empty
- reserve(capacity) ->  allocates space for the specified capacity
- capacity()    ->  returns the total allocated mempry
- resize(new_size)  ->  resizes the vector

## Modifiers FUnctions:
- push_back()   ->  adds an element to the end\
- pop_back()    -> removes the last element
- insert(pos, val)  ->  inserts an element at the given pos
- erase(pos)    ->  removes an element from a specfied pos
- clear()   ->  removes all elements
- emplace_back(arg...)  ->  constructs and adds an element at the end

## Access Functions
- at(index) ->  accesses the element at the specified pos(bounds-checked)
- front()   ->  accesses the first element
- back()    ->  accesses the last element
- data()    ->  returns a pointer to the underlying array

