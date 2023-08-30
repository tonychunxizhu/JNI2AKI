#include "hello.h"
#include <iostream>
#include <string>
#include <aki/jsbind.h>
#include <hilog/log.h>
#include <iostream>
#include <string>
#include <cstdint>
#include <string>
#include <iostream>

void androidJNISayHello(int i) {
    // TODO: implement androidJNISayHello()
    OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_DOMAIN, "RRR", "%{public}d", i);
}

class TestDjinniWrapper : public test::hello::ISayHello
{
public:
    TestDjinniWrapper() = default;

    std::string sayHello(const test::hello::MyRecord &testInfo) {
        auto f = aki::JSBind::GetJSFunction("new TestDjinniWrapper().sayHello");
        auto value = f->Invoke<char *>();
        std::string msg = "name: " + testInfo.name + " project: " + testInfo.project;
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_DOMAIN, "RRR", "%{public}s", value);
        return msg;
    }
};

std::shared_ptr<TestDjinniWrapper::ISayHello> TestDjinniWrapper::ISayHello::NewInstance() {
    return std::make_shared<TestDjinniWrapper>();
}

/*namespace test {
    namespace hello {

    int32_t const VERSION = 1;

    struct MyRecord;

    class ISayHello    {
        public:
            virtual ~ISayHello() {}

            static constexpr int32_t VERSION = 1;

            std::string sayHello(const MyRecord &testInfo);

            static std::shared_ptr<ISayHello> NewInstance();
    };

    enum class Gender : int {
        Man,
        Woman,
    };

    struct MyRecord final {
        int32_t id;
        std::string name;
        std::string project;
        Gender sex;

        MyRecord(int32_t id_, std::string name_, std::string project_, Gender sex_)
            : id(std::move(id_)), name(std::move(name_)), project(std::move(project_)), sex(std::move(sex_)) {}
    };

    }
}

namespace std {

    template <> struct hash<::test::hello::Gender> {
        size_t operator()(::test::hello::Gender type) const { return std::hash<int>()(static_cast<int>(type)); }
    };

}

class TestDjinniWrapper : public test::hello::ISayHello{
    private:
        std::string msg;

    public:
        std::string sayHello(const test::hello::MyRecord &testInfo) {
            msg = "name: " + testInfo.name + "project: " + testInfo.project;
            // msg = "hahahah";
            return msg;
        }
};

std::shared_ptr<TestDjinniWrapper::ISayHello> TestDjinniWrapper::ISayHello::NewInstance() {
    auto f = aki::JSBind::GetJSFunction("ISayHello.newInstance");
    auto value = f->Invoke<std::shared_ptr<TestDjinniWrapper::ISayHello>>();
    OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_DOMAIN, "RRR", "NewInstance");
    return std::make_shared<TestDjinniWrapper>();
}

namespace djinni_generated {

    void nativeDestroy(std::int64_t nativeRef) { OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_DOMAIN, "RRR", "nativeDestroy"); }

    std::string native_sayHello(int64_t nativeRef, test::hello::MyRecord j_testInfo) {
        auto f = aki::JSBind::GetJSFunction("new CppProxy().native_sayHello");
        auto value = f->Invoke<char *>();
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_DOMAIN, "RRR", "sayHello");
        return "sayHello";
    }

    std::shared_ptr<test::hello::ISayHello> newInstance() {
        auto f = aki::JSBind::GetJSFunction("CppProxy.newInstance");
        auto value = f->Invoke<char *>();
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_DOMAIN, "RRR", "newInstance");
        return nullptr;
    }

    JSBIND_GLOBAL() {
        JSBIND_FUNCTION(nativeDestroy);
        JSBIND_FUNCTION(native_sayHello);
        JSBIND_FUNCTION(newInstance);
    }

}*/

JSBIND_CLASS(TestDjinniWrapper) {
    JSBIND_CONSTRUCTOR<>();
    JSBIND_METHOD(sayHello);
}

JSBIND_GLOBAL() {
    JSBIND_FUNCTION(androidJNISayHello);
    JSBIND_FUNCTION(TestDjinniWrapper::ISayHello::NewInstance);
//    JSBIND_FUNCTION(test::hello::ISayHello::sayHello);
}

JSBIND_ADDON(entry)