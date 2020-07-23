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
        ProcessGuess(Input);
    }
}

void UBullCowCartridge::SetupGame()
{

    PrintLine(TEXT("Welcome to Bull Cows!"));

    HiddenWord = TEXT("cakes");
    Lives =HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("Guess The %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("You have %i Lives"),Lives);
    PrintLine(TEXT("Type in your guess.\nPress enter to continue.."));

    // const TCHAR HW[] = TEXT("plums");
    // PrintLine(TEXT("Charcter 1 of the hidden word is : %c"),HiddenWord[0]);
    // PrintLine(TEXT("The 4th charcter of HW is : %c"),HW[3]);

}

void UBullCowCartridge::EndGame()
{
    bGameOver=true;
    PrintLine(TEXT("\nPress enter to go play again.."));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if(Guess == HiddenWord){
        PrintLine(TEXT("You have Won!"));
        EndGame();
        return;
    }
    
    if(Guess.Len() != HiddenWord.Len()){
        PrintLine(TEXT("The hidden word is %i letters long"), HiddenWord.Len());
        PrintLine(TEXT("Sorry, try guessing again! \nYou have %i lives remaining"), Lives);
        return;
    }

    if(!IsIsogram(Guess)){
        PrintLine(TEXT("No repeating letters, guess again"));
        return;
    }

    PrintLine(TEXT("Lost a life!"));
    --Lives;

    if(Lives<=0){
        ClearScreen();
        PrintLine(TEXT("You have no lives left!"));
        PrintLine(TEXT("The hidden word was: %s"),*HiddenWord);
        EndGame();
        return; 
    }

    PrintLine(TEXT("Guess again, you have %i lives left"),Lives);

}

bool UBullCowCartridge::IsIsogram(FString Word) const
{
    
    return true;
}