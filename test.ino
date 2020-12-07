#include <AUnit.h>
#include "src/config.h"
test(eeprom_write_read_mqtt_config)
{
    Configuration cfg;
    MQTT_PARAMS in;
    in.mqttServerAddress = "Test address";
    in.useAuthentication = true;
    in.mqttUserName = "Test username";
    in.mqttPassword = "Test passwpord";
    in.red_mqtt_topic = "Test red mqtt topic";
    in.green_mqtt_topic = "Test green mqtt topic";
    in.blue_mqtt_topic = "Test blue mqtt topic";
    cfg.write_mqtt_configuration(in.mqttServerAddress,
                                 in.useAuthentication,
                                 in.mqttUserName,
                                 in.mqttPassword,
                                 in.red_mqtt_topic,
                                 in.green_mqtt_topic,
                                 in.blue_mqtt_topic);
    MQTT_PARAMS out = cfg.get_mqtt_configuration();
    assertEqual(in.mqttServerAddress,out.mqttServerAddress);
    assertEqual(in.useAuthentication,out.useAuthentication);
    assertEqual(in.mqttUserName,out.mqttUserName);
    assertEqual(in.mqttPassword,out.mqttPassword);
    assertEqual(in.red_mqtt_topic,out.red_mqtt_topic);
    assertEqual(in.green_mqtt_topic,out.green_mqtt_topic);
    assertEqual(in.blue_mqtt_topic,out.blue_mqtt_topic);
}

void setup()
{
    delay(1000);
    Serial.begin(115200);
    while (!Serial)
    {
        /* code */
    }

    Serial.println("Starting tests!\n\n");
}

void loop()
{
    aunit::TestRunner::run();
}