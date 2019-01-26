#ifndef _BULLCOWGAME_MAIN_H_
#define _BULLCOWGAME_MAIN_H_

using FString = std::string;
using int32 = int;

void PrintIntro();
FString GetGuess();
void PlayGame();
bool AskToPlayAgain();

#endif  // _BULLCOWGAME_MAIN_H_