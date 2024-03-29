//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by Philipp C. Moser on 08.12.17.
//  Copyright © 2017 Philipp C. Moser. All rights reserved.
//

#include "FBullCowGame.hpp"

FBullCowGame::FBullCowGame() { Reset(); }

// Getter Methods 
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }


void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 8;
    const FString HIDDEN_WORD = "planet";
    
    MyMaxTries = MAX_TRIES;
    MyHiddenWord = HIDDEN_WORD;
    MyCurrentTry = 1;
    bGameIsWon = false;
    return;
}



EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const // TODO get more specific
{
    if (false) // if the guess is not an isogram
    {
        return EGuessStatus::Not_Isogram;
    }
    else if (false) // if the guess is not at all lowercase
    {
        return EGuessStatus::Not_Lowercase;
    }
    else if (Guess.length() != GetHiddenWordLength()) // if the guess length is wrong
    {
        return EGuessStatus::Wrong_Length;
    }
    else // otherwise
    {
        return EGuessStatus::OK;
    }
}

// receives a VALID guess, increments turn and return 
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
    MyCurrentTry++;
    
    FBullCowCount BullCowCount;
    int32 WordLength = MyHiddenWord.length(); // assuming same length as guess
    
    // loop throught all letters in the hidden word
    for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) {
        // compare letters against the guess.
        for (int32 GChar = 0; GChar < WordLength; GChar++) {
            if(Guess[GChar] == MyHiddenWord[MHWChar]) { // if they match then
                
                if( MHWChar == GChar) { // if they're in the same place
                    BullCowCount.Bulls++; // increment bulls if they're in the same place
                }
                else {
                    BullCowCount.Cows++; // increment cows if they are not.
                }
            }
        }
    }
    
    if ( BullCowCount.Bulls == WordLength)
    {
        bGameIsWon = true;
    }
    else
    {
        bGameIsWon = false;
    }
    
    return BullCowCount;
}
