#include <string>

namespace NativeLibrary {
    class NativeClass {
        public:
            const std::string& get_property() { return property; }
            void set_property(const std::string& property) { this->property = property; }
            std::string property;

        const std::string& get_value() { return value; }
        void set_value(const std::string& value) { this->value = value; }
        std::string value;

        int year;
        int get_year() { return year; }
        void set_year(int year) { this->year = year; }
        int add(int a, int b){return a+b;}

    };


    class Foo {
    public:
        int n;
        Foo(int n) : n(n) { }
        virtual ~Foo() { }
        virtual int bar(int a, int b) {
            printf("Callback in C++ a = %d, b = %d)\n", a,b);
            return a+b;
        }
    };

    int callback(Foo *foo, int a, int b) {
        return foo->bar(a,b);
    }
}
