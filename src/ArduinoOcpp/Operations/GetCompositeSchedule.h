// matth-x/ArduinoOcpp
// Copyright Matthias Akstaller 2019 - 2023
// MIT License

#ifndef GETCOMPOSITESCHEDULE_H
#define GETCOMPOSITESCHEDULE_H

#include <ArduinoOcpp/Core/Operation.h>
#include <ArduinoOcpp/Core/Time.h>
#include <ArduinoOcpp/Model/SmartCharging/SmartChargingService.h>

namespace ArduinoOcpp {

class Model;

namespace Ocpp16 {

class GetCompositeSchedule : public Operation {
private:
    Model& model;
    SmartChargingService& scService;
    int connectorId = -1;
    int duration = -1;
    ChargingRateUnitType_Optional chargingRateUnit = ChargingRateUnitType_Optional::None;

    const char *errorCode {nullptr};
public:
    GetCompositeSchedule(Model& model, SmartChargingService& scService);

    const char* getOperationType();

    void processReq(JsonObject payload);

    std::unique_ptr<DynamicJsonDocument> createConf();

    const char *getErrorCode() {return errorCode;}
};

} //end namespace Ocpp16
} //end namespace ArduinoOcpp
#endif
