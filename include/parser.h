#ifndef PARSER_H
#define PARSER_H

int symbolLoop(char* input);

void analyzeSymbol(char input);

struct vector fragmentSymbols(char* input);

int isBracket(char input);

int isSpace(char input);

char* charToString(char input);

#endif /* PARSER_H */
