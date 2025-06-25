//yoav1.nach@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "MyContainer.cpp"
#include <sstream>
using namespace Container;

//tseting creation of MyContainer
TEST_CASE("create MyContainer")
{
    MyContainer<int>* cont = new MyContainer<int>();
    CHECK(cont!=NULL);
    delete cont;
}


//testing adding element to container
TEST_CASE("add element")
{
    MyContainer<int> cont;

    cont.addElement(1);

    std::ostringstream os;

    os<<cont;

    CHECK(os.str()=="[1]");

}

//testing removing element to container
TEST_CASE("remove element")
{
    MyContainer<int> cont;

    cont.addElement(1);

    std::ostringstream os;

    os<<cont;

    CHECK(os.str()=="[1]");

    cont.removeElement(1);

    os = std::ostringstream();

    os<<cont;

    CHECK(os.str()=="[]");

}

//testing size of container
TEST_CASE("container size")
{
    MyContainer<int> cont;

    int size = cont.size();

    CHECK(size==0);

    cont.addElement(1);

    size = cont.size();

    CHECK(size==1);

    cont.removeElement(1);

    size = cont.size();

    CHECK(size==0);
}

//testing operator <<
TEST_CASE("operator <<")
{
    MyContainer<int> cont;

    std::ostringstream os;

    os<<cont;

    CHECK(os.str()=="[]");

    cont.addElement(1);

    os=std::ostringstream();

    os<<cont;

    CHECK(os.str()=="[1]");

    cont.addElement(2);

    os=std::ostringstream();

    os<<cont;

    CHECK(os.str()=="[1, 2]");
}
//testing ascending order iterator
TEST_CASE("ascending order iterator")
{
    MyContainer<int> container;
    container.addElement(7);
    container.addElement(15);
    container.addElement(6);
    container.addElement(1);
    container.addElement(2);

    std::ostringstream os;

    for(auto it = container.begin_ascending_order();it!=container.end_ascending_order();++it)
    {
        os << *it << ' ';
    }

    CHECK(os.str()=="1 2 6 7 15 ");
}

//testing desending order iterator
TEST_CASE("desending order iterator")
{
    MyContainer<int> container;
    container.addElement(7);
    container.addElement(15);
    container.addElement(6);
    container.addElement(1);
    container.addElement(2);

    std::ostringstream os;

    for(auto it = container.begin_descending_order();it!=container.end_descending_order();++it)
    {
        os << *it << ' ';
    }

    CHECK(os.str()=="15 7 6 2 1 ");
}

//testing side cross order iterator
TEST_CASE("side cross order iterator")
{
    MyContainer<int> container;
    container.addElement(7);
    container.addElement(15);
    container.addElement(6);
    container.addElement(1);
    container.addElement(2);

    std::ostringstream os;

    for(auto it = container.begin_side_cross_order();it!=container.end_side_cross_order();++it)
    {
        os << *it << ' ';
    }

    CHECK(os.str()=="1 15 2 7 6 ");
}

//testing reverse order iterator
TEST_CASE("reverse order iterator")
{
    MyContainer<int> container;
    container.addElement(7);
    container.addElement(15);
    container.addElement(6);
    container.addElement(1);
    container.addElement(2);

    std::ostringstream os;

    for(auto it = container.begin_reverse_order();it!=container.end_reverse_order();++it)
    {
        os << *it << ' ';
    }

    CHECK(os.str()=="2 1 6 15 7 ");
}

//testing order iterator
TEST_CASE("order iterator")
{
    MyContainer<int> container;
    container.addElement(7);
    container.addElement(15);
    container.addElement(6);
    container.addElement(1);
    container.addElement(2);

    std::ostringstream os;

    for(auto it = container.begin_order();it!=container.end_order();++it)
    {
        os << *it << ' ';
    }

    CHECK(os.str()=="7 15 6 1 2 ");
}

//testing middle out order iterator
TEST_CASE("middle out order iterator")
{
    MyContainer<int> container;
    container.addElement(7);
    container.addElement(15);
    container.addElement(6);
    container.addElement(1);
    container.addElement(2);

    std::ostringstream os;

    for(auto it = container.begin_middle_out_order();it!=container.end_middle_out_order();++it)
    {
        os << *it << ' ';
    }

    CHECK(os.str()=="6 15 1 7 2 ");
}

