//
//  ColourSchme.hpp
//  MusicTing
//
//  Created by Mr. M on 21/11/2016.
//
//

#ifndef ColourSchme_hpp
#define ColourSchme_hpp

#include <stdio.h>

#endif /* ColourSchme_hpp */

#include <map>

struct ColourSchme{
    std::map<char, int> colour1;
    std::map<char, int> colour2;
    std::map<char, int> colour3;
    std::map<char, int> colour4;
    std::map<char, int> colour5;
    
    void setColour1(int r, int g, int b);
    void setColour2(int r, int g, int b);
    void setColour3(int r, int g, int b);
    void setColour4(int r, int g, int b);
    void setColour5(int r, int g, int b);
};
