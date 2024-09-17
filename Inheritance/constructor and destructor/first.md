# Constructors and Destructors in Base & Derived Class

- Derived classes can have their own Constructors & Destructors

- When an object of a derived class is created -> 
  the base class's constructor is executed first,
  followed by the derived class's constructor

- When an object of a derived class is destroyed ->
  its destructor is called first,
  then that of the base class