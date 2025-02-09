// matth-x/ArduinoOcpp
// Copyright Matthias Akstaller 2019 - 2023
// MIT License

#ifndef HEARTBEAT_H
#define HEARTBEAT_H

#include <ArduinoOcpp/Core/Operation.h>

namespace ArduinoOcpp {

class Model;

namespace Ocpp16 {

class Heartbeat : public Operation {
private:
    Model& model;
public:
    Heartbeat(Model& model);

    const char* getOperationType();

    std::unique_ptr<DynamicJsonDocument> createReq();

    void processConf(JsonObject payload);

    void processReq(JsonObject payload);

    std::unique_ptr<DynamicJsonDocument> createConf();
};

} //end namespace Ocpp16
} //end namespace ArduinoOcpp
#endif
