/*
 *  Copyright (C) 2021-2023 Intel Corporation
 *  SPDX-License-Identifier: MIT
 *  @file utility.cpp
 */

#include <stdarg.h>
#include <syslog.h>
#include <unistd.h>

#include <cstdio>
#include <string>
#include <regex>
#include <iomanip>
#include <fstream>

#include "utility.h"

namespace xpum::cli {

bool isNumber(const std::string &str) {
    return str.size() && str.find_first_not_of("0123456789") == std::string::npos;
}

bool isInteger(const std::string &str) {
    const std::string bdfFormat = "^-?\\d+$";
    return std::regex_match(str, std::regex(bdfFormat));
}

bool isValidDeviceId(const std::string &str) {
    if (!isNumber(str)) {
        return false;
    }

    int value;
    try {
        value = std::stoi(str);
    } catch (const std::out_of_range &oor) {
        return false;
    }
    if (value < 0) {
        return false;
    }

    return true;
}

bool isValidTileId(const std::string &str) {
    if (!isNumber(str)) {
        return false;
    }

    int value;
    try {
        value = std::stoi(str);
    } catch (const std::out_of_range &oor) {
        return false;
    }
    if (value < 0 || value > 1) {
        return false;
    }

    return true;
}

bool isBDF(const std::string &str) {
    const std::string bdfFormat = "[a-f0-9]{4}:[a-f0-9]{2}:[a-f0-9]{2}\\.[a-f0-9]{1}";
    return std::regex_match(str, std::regex(bdfFormat));
}

bool isShortBDF(const std::string &str) {
    const std::string bdfFormat = "[a-f0-9]{2}:[a-f0-9]{2}\\.[a-f0-9]{1}";
    return std::regex_match(str, std::regex(bdfFormat));
}

std::string to_hex_string(uint64_t val, int width) {
    std::stringstream s;
    if (width == 0)
        s << std::string("0x") << std::hex << val;
    else
        s << std::string("0x") << std::setfill('0') << std::setw(width) << std::hex << val;
    return s.str();
}

std::string add_two_hex_string(std::string str1, std::string str2) {
    uint64_t u1 = std::stoul(str1.c_str(), 0, 16);
    uint64_t u2 = std::stoul(str2.c_str(), 0, 16);

    return to_hex_string(u1 + u2);
}

std::string toString(const std::vector<int> vec) {
    if (vec.empty()) {
        return "";
    }
    std::stringstream ss;
    for (size_t i = 0; i < vec.size(); i++) {
        if (i != 0) {
            ss << ", ";
        }
        ss << vec[i];
    }
    return ss.str();
}

std::string trim(const std::string& str, const std::string& toRemove) {
    const auto strBegin = str.find_first_not_of(toRemove);
    if (strBegin == std::string::npos)
        return "";

    const auto strEnd = str.find_last_not_of(toRemove);
    const auto strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}

linux_os_release_t getOsRelease() {
    /*
     *  Refer https://www.linux.org/docs/man5/os-release.html
     */
    std::ifstream ifs("/etc/os-release");
    if (!ifs.is_open()) {
        return LINUX_OS_RELEASE_UNKNOWN;
    }
    std::string line;
    while (std::getline(ifs, line)) {
        line = trim(line, " \t");
        std::istringstream iss(line);
        std::string key, value;
        if (std::getline(iss, key, '=') && std::getline(iss, value) && key.compare("ID") == 0) {
            if (value.find("ubuntu") != std::string::npos) {
                return LINUX_OS_RELEASE_UBUNTU;
            } else if (value.find("centos") != std::string::npos) {
                return LINUX_OS_RELEASE_CENTOS;
            } else if (value.find("sles") != std::string::npos) {
                return LINUX_OS_RELEASE_SLES;
            } else if (value.find("rhel") != std::string::npos) {
                return LINUX_OS_RELEASE_RHEL;
            } else if (value.find("debian") != std::string::npos) {
                return LINUX_OS_RELEASE_DEBIAN;
            } else {
                return LINUX_OS_RELEASE_UNKNOWN;
            }
        }
    }
    return LINUX_OS_RELEASE_UNKNOWN;
}

bool isFileExists(const char* path) {
    std::ifstream ifs(path);
    return ifs.good();
}

}// end namespace xpum::cli
