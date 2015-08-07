#include <cstdlib>
#include <iostream>
#include <string>

#include "Foo.hpp"
#include "ForId1D.hpp"
#include "TypeLists.hpp"

int main()
{
    int id1 = 0;
    int id2 = 1;
    int id3 = 2;
    std::string name = "Raboof";
    FooInput input(id1, id2, id3, name);

    buildFoo1 builder1;
    std::cout << "Instantiate Foo1 with integer data type" << std::endl;
    IFoo * foo1_integer = for_id<first_list, IFoo>(builder1, input, input.id1);
    foo1_integer->printData();
    foo1_integer->printMoreData();
    foo1_integer->printEvenMoreData();
    delete foo1_integer;

    std::cout << "Instantiate Foo1 with float data type" << std::endl;
    IFoo * foo1_float = for_id<first_list, IFoo>(builder1, input, input.id2);
    foo1_float->printData();
    foo1_float->printMoreData();
    foo1_float->printEvenMoreData();
    delete foo1_float;

    std::cout << "Instantiate Foo1 with double data type" << std::endl;
    IFoo * foo1_double = for_id<first_list, IFoo>(builder1, input, input.id3);
    foo1_double->printData();
    foo1_double->printMoreData();
    foo1_double->printEvenMoreData();
    delete foo1_double;

    return EXIT_SUCCESS;
}
