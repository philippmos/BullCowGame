//
//  FBullCowGame.hpp
//  BullCowGame
//
//  Created by Philipp C. Moser on 08.12.17.
//  Copyright © 2017 Philipp C. Moser. All rights reserved.
//

#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp

#include <stdio.h>
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
    int32 Bulls = 0;
    int32 Cows = 0;
};

    
#endif /* FBullCowGame_hpp */


class FBullCowGame {
public:
    FBullCowGame(); // constructor
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    bool IsGameWon() const;
    
    void Reset();
    bool CheckGuessValidity(FString);
    
    // counts bulls & cows and increases try # assuming valid guess
    FBullCowCount SubmitGuess(FString);
    
    
    
    
    
// Please try and ignore this and focus on the interface above
private:
    int32 MyCurrentTry = 1;
    int32 MyMaxTries = 5;
    FString MyHiddenWord;
};
