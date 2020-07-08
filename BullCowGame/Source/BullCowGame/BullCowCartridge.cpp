// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"


void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame();

    PrintLine(TEXT("The Hidden Word is : %s."),*HiddenWord);
    // PrintLine(FString::Printf(TEXT("The Hidden Word is : %s"),*HiddenWord));

    
    
    
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if(bGameOver){
        ClearScreen();
        SetupGame();
    }else{
        if(Input == HiddenWord){
            PrintLine(TEXT("You have Won!"));
            EndGame();
        }else{
            if(Input.Len() != HiddenWord.Len()){
                PrintLine(TEXT("The Hidden Word is %i characters long. \nYou have Lost"), HiddenWord.Len());
                EndGame();
            }
            PrintLine(TEXT("You have Lost!"));
            // bGameOver = true;
        }

    }
    

    
    


}

void UBullCowCartridge::SetupGame()
{

    PrintLine(TEXT("Welcome to Bull Cows!"));

    HiddenWord = TEXT("cake");
    Lives =4;
    bGameOver = false;

    PrintLine(TEXT("Guess The %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("Type in your guess.\nPress enter to continue.."));

}

void UBullCowCartridge::EndGame()
{
    bGameOver=true;
    PrintLine(TEXT("Press enter to go play again.."));
}