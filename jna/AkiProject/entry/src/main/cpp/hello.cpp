#include <iostream>
#include <string>
#include <aki/jsbind.h>
#include <hilog/log.h>

struct MyStructure {
    int a;
    int b;
};

//    strcpy(str, newName);
//    str = newName;
//    aki::ArrayBuffer newName(str.GetData(), str.GetCount());
//    uint8_t* data = newName.GetData();
//    data[0] = 'a';
//    data[1] = 'a';
//    data[2] = 'a';
char* changeName2() {
    char* newName = new char[4];
    strcpy(newName, "aaa");
    return newName;
}

void changeNum(aki::ArrayBuffer num) {
    uint8_t *temp = num.GetData();
    temp[0] += 10;
}
//    aki::ArrayBuffer newNum(num.GetData(), num.GetCount());
//    uint8_t *temp = newNum.GetData();

int calculateArea(int length, int width) { return length * width; }
int calculatePerimeter(int length, int width) { return 2 * (length + width); }



void show() { 
    auto f = aki::JSBind::GetJSFunction("AddNumber.show");
    auto newName = f->Invoke<char *>("pm", 4);
    OH_LOG_Print(LOG_APP, LOG_DEBUG, LOG_DOMAIN, "testTag", "Test current time: %{public}s", newName);
}

void addN() {
    auto f = aki::JSBind::GetJSFunction("AddNumber.add");
    auto i = f->Invoke<int>(2, 3);
    OH_LOG_Print(LOG_APP, LOG_DEBUG, LOG_DOMAIN, "testTag", "Test add number: %{public}d", i);
}

double changeDouble() { return 60.00; }

int add1(int a, int b) { return a + b; }

void changeName() {
    const char *newName = "aaa";
    auto f = aki::JSBind::GetJSFunction("set");
    f->Invoke<void>(newName);
}

MyStructure MakeMyStructure(int a, int b) {
    MyStructure myStructure = {a, b};
    return myStructure;
}

int add(MyStructure *s) { return s->a + s->b; }

JSBIND_GLOBAL() {
    JSBIND_FUNCTION(changeName);
    JSBIND_FUNCTION(changeName2);
    JSBIND_FUNCTION(changeNum);
    JSBIND_FUNCTION(changeDouble);
    JSBIND_FUNCTION(add1);
    JSBIND_FUNCTION(addN);
    JSBIND_FUNCTION(show);
    JSBIND_FUNCTION(calculateArea);
    JSBIND_FUNCTION(calculatePerimeter);
    JSBIND_FUNCTION(add);
    JSBIND_FUNCTION(MakeMyStructure);
}

JSBIND_ADDON(entry)

JSBIND_CLASS(MyStructure) {
    JSBIND_CONSTRUCTOR<>();
    JSBIND_PROPERTY(a);
    JSBIND_PROPERTY(b);
}




