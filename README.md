# Compiler for Deca (java-ish)

This project is a compiler for the deca language written in C++.

### Prerequisites

This compiler generates java bytecode in string format. You will therefore need a compiler
from java bytecode in string format to actual java bytecode.

This compiler can be found at : http://jasmin.sourceforge.net/

Here is an example :
```
java -jar jasmin-2.4/jasmin.jar file_containing_bytecode_in_string_format.j
```

This will produce a java .class file which you should be able to execute using your standard JVM.

### Installing

Clone the repository

```
git clone https://github.com/pougetat/decacompiler.git
```

Build the project

```
mkdir build
cd build
cmake ..
cd src
make
```

Compile a deca program (The executable is in build/src/)

```
./main sample.deca
```

Here is a sample .deca program

```
{
    int a = 3;
    if (a - 1 == 2)
    {
        while (a <= 15)
        {
            print("this is a", a);
            a = a + 1;
        }
        print("yes");
    }
    else {
        print("no");
    }
    print(a);
}
```

Here is another sample deca program with classes:

```
class A {
    B b = new B();
}

class B {
    int b = 13;
    C c = new C();
}

class C {
    int c = 46;
}

{
    A a = new A();
    print(a.b.c.c);
}
```


## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details