#include "config.h"

Configuration::Configuration()
{
}

bool Configuration::write_mqtt_configuration(String mqttServerAddress,
                                             bool useAuthentication,
                                             String mqttUserName,
                                             String mqttPassword,
                                             String red_mqtt_topic,
                                             String green_mqtt_topic,
                                             String blue_mqtt_topic)
{
    config::MQTT_PARAMS conf;
    if (mqttServerAddress.length() > sizeof(conf.mqttServerAddress))
    {
        return false;
    }
    mqttServerAddress.toCharArray(conf.mqttServerAddress, sizeof(conf.mqttServerAddress));
    conf.useAuthentication = useAuthentication;
    if (mqttUserName.length() > sizeof(conf.mqttUserName))
    {
        return false;
    }
    mqttUserName.toCharArray(conf.mqttUserName, sizeof(conf.mqttUserName));
    if (mqttPassword.length() > sizeof(conf.mqttPassword))
    {
        return false;
    }
    mqttPassword.toCharArray(conf.mqttPassword, sizeof(conf.mqttPassword));
    if (red_mqtt_topic.length() > sizeof(conf.red_mqtt_topic))
    {
        return false;
    }
    red_mqtt_topic.toCharArray(conf.red_mqtt_topic, sizeof(conf.red_mqtt_topic));
    if (green_mqtt_topic.length() > sizeof(conf.green_mqtt_topic))
    {
        return false;
    }
    green_mqtt_topic.toCharArray(conf.green_mqtt_topic, sizeof(conf.green_mqtt_topic));
    if (blue_mqtt_topic.length() > sizeof(conf.blue_mqtt_topic))
    {
        return false;
    }
    blue_mqtt_topic.toCharArray(conf.blue_mqtt_topic, sizeof(conf.blue_mqtt_topic));
    char buffer[sizeof(conf)];
    memcpy(&buffer, &conf, sizeof(conf));
    writeEEPROM(sizeof(config::WIFI_DETAILS), buffer, sizeof(buffer));
    return true;
}

MQTT_PARAMS Configuration::get_mqtt_configuration()
{
    char buffer[sizeof(config::MQTT_PARAMS)];
    readEEPROM(sizeof(config::WIFI_DETAILS), buffer, sizeof(config::MQTT_PARAMS));
    config::MQTT_PARAMS mqtt_parameters_binary;
    memcpy(&mqtt_parameters_binary, &buffer, sizeof(config::MQTT_PARAMS));
    MQTT_PARAMS mqtt_parameters;
    mqtt_parameters.mqttServerAddress = String(mqtt_parameters_binary.mqttServerAddress);
    mqtt_parameters.useAuthentication = mqtt_parameters_binary.useAuthentication;
    mqtt_parameters.mqttUserName = String(mqtt_parameters_binary.mqttUserName);
    mqtt_parameters.mqttPassword = String(mqtt_parameters_binary.mqttPassword);
    mqtt_parameters.red_mqtt_topic = String(mqtt_parameters_binary.red_mqtt_topic);
    mqtt_parameters.green_mqtt_topic = String(mqtt_parameters_binary.green_mqtt_topic);
    mqtt_parameters.blue_mqtt_topic = String(mqtt_parameters_binary.blue_mqtt_topic);
    return mqtt_parameters;
}