#pragma once


#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 4.0f, FColor::Magenta, TEXT(text),false);
#define printf(Format, ...) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 4.0f, FColor::Magenta, FString::Printf(TEXT(Format),##__VA_ARGS__),false);

