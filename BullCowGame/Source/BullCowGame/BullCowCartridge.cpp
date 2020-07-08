// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"


void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame();

    PrintLine(TEXT("The Hidden Word is : %s."),*HiddenWord);
    
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
            --Lives;
            PrintLine(TEXT("Lost a life!"));
            if(Lives>0){
                if(Input.Len() != HiddenWord.Len()){
                    PrintLine(TEXT("Sorry, try guessing again! \nYou have %i lives remaining"), Lives);
                    EndGame();
                }
            }else{
                PrintLine(TEXT("You have no lives left!"));
                EndGame();
            }
        }
    }
}

void UBullCowCartridge::SetupGame()
{

    PrintLine(TEXT("Welcome to Bull Cows!"));

    HiddenWord = TEXT("cake");
    Lives =HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("Guess The %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("You have %i Lives"),Lives);
    PrintLine(TEXT("Type in your guess.\nPress enter to continue.."));

}

void UBullCowCartridge::EndGame()
{
    bGameOver=true;
    PrintLine(TEXT("Press enter to go play again.."));
}