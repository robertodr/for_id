#ifndef FOO_HPP
#define FOO_HPP

#include <cmath>
#include <iomanip>



class IFoo
{
    public:
        IFoo() : name_(""), built_(true) {}
        IFoo(const std::string & n) : name_(n), built_(true) {}
        virtual ~IFoo() {}
        virtual void printData() const = 0;
        virtual void printMoreData() const = 0;
        virtual void printEvenMoreData() const = 0;
    protected:
        std::string name_;
        bool built_;
};

struct FooInput
{
    int id1;
    int id2;
    int id3;
    std::string name;
    FooInput(int a, int b, int c, const std::string & n) : id1(a), id2(b), id3(c), name(n) {}
};

template <typename T>
class Foo1 : public IFoo
{
    public:
        Foo1() : IFoo(), data_((T)M_PI) {}
        Foo1(const std::string & n) : IFoo(n), data_((T)M_PI) {}
        virtual ~Foo1() {}
        virtual void printData() const { std::cout << this->name_ << "\n" << std::setprecision(16) << this->data_ << std::endl; }
        virtual void printMoreData() const { std::cout << this->name_ << "\n" << "No such thing as moreData_ here..." << std::endl; }
        virtual void printEvenMoreData() const { std::cout << this->name_ << "\n" << "No such thing as evenMoreData_ here..." << std::endl; }
    private:
        T data_;
};

struct buildFoo1
{
    template <typename T>
    IFoo * operator()(const FooInput & data) {
        return new Foo1<T>(data.name);
    }
};

template <typename T, typename U>
class Foo2 : public IFoo
{
    public:
        Foo2() : IFoo(), data_((T)M_PI), moreData_((U)2.0 * M_PI) {}
        Foo2(const std::string & n) : IFoo(n), data_((T)M_PI), moreData_((U)2.0 * M_PI) {}
        virtual ~Foo2() {}
        virtual void printData() const { std::cout << this->name_ << "\n" << std::setprecision(16) << this->data_ << std::endl; }
        virtual void printMoreData() const { std::cout << this->name_ << "\n" << std::setprecision(16) << this->moreData_ << std::endl; }
        virtual void printEvenMoreData() const { std::cout << this->name_ << "\n" << "No such thing as evenMoreData_ here..." << std::endl; }
    private:
        T data_;
        U moreData_;
};

struct buildFoo2
{
    template <typename T, typename U>
    IFoo * operator()(const FooInput & data) {
        return new Foo2<T, U>(data.name);
    }
};

template <typename T, typename U, typename V>
class Foo3 : public IFoo
{
    public:
        Foo3() : IFoo(), data_((T)M_PI), moreData_((U)2.0 * M_PI), evenMoreData_((V)3.0 * M_PI) {}
        Foo3(const std::string & n) : IFoo(n), data_((T)M_PI), moreData_((U)2.0 * M_PI), evenMoreData_((V)3.0 * M_PI) {}
        virtual ~Foo3() {}
        virtual void printData() const { std::cout << this->name_ << "\n" << std::setprecision(16) << this->data_ << std::endl; }
        virtual void printMoreData() const { std::cout << this->name_ << "\n" << std::setprecision(16) << this->moreData_ << std::endl; }
        virtual void printEvenMoreData() const { std::cout << this->name_ << "\n" << std::setprecision(16) << this->evenMoreData_ << std::endl; }
    private:
        T data_;
        U moreData_;
        V evenMoreData_;
};

struct buildFoo3
{
    template <typename T, typename U, typename V>
    IFoo * operator()(const FooInput & data) {
        return new Foo3<T, U, V>(data.name);
    }
};

#endif // FOO_HPP
