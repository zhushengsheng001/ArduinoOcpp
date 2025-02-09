// matth-x/ArduinoOcpp
// Copyright Matthias Akstaller 2019 - 2023
// MIT License

#include <ArduinoOcpp/Operations/Authorize.h>
#include <ArduinoOcpp/Model/Model.h>
#include <ArduinoOcpp/Model/Authorization/AuthorizationService.h>

#include <ArduinoOcpp/Debug.h>

using ArduinoOcpp::Ocpp16::Authorize;

Authorize::Authorize(Model& model, const char *idTagIn) : model(model) {
    if (idTagIn && strnlen(idTagIn, IDTAG_LEN_MAX + 2) <= IDTAG_LEN_MAX) {
        snprintf(idTag, IDTAG_LEN_MAX + 1, "%s", idTagIn);
    } else {
        AO_DBG_WARN("Format violation of idTag. Discard idTag");
        (void)0;
    }
}

const char* Authorize::getOperationType(){
    return "Authorize";
}

std::unique_ptr<DynamicJsonDocument> Authorize::createReq() {
    auto doc = std::unique_ptr<DynamicJsonDocument>(new DynamicJsonDocument(JSON_OBJECT_SIZE(1) + (IDTAG_LEN_MAX + 1)));
    JsonObject payload = doc->to<JsonObject>();
    payload["idTag"] = idTag;
    return doc;
}

void Authorize::processConf(JsonObject payload){
    const char *idTagInfo = payload["idTagInfo"]["status"] | "not specified";

    if (!strcmp(idTagInfo, "Accepted")) {
        AO_DBG_INFO("Request has been accepted");
    } else {
        AO_DBG_INFO("Request has been denied. Reason: %s", idTagInfo);
    }

    if (model.getAuthorizationService()) {
        model.getAuthorizationService()->notifyAuthorization(idTag, payload["idTagInfo"]);
    }
}

void Authorize::processReq(JsonObject payload){
    /*
     * Ignore Contents of this Req-message, because this is for debug purposes only
     */
}

std::unique_ptr<DynamicJsonDocument> Authorize::createConf(){
    auto doc = std::unique_ptr<DynamicJsonDocument>(new DynamicJsonDocument(2 * JSON_OBJECT_SIZE(1)));
    JsonObject payload = doc->to<JsonObject>();
    JsonObject idTagInfo = payload.createNestedObject("idTagInfo");
    idTagInfo["status"] = "Accepted";
    return doc;
}
