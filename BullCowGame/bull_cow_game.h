#ifndef _BULL_COW_GAME_H_
#define _BULL_COW_GAME_H_

#include <string>

using FString = std::string;
using int32 = int;

// all values initialized to zero
struct BullCowCount {
  int32 bulls_ = 0;
  int32 cows_ = 0;
};

enum class GuessStatus {
  Invalid_Status,
  OK,
  Not_Isogram,
  Incorrect_Length,
  Not_Alphabetic,
  Not_Lowercase
};

class BullCowGame {
 public:
  BullCowGame();

  int32 GetMaxTries() const;
  int32 GetCurrentTry() const;
  int32 GetHiddenWordLength() const;

  bool IsGameWon() const;
  GuessStatus CheckGuessValidity(FString) const;

  void Reset();  // TODO make a more rich return value
  // counts bulls & cows, and increases try number assuming valid guess
  BullCowCount SubmitValidGuess(FString);


 private:
  int32 my_current_try_;
  int32 my_max_tries_;
  FString my_hidden_word_;
};

#endif  // _BULL_COW_GAME_H_