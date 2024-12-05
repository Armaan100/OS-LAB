# Iterators
- provide a way to access elements in containers. They behave like pointers, allowing
traversal of container elements. Iterators can be used with containers to make code generic
and flexible.

- In C++, an iterator is an object that points to an element within a container. Think of an iterator
as a pointer that “points” to the location of an element but doesn’t directly hold the element's
value. Therefore, to access the actual value stored at the iterator’s position, you need to
dereference the iterator.

## Types of iterators
- Input Iterator: Can read data sequentially.
- Output Iterator: Can write data sequentially.
- Forward Iterator: Can read or write in a single direction.
- Bidirectional Iterator: Can move both forward and backward.
- Random Access Iterator: Can jump to any element in constant time.