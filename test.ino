#include <AUnit.h>
#include "src/config.h"

test(eeprom_write_read_wifi_details)
{
    Configuration cfg;
    WIFI_DETAILS in;
    in.ssid = "Test SSID";
    in.passwd = "Test PASSWD";
    cfg.write_wifi_details(in.ssid, in.passwd);
    WIFI_DETAILS out = cfg.get_wifi_details();
    assertEqual(in.ssid, out.ssid);
    assertEqual(in.passwd, out.passwd);
}

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

test(full_eeprom_write_test)
{
    Configuration cfg;
    WIFI_DETAILS in;
    in.ssid = "Test SSID";
    in.passwd = "Test PASSWD";
    cfg.write_wifi_details(in.ssid, in.passwd);
    MQTT_PARAMS mqtt_in;
    mqtt_in.mqttServerAddress = "Test address";
    mqtt_in.useAuthentication = true;
    mqtt_in.mqttUserName = "Test username";
    mqtt_in.mqttPassword = "Test password";
    mqtt_in.red_mqtt_topic = "Test red mqtt topic";
    mqtt_in.green_mqtt_topic = "Test green mqtt topic";
    mqtt_in.blue_mqtt_topic = "Test blue mqtt topic";
    cfg.write_mqtt_configuration(mqtt_in.mqttServerAddress,
                                 mqtt_in.useAuthentication,
                                 mqtt_in.mqttUserName,
                                 mqtt_in.mqttPassword,
                                 mqtt_in.red_mqtt_topic,
                                 mqtt_in.green_mqtt_topic,
                                 mqtt_in.blue_mqtt_topic);
    WIFI_DETAILS wifi_out = cfg.get_wifi_details();
    assertEqual(in.ssid, wifi_out.ssid);
    assertEqual(in.passwd, wifi_out.passwd);
    MQTT_PARAMS mqtt_out = cfg.get_mqtt_configuration();
    assertEqual(mqtt_in.mqttServerAddress, mqtt_out.mqttServerAddress);
    assertEqual(mqtt_in.useAuthentication, mqtt_out.useAuthentication);
    assertEqual(mqtt_in.mqttUserName, mqtt_out.mqttUserName);
    assertEqual(mqtt_in.mqttPassword, mqtt_out.mqttPassword);
    assertEqual(mqtt_in.red_mqtt_topic, mqtt_out.red_mqtt_topic);
    assertEqual(mqtt_in.green_mqtt_topic, mqtt_out.green_mqtt_topic);
    assertEqual(mqtt_in.blue_mqtt_topic, mqtt_out.blue_mqtt_topic);
}

test(fail_write_read_wifi_details_ssid_to_big)
{
    Configuration cfg;
    WIFI_DETAILS in;
    in.ssid = "Text  to big this should \
                fail lorem ipsum dolor si amet lorem \
                ipsum dolor si amet fail this please";
    in.passwd = "Test PASSWD";
    bool status = cfg.write_wifi_details(in.ssid, in.passwd);
    assertFalse(status);
}

test(fail_write_read_wifi_details_passwd_to_big)
{
    Configuration cfg;
    WIFI_DETAILS in;
    in.ssid = "Test SSID";
    in.passwd = "Text  to big this should \
                fail lorem ipsum dolor si amet lorem \
                ipsum dolor si amet fail this please";
    bool status = cfg.write_wifi_details(in.ssid, in.passwd);
    assertFalse(status);
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
    EEPROM.begin(512);
    Serial.println("Starting tests!\n\n");
}

void loop()
{
    aunit::TestRunner::run();
}