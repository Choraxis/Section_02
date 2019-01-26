/* Copyright 2019 Christian Meetze
 * This is the console executable that makes use of the BullCow class.
 * This acts as the view in a MVC pattern, and is responsible for all
 * user interaction. For game logic see the BullCowGame class.
*/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::getline;

#include "bull_cow_game.h"
#include "main.h"

using FText = std::string;
using int32 = int;

BullCowGame BCGame;

void PrintIntro() {
  cout << "Welcome to Bulls and Cows, a fun word game." << endl;
  cout << "Can you guess the " << BCGame.GetHiddenWordLength()
       << " letter isogram I'm thinking of?" << endl;
}

// loop continually until the user gives a valid guess
FText GetValidGuess() {
  GuessStatus status = GuessStatus::Invalid_Status;
  FText guess = "";

  do {
    cout << "Try " << BCGame.GetCurrentTry() << ". Enter your guess > ";
    getline(cin, guess);
    status = BCGame.CheckGuessValidity(guess);

    switch (status) {
    case GuessStatus::Incorrect_Length:
      cout << "Please enter a " << BCGame.GetHiddenWordLength()
            << " letter word." << endl;
      break;
    case GuessStatus::Not_Alphabetic:
      cout << "Please enter a word that only consists of letters." << endl;
      break;
    case GuessStatus::Not_Isogram:
      cout << "Please enter an isogram." << endl;
      break;
    case GuessStatus::Not_Lowercase:
      cout << "Please enter a lowercase word." << endl;
      break;
    default:
      break;
    }
  } while (status != GuessStatus::OK);
  return guess;
}

void PlayGame() {
  BCGame.Reset();
  int32 max_tries = BCGame.GetMaxTries();

  while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= max_tries) {
    FText guess = GetValidGuess();
    BullCowCount BCC = BCGame.SubmitValidGuess(guess);
    cout << "Bulls = " << BCC.bulls_ << ". Cows = " << BCC.cows_ << endl
         << endl;
  }
}

bool AskToPlayAgain() {
  if (BCGame.IsGameWon())
    cout << "You won! Great job!" << endl;
  else
    cout << "Better luck next time!" << endl;
  cout << "Do you want to play again? (y/n) > ";
  FText response;
  getline(cin, response);

  return (response[0] == 'y') || (response[0] == 'Y');
}

int main(int32 argc, char* argv[]) {
  do {
    PrintIntro();
    PlayGame();
    // TODO add a game summary
  } while (AskToPlayAgain() == true);

  return 0;
}