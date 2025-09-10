/// Implementation for the Parallel class.
///@file parallel.cpp

// File Header.
#include "json-test.h"

// System Headers.
#include <iostream>

// Application Headers.
#include "json.h"




/// Main entry point for the curl-test program,
int main
(
    int             argc,
    const char**    argv
)
{

    // Welcome message.
    std::cout << "Hello from json-test." << std::endl;

    // Build a test string.
    // std::string jsonString = "{\"param1\":\"value1\",\"param2\":\"value2\"}";
    std::string jsonString = "{\n\"param1\":  \"value1\",\n\"param2\":\"value2\"  ,   \"param3\" : 16,\n \"param4\" : {\"param1\":\"value1\",\"param2\":\"value2\"}   ,  \"param5\"    :    17,\n\"param5\":18,\"param7\":18\n}\n";
    std::cout << jsonString << std::endl;

    // Test the decoder.
    json::Json json = json::getJson(jsonString);

    for (auto it = json.cbegin(); it != json.cend(); it++)
    {
        std::cout << "\"" << it->first << "\": [" << it->second << "]" << std::endl;
    }

    if (json.find("param2") != json.cend())
    {
        std::cout << "The value of param2 is " << json::getString(json["param2"]) << "." << std::endl;
    }

    // Return success.
    std::cout << "Goodbye from json-test." << std::endl;
    return 0;
}

