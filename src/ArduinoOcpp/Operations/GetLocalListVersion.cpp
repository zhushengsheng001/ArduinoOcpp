// matth-x/ArduinoOcpp
// Copyright Matthias Akstaller 2019 - 2023
// MIT License

#include <ArduinoOcpp/Operations/GetLocalListVersion.h>
#include <ArduinoOcpp/Model/Model.h>
#include <ArduinoOcpp/Model/Authorization/AuthorizationService.h>
#include <ArduinoOcpp/Debug.h>

using ArduinoOcpp::Ocpp16::GetLocalListVersion;

GetLocalListVersion::GetLocalListVersion(Model& model) : model(model) {
  
}

const char* GetLocalListVersion::getOperationType(){
    return "GetLocalListVersion";
}

void GetLocalListVersion::processReq(JsonObject payload) {
    //empty payload
}

std::unique_ptr<DynamicJsonDocument> GetLocalListVersion::createConf(){
    auto doc = std::unique_ptr<DynamicJsonDocument>(new DynamicJsonDocument(JSON_OBJECT_SIZE(1)));
    JsonObject payload = doc->to<JsonObject>();
    if (auto authService = model.getAuthorizationService()) {
        payload["listVersion"] = authService->getLocalListVersion();
    } else {
        payload["listVersion"] = -1;
    }
    return doc;
}
