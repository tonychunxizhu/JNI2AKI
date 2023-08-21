//
// Created by zhoumohan on 2021/12/3.
//
#include <cstring>
#include "header/ISayHello.h"
#include "header/MyRecord.h"

class TestDjinniWrapper : public test::hello::ISayHello {
private:
    std::string msg;
public:
    std::string sayHello(const test::hello::MyRecord &testInfo) {
        msg = "name: " + testInfo.name + "project: " + testInfo.project;
        //msg = "hahahah";
        return msg;
    }
};


std::shared_ptr<TestDjinniWrapper::ISayHello> TestDjinniWrapper::ISayHello::NewInstance() {
    return std::make_shared<TestDjinniWrapper>();
}