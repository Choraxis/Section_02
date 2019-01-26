#include "bull_cow_game.h"

using FString = std::string;
using int32 = int;

static constexpr int32 kMaxTries = 3;
static const FString kHiddenWord = "planet";

BullCowGame::BullCowGame() { Reset(); }

int32 BullCowGame::GetMaxTries() const { return my_max_tries_; }
int32 BullCowGame::GetCurrentTry() const { return my_current_try_; }
int32 BullCowGame::GetHiddenWordLength() const { return my_hidden_word_.length(); }

void BullCowGame::Reset() {
  my_current_try_ = 1;
  my_max_tries_ = kMaxTries;
  my_hidden_word_ = kHiddenWord;
}

BullCowCount BullCowGame::SubmitValidGuess(FString guess) {
  ++my_current_try_;
  BullCowCount BCC;
  int32 hidden_word_length = my_hidden_word_.length();
  int32 guess_length = guess.length();

  for (int32 i = 0; i < hidden_word_length; ++i) {
    for (int32 j = 0; j < guess_length; ++j) {
      if (my_hidden_word_[i] == guess[j]) {
          if (i == j)
            ++BCC.bulls_;
          else
            ++BCC.cows_;
      }
    }
  }
  return BCC;
}

bool BullCowGame::IsGameWon() const {
  return false;
}

GuessStatus BullCowGame::CheckGuessValidity(FString guess) const {
  if (false)
    return GuessStatus::Not_Isogram;
  else if (false)
    return GuessStatus::Not_Lowercase;
  else if (guess.length() != my_hidden_word_.length())
    return GuessStatus::Incorrect_Length;
  else
    return GuessStatus::OK;
}