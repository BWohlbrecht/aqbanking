/* This file is auto-generated from "tanmethod.xml" by the typemaker
   tool of Gwenhywfar. 
   Do not edit this file -- all changes will be lost! */
#ifndef TANMETHOD_P_H
#define TANMETHOD_P_H

#include "tanmethod_l.h"


struct AH_TAN_METHOD {
  GWEN_INHERIT_ELEMENT(AH_TAN_METHOD)
  GWEN_LIST_ELEMENT(AH_TAN_METHOD)
  int _usage;
  int _modified;

  int function;
  int process;
  char *methodId;
  char *methodName;
  char *zkaTanName;
  char *zkaTanVersion;
  int tanMaxLen;
  char *formatId;
  char *prompt;
  int returnMaxLen;
  int maxActiveLists;
  int multiTanAllowed;
  int timeShiftAllowed;
  int tanListMode;
  int stornoAllowed;
  int needSmsAccount;
  int needLocalAccount;
  int needChallengeClass;
  int needChallengeAmount;
  int challengeIsStructured;
  int initMode;
  int needTanMediumId;
  int maxActiveTanMedia;
  int gvVersion;
};




























#endif /* TANMETHOD_P_H */
