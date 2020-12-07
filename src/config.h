#include <Arduino.h>
#include "effiicentEEPROM.h"

namespace config
{
    const uint8_t USE_MQTT = 10;
    const uint8_t USE_WEBSERVER = 11;

    struct MQTT_PARAMS
    {
        uint8_t _TYPE = USE_MQTT;
        char mqttServerAddress[20];
        bool useAuthentication;
        char mqttUserName[20];
        char mqttPassword[20];
        char red_mqtt_topic[50];
        char green_mqtt_topic[50];
        char blue_mqtt_topic[50];
    };

    struct WEB_SERVER_PARAMS
    {
        uint8_t _TYPE = USE_WEBSERVER;
        uint16_t PORT = 8080;
    };

    struct WIFI_DETAILS
    {
        char ssid[50];
        char passwd[50];
    };

}; // namespace config

struct MQTT_PARAMS
{
    String mqttServerAddress;
    bool useAuthentication;
    String mqttUserName;
    String mqttPassword;
    String red_mqtt_topic;
    String green_mqtt_topic;
    String blue_mqtt_topic;
};

class Configuration
{
public:
    Configuration();
    bool write_mqtt_configuration(String mqttServerAddress,
                                  bool useAuthentication,
                                  String mqttUserName,
                                  String mqttPassword,
                                  String red_mqtt_topic,
                                  String green_mqtt_topic,
                                  String blue_mqtt_topic);
    MQTT_PARAMS get_mqtt_configuration();

private:
};