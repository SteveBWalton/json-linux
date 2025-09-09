/// Implementation for json handling.
///@file json.cpp

// File Header.
#include "json.h"

// System Headers.
#include <string>
#include <map>



namespace json
{

bool getPair
(
//  const std::string& text,
    std::string_view jsonString,
    int& pos,
    std::string& key,
    std::string& value
)
{
    // Check that we have not reached the end.
    if (pos >= (int)jsonString.length())
    {
        return false;
    }

    // Ignore white spaces & line breaks
    while (jsonString[pos] == ' ' || jsonString[pos] == '\n')
    {
        pos++;
        if (pos >= (int)jsonString.length())
        {
            return false;
        }
    }

    int currentPos;
    key = "";
    value = "";

    // If hit a double quote for the first time this is the key.
    while (jsonString[pos] != '\"')
    {
        pos++;
        if (pos >= (int)jsonString.length())
        {
            return false;
        }
    }

    // Start of the key.
    currentPos = ++pos;
    while (jsonString[pos] != '\"')
    {
        pos++;
    }

    key = jsonString.substr(currentPos, pos - currentPos);
    pos++;

    // Now we need to find the corresponding value.

    // ignore :, white spaces & line breaks
    while (jsonString[pos] == ' ' || jsonString[pos] == '\n' || jsonString[pos] == ':')
    {
        pos++;
    }

    if (jsonString[pos] == '{')
    {
        // Another json format value.
        currentPos = pos;
        while (jsonString[pos] != '}')
        {
            pos++;
        }

        value = jsonString.substr(currentPos, pos - currentPos + 1);
    }
    else
    {
        // Primitive value.
        currentPos = pos;

        while (jsonString[pos] != '}' && jsonString[pos] != ',')
        {
            pos++;
        }

        // Remove any extra white space.
        int endPos = pos - 1;
        while (jsonString[endPos] == ' ' || jsonString[endPos] == '\n')
        {
            endPos--;
        }

        // Store the value string.
        value = jsonString.substr(currentPos, endPos - currentPos + 1);
    }

    // After parsing the value, check whether the current points to a comma.
    if (jsonString[pos] == ',')
    {
        pos++;
    }

    // Return success.
    return true;
}



// Convert the json in a string to a std::map.
std::map<std::string, std::string> getJson(std::string_view jsonString)
{
    // Define a map to hold the json.
    std::map<std::string, std::string> mapJson;

    // Example map.
    // mapJson.insert(std::make_pair("articleDescription", "Welle geschweisst"));
    // mapJson.insert(std::make_pair("cpid", "(8022)4056778MHG0HAQUWX"));


    // Loop through the string and add elements to the json map.
    int pos = 0;
    std::string key;
    std::string value;

    while (getPair(jsonString, pos, key, value))
    {
        mapJson.insert(std::make_pair(key, value));
    }

    // Return the map built.
    return mapJson;
}



// Convert a json cell to std::string.
std::string getString(const std::string& jsonString)
{
    std::string result = "";
    if (jsonString == "null")
    {
        return result;
    }
    if (jsonString[0]=='\"')
    {
        return jsonString.substr(1, jsonString.length()-2);
    }
    return jsonString;
}



// Convert a json cell to bool.
bool getBool(const std::string& jsonString)
{
    if (jsonString.substr(0, 4) == "true")
    {
        return true;
    }
    if (jsonString.substr(0, 1) == "1")
    {
        return true;
    }

    // Default to false.
    return false;
}

}
