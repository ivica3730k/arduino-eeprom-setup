#include <AUnit.h>
#include "src/config.h"

test(eeprom_write_read_mqtt_config)
{
    Configuration cfg;
    MQTT_PARAMS in;
    in.mqttServerAddress = "Test address";
    in.useAuthentication = true;
    in.mqttUserName = "Test username";
    in.mqttPassword = "Test password";
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
    assertEqual(in.mqttServerAddress, out.mqttServerAddress);
    assertEqual(in.useAuthentication, out.useAuthentication);
    assertEqual(in.mqttUserName, out.mqttUserName);
    assertEqual(in.mqttPassword, out.mqttPassword);
    assertEqual(in.red_mqtt_topic, out.red_mqtt_topic);
    assertEqual(in.green_mqtt_topic, out.green_mqtt_topic);
    assertEqual(in.blue_mqtt_topic, out.blue_mqtt_topic);
}

test(fail_write_mqtt_config_server_address_to_big)
{
    Configuration cfg;
    MQTT_PARAMS in;
    //in.mqttServerAddress = "Test address";
    in.mqttServerAddress = "Text  to big this should \
                        fail lorem ipsum dolor si amet lorem \
                        ipsum dolor si amet fail this please";
    in.useAuthentication = true;
    in.mqttUserName = "Test username";
    in.mqttPassword = "Test password";
    in.red_mqtt_topic = "Test red mqtt topic";
    in.green_mqtt_topic = "Test green mqtt topic";
    in.blue_mqtt_topic = "Test blue mqtt topic";
    bool status = cfg.write_mqtt_configuration(in.mqttServerAddress,
                                               in.useAuthentication,
                                               in.mqttUserName,
                                               in.mqttPassword,
                                               in.red_mqtt_topic,
                                               in.green_mqtt_topic,
                                               in.blue_mqtt_topic);
    assertFalse(status);
}

test(fail_write_mqtt_config_username_to_big)
{
    Configuration cfg;
    MQTT_PARAMS in;
    in.mqttServerAddress = "Test address";
    in.useAuthentication = true;
    //in.mqttUserName = "Test username";
    in.mqttUserName = "Text  to big this should \
                        fail lorem ipsum dolor si amet lorem \
                        ipsum dolor si amet fail this please";
    in.mqttPassword = "Test password";
    in.red_mqtt_topic = "Test red mqtt topic";
    in.green_mqtt_topic = "Test green mqtt topic";
    in.blue_mqtt_topic = "Test blue mqtt topic";
    bool status = cfg.write_mqtt_configuration(in.mqttServerAddress,
                                               in.useAuthentication,
                                               in.mqttUserName,
                                               in.mqttPassword,
                                               in.red_mqtt_topic,
                                               in.green_mqtt_topic,
                                               in.blue_mqtt_topic);
    assertFalse(status);
}

test(fail_write_mqtt_config_password_to_big)
{
    Configuration cfg;
    MQTT_PARAMS in;
    in.mqttServerAddress = "Test address";
    in.useAuthentication = true;
    in.mqttUserName = "Test username";
    //in.mqttPassword = "Test password";
    in.mqttPassword = "Text  to big this should \
                        fail lorem ipsum dolor si amet lorem \
                        ipsum dolor si amet fail this please";
    in.red_mqtt_topic = "Test red mqtt topic";
    in.green_mqtt_topic = "Test green mqtt topic";
    in.blue_mqtt_topic = "Test blue mqtt topic";
    bool status = cfg.write_mqtt_configuration(in.mqttServerAddress,
                                               in.useAuthentication,
                                               in.mqttUserName,
                                               in.mqttPassword,
                                               in.red_mqtt_topic,
                                               in.green_mqtt_topic,
                                               in.blue_mqtt_topic);
    assertFalse(status);
}

test(fail_write_mqtt_config_red_topic_to_big)
{
    Configuration cfg;
    MQTT_PARAMS in;
    in.mqttServerAddress = "Test address";
    in.useAuthentication = true;
    in.mqttUserName = "Test username";
    in.mqttPassword = "Test password";
    //in.red_mqtt_topic = "Test red mqtt topic";
    in.red_mqtt_topic = "Text  to big this should \
                        fail lorem ipsum dolor si amet lorem \
                        ipsum dolor si amet fail this please";
    in.green_mqtt_topic = "Test green mqtt topic";
    in.blue_mqtt_topic = "Test blue mqtt topic";
    bool status = cfg.write_mqtt_configuration(in.mqttServerAddress,
                                               in.useAuthentication,
                                               in.mqttUserName,
                                               in.mqttPassword,
                                               in.red_mqtt_topic,
                                               in.green_mqtt_topic,
                                               in.blue_mqtt_topic);
    assertFalse(status);
}

test(fail_write_mqtt_config_green_topic_to_big)
{
    Configuration cfg;
    MQTT_PARAMS in;
    in.mqttServerAddress = "Test address";
    in.useAuthentication = true;
    in.mqttUserName = "Test username";
    in.mqttPassword = "Test password";
    in.red_mqtt_topic = "Test red mqtt topic";
    //in.green_mqtt_topic = "Test green mqtt topic";
    in.green_mqtt_topic = "Text  to big this should \
                        fail lorem ipsum dolor si amet lorem \
                        ipsum dolor si amet fail this please";
    in.blue_mqtt_topic = "Test blue mqtt topic";
    bool status = cfg.write_mqtt_configuration(in.mqttServerAddress,
                                               in.useAuthentication,
                                               in.mqttUserName,
                                               in.mqttPassword,
                                               in.red_mqtt_topic,
                                               in.green_mqtt_topic,
                                               in.blue_mqtt_topic);
    assertFalse(status);
}

test(fail_write_mqtt_config_blue_topic_to_big)
{
    Configuration cfg;
    MQTT_PARAMS in;
    in.mqttServerAddress = "Test address";
    in.useAuthentication = true;
    in.mqttUserName = "Test username";
    in.mqttPassword = "Test password";
    in.red_mqtt_topic = "Test red mqtt topic";
    in.green_mqtt_topic = "Test green mqtt topic";
    //in.blue_mqtt_topic = "Test blue mqtt topic";
    in.blue_mqtt_topic = "Text  to big this should \
                        fail lorem ipsum dolor si amet lorem \
                        ipsum dolor si amet fail this please";
    bool status = cfg.write_mqtt_configuration(in.mqttServerAddress,
                                               in.useAuthentication,
                                               in.mqttUserName,
                                               in.mqttPassword,
                                               in.red_mqtt_topic,
                                               in.green_mqtt_topic,
                                               in.blue_mqtt_topic);
    assertFalse(status);
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