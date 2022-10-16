/**
 * @file strings.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

#include <string>
#include <vector>

class symbol;

class strings {
  public:
    strings(std::string str);
    std::vector<symbol> getstring() const;
    
  private:
    std::vector<symbol> strings_;
    
};

bool operator<(const strings& strings1, const strings& strings2);
bool operator==(const strings& strings1, const strings& strings2);
std::ostream& operator<<(std::ostream& out, const strings& strings);