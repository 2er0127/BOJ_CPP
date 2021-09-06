#include <iostream>
#include <vector>
#include <array>
#include <sstream>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

struct card {
    int number;
    
    enum suit {
        HEART, SPADE, CLUB, DIAMOND
    } suit;
    
    string to_sting() const {
        ostringstream os;
        
        if(number>0&&number<=10)
            os<<number;
        
        else {
            switch(number) {
                case 1:
                    os<<"Ace";
                    break;
                case 11:
                    os<<"Jack";
                    break;
                case 12:
                    os<<"Queen";
                    break;
                case 13:
                    os<<"King";
                    break;
                default:
                    return "Invalid card";
            }
        }
        
        os<<" of ";
        
        switch (suit) {
            case HEART:
                os<<"hearts";
                break;
            case SPADE:
                os<<"spades";
                break;
            case CLUB:
                os<<"clubs";
                break;
            case DIAMOND:
                os<<"diamonds";
                break;
        }
        return os.str();
    }
};
