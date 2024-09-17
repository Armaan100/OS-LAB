# Passing Arguments To Base Class Constructor

- derived-constructor(arg-list): base1(arg-list), base2(arg-list), ..., baseN(arg-list)
  {
    //body of the derived constructor
  }


  # Order of Constructor Call

  - Base Class Constructors are always called in the derived class

  - Whenever we create derived class object, 
    first the base class default constuctor is executed and then the derived class's constructor finishes execution