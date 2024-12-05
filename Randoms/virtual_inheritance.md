# Virtual Inheritance

- When you declare a class to inherit from another class virtually (as in virtual B2), the construction and initialization of that base class (B2) are handled differently compared to regular inheritance.

- In the case of virtual inheritance, the virtual base class is always constructed first, regardless of the order of inheritance in the derived class. This ensures that the virtual base class is constructed only once, even if multiple derived classes indirectly inherit from it.

- Virtual inheritance in C++ is a feature used to solve the diamond problem (or ambiguity problem) that occurs in multiple inheritance. Virtual inheritance ensures that when multiple classes inherit from the same base class, only one instance of the base class is created, preventing duplication and ambiguity.


- Avoids Ambiguity: It prevents multiple copies of the base class when using multiple inheritance, solving the diamond problem.


- One Instance of Base Class: Only one instance of the virtual base class exists, even if multiple derived classes inherit from it.


- Order of Constructor Calls: Virtual base classes are constructed before non-virtual base classes, ensuring that the virtual base class is initialized only once.