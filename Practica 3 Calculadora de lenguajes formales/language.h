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

    void set_tag_language(std::string tag);
    void set_contain_language(std::string contain);

    std::string get_tag_language(int i);
    std::string get_contain_language(int i);
};