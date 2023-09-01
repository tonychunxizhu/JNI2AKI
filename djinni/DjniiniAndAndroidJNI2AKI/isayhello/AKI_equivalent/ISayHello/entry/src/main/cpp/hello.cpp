#include <string>
#include <aki/jsbind.h>
#include <hilog/log.h>
#include <string>
#include "header/Gender.h"
#include "header/ISayHello.h"
#include "header/MyRecord.h"

void androidJNISayHello(int i) {
    // TODO: implement androidJNISayHello()
    OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_DOMAIN, "RRR", "%{public}d", i);
}

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

JSBIND_GLOBAL() {
    JSBIND_FUNCTION(androidJNISayHello);
    JSBIND_FUNCTION(TestDjinniWrapper::ISayHello::NewInstance);
}

JSBIND_ADDON(entry)