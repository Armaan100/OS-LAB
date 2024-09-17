# FRIEND CLASS

- A class can also be made a friend of another class

- Suppose class A and class B

- class B{
    ...
    ...
    friend class A;
}

- All the member of a friend class A become friend of class B


- Any member function of class A can access the private data of class B


- But, member functions of class B cannot access the private data of class A
