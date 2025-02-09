// matth-x/ArduinoOcpp
// Copyright Matthias Akstaller 2019 - 2023
// MIT License

#include <ArduinoOcpp/Operations/Reset.h>
#include <ArduinoOcpp/Model/Model.h>
#include <ArduinoOcpp/Model/Reset/ResetService.h>

using ArduinoOcpp::Ocpp16::Reset;

Reset::Reset(Model& model) : model(model) {
  
}

const char* Reset::getOperationType(){
    return "Reset";
}

void Reset::processReq(JsonObject payload) {
    /*
     * Process the application data here. Note: you have to implement the device reset procedure in your client code. You have to set
     * a onSendConfListener in which you initiate a reset (e.g. calling ESP.reset() )
     */
    bool isHard = !strcmp(payload["type"] | "undefined", "Hard");

    if (auto rService = model.getResetService()) {
        if (!rService->getExecuteReset()) {
            AO_DBG_ERR("No reset handler set. Abort operation");
            (void)0;
            //resetAccepted remains false
        } else {
            if (!rService->getPreReset() || rService->getPreReset()(isHard) || isHard) {
                resetAccepted = true;
                rService->initiateReset(isHard);
                for (unsigned int cId = 0; cId < model.getNumConnectors(); cId++) {
                    model.getConnector(cId)->endTransaction(isHard ? "HardReset" : "SoftReset");
                }
            }
        }
    } else {
        resetAccepted = true; //assume that onReceiveReset is set
    }
}

std::unique_ptr<DynamicJsonDocument> Reset::createConf() {
    auto doc = std::unique_ptr<DynamicJsonDocument>(new DynamicJsonDocument(JSON_OBJECT_SIZE(1)));
    JsonObject payload = doc->to<JsonObject>();
    payload["status"] = resetAccepted ? "Accepted" : "Rejected";
    return doc;
}
