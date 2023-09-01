//
// Created by Ruturaj on 2023-09-01.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include <string>
#include <aki/jsbind.h>
#include <string>
#include "header/Gender.h"
#include "header/ISayHello.h"
#include "header/MyRecord.h"

class TestDjinniWrapper : public test::hello::ISayHello
{
public:
    TestDjinniWrapper() = default;

    std::string sayHello(const test::hello::MyRecord &testInfo) {
        std::string msg = "name: " + testInfo.name + " project: " + testInfo.project;
        return msg;
    }
};

std::shared_ptr<TestDjinniWrapper::ISayHello> TestDjinniWrapper::ISayHello::NewInstance() {
    return std::make_shared<TestDjinniWrapper>();
}

JSBIND_CLASS(TestDjinniWrapper) {
    JSBIND_CONSTRUCTOR<>();
    JSBIND_METHOD(sayHello);
}

JSBIND_GLOBAL() { JSBIND_FUNCTION(TestDjinniWrapper::ISayHello::NewInstance); }

JSBIND_ADDON(entry2)