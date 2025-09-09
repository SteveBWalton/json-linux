/// Definitions for json handling.
///@file json.h

#pragma once

// PLCnext Headers.

// System Headers.
#include <string>
#include <map>

namespace json
{

// The type to hold a json data.
typedef std::map<std::string, std::string> Json;

// Convert json to a std::map.
// std::map<std::string, std::string> getJson(std::string_view);
Json getJson(std::string_view);

// Convert to Json cell to std::string.
std::string getString(const std::string&);

// Convert to Json cell to bool.
bool getBool(const std::string&);

}
