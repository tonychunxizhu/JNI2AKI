//
// Created by zhoumohan on 2021/12/3.
//
#include <string.h>
#include "header/test_djnni_interface.h"
#include "header/test_info_store.h"

class TestDjinniWrapper : public test::hello::TestDjnniInterface
{
private:
	std::string msg;
public:
	std::string Show(const test::hello::TestInfoStore & testInfo){
		msg = "name: "+testInfo.name+"project: "+testInfo.project;
        //msg = "hahahah";
		return msg;
	}
};


std::shared_ptr<TestDjinniWrapper::TestDjnniInterface> TestDjinniWrapper::TestDjnniInterface::NewInstance()
{
  return std::make_shared<TestDjinniWrapper>();
}