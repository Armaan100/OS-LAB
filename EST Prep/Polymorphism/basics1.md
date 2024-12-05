- Same name function do different classes mein present hein toh usko overoading nhi bola jata, therefore static binding not apply
- In such situations, we may use the class resolution operator to specify the class while invoking the functions witht the derived class objects

- How to select the appropriate function while running -> called runtime polymorphism.
- cpp supports mechanism known as virtual function to achieve run time polymorphism

- since the function is linked with a particular class much later after the compilation, this process is termed as late binding. Also known as Dynamic Binding cuz the selection of the appropriate function is fone dynamically at the run time -> requires use of pointer to objects



int (*fn)();