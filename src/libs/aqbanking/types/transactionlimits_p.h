/* This file is auto-generated from "transactionlimits.xml" by the typemaker
   tool of Gwenhywfar. 
   Do not edit this file -- all changes will be lost! */
#ifndef TRANSACTIONLIMITS_P_H
#define TRANSACTIONLIMITS_P_H

#include "transactionlimits_l.h"


struct AB_TRANSACTION_LIMITS {
  GWEN_LIST_ELEMENT(AB_TRANSACTION_LIMITS)
  int _usage;
  int _modified;

  int maxLenLocalName;
  int minLenLocalName;
  int maxLenRemoteName;
  int minLenRemoteName;
  int maxLinesRemoteName;
  int minLinesRemoteName;
  int maxLenLocalBankCode;
  int minLenLocalBankCode;
  int maxLenLocalAccountNumber;
  int minLenLocalAccountNumber;
  int maxLenLocalSuffix;
  int minLenLocalSuffix;
  int maxLenRemoteBankCode;
  int minLenRemoteBankCode;
  int maxLenRemoteAccountNumber;
  int minLenRemoteAccountNumber;
  int maxLenRemoteSuffix;
  int minLenRemoteSuffix;
  int maxLenRemoteIban;
  int minLenRemoteIban;
  int maxLenTextKey;
  int minLenTextKey;
  GWEN_STRINGLIST *valuesTextKey;
  AB_TEXTKEY_DESCR_LIST *textKeys;
  int maxLenCustomerReference;
  int minLenCustomerReference;
  int maxLenBankReference;
  int minLenBankReference;
  int maxLenPurpose;
  int minLenPurpose;
  int maxLinesPurpose;
  int minLinesPurpose;
  int needDate;
  int minValueSetupTime;
  int maxValueSetupTime;
  int minValueSetupTimeFirst;
  int maxValueSetupTimeFirst;
  int minValueSetupTimeOnce;
  int maxValueSetupTimeOnce;
  int minValueSetupTimeRecurring;
  int maxValueSetupTimeRecurring;
  int minValueSetupTimeFinal;
  int maxValueSetupTimeFinal;
  GWEN_STRINGLIST *valuesCycleWeek;
  GWEN_STRINGLIST *valuesCycleMonth;
  GWEN_STRINGLIST *valuesExecutionDayWeek;
  GWEN_STRINGLIST *valuesExecutionDayMonth;
  int allowMonthly;
  int allowWeekly;
  int allowChangeRecipientAccount;
  int allowChangeRecipientName;
  int allowChangeValue;
  int allowChangeTextKey;
  int allowChangePurpose;
  int allowChangeFirstExecutionDate;
  int allowChangeLastExecutionDate;
  int allowChangeCycle;
  int allowChangePeriod;
  int allowChangeExecutionDay;
};



/** @name Issuer Name
 *
Limits for the issuer name.*/
/*@{*/



/*@}*/

/** @name Payee Name
 *
Limits for the payee name.*/
/*@{*/





/*@}*/

/** @name Local Bank Code
 *
Limits for local bank code.*/
/*@{*/



/*@}*/

/** @name Local Account Id
 *
Limits for local account id.*/
/*@{*/



/*@}*/

/** @name Local Account Number
 *
Limits for local account id suffix.*/
/*@{*/



/*@}*/

/** @name Remote Bank Code
 *
Limits for remote bank code.*/
/*@{*/



/*@}*/

/** @name Remote Account Number
 *
Limits for remote account number.*/
/*@{*/



/*@}*/

/** @name Remote Account Number Suffix
 *
Limits for remote account id suffix.*/
/*@{*/



/*@}*/

/** @name Remote IBAN
 *
Limits for remote IAN.*/
/*@{*/



/*@}*/

/** @name Text Key
 *
Limits for textKey.*/
/*@{*/





/*@}*/

/** @name Customer Reference
 *
Limits for customer reference.*/
/*@{*/



/*@}*/

/** @name Bank Reference
 *
Limits for bank reference.*/
/*@{*/



/*@}*/

/** @name Purpose
 *
Limits for purpose (called
<i>memo</i>
in some apps).*/
/*@{*/





/*@}*/

/** @name Date
 *
Limits for date.*/
/*@{*/


/*@}*/

/** @name Standing Orders And Dated Transfer
 *
These limits apply to standing orders and dated transfers only.*/
/*@{*/



























/*@}*/


#endif /* TRANSACTIONLIMITS_P_H */
