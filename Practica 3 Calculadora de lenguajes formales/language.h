/**
 * @file language.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string>
#include <vector>

class language {
  private:
    std::vector<std::string> tag_language;
    std::vector<std::string> contain_language;
    
  public: 
    language();
    ~language();
};