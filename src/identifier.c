// ----------------------------------------------------------------
// ESPECIFICAÇÃO: O programa deve determinar se um identificador
// é ou não válido. Um identificador válido deve começar com uma
// letra e conter apenas letras ou dígitos. Além disto, deve ter
// no mínimo 1 caractere e no máximo 6 caracteres de comprimento
// ----------------------------------------------------------------

#include <stdio.h>
#include <string.h>
#include "identifier.h"

int valid_s(char ch) {
  if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')))
    return 1;
  else
    return 0;
}

int valid_f(char ch) {
  if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')) || ((ch >= '0') && (ch <= '9')))
    return 1;
  else
    return 0;
}

int identifier(char string[]) {
  int  length, valid_id, pos = 0;
  length = strlen(string);
  if (length == 0) {
	printf("Invalido\n");
    return 1;
  }

  valid_id = valid_s(string[pos++]);
  
  while(pos < length) {
    if (string[pos] == '\n') break;
    if(!(valid_f(string[pos]))) {
      valid_id = 0;
    }
    pos++;
  }
  
  if (valid_id && (length >= 1) && (length <= 6)) {
    printf("Valido\n");
    return 0;
  }
  else {
    printf("Invalido\n");
    return 1;
  }
}

