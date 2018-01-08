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
	int a;
	int b = 34;
	while (b <= 54)
	{
		print(b);
		b = b+1;
	}
}
```


## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details