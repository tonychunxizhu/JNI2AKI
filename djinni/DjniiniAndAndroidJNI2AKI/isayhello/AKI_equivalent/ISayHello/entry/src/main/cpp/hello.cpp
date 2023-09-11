#include <string>
#include <aki/jsbind.h>
#include <hilog/log.h>

void androidJNISayHello(int i) {
    // TODO: implement androidJNISayHello()
    OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_DOMAIN, "RRR", "%{public}d", i);
}

JSBIND_GLOBAL() {
    JSBIND_FUNCTION(androidJNISayHello);
}

JSBIND_ADDON(entry)