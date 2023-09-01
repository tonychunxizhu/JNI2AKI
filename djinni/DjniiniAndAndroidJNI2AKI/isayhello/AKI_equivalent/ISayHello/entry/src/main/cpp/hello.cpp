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

JSBIND_GLOBAL() {
    JSBIND_FUNCTION(androidJNISayHello);
}

JSBIND_ADDON(entry)