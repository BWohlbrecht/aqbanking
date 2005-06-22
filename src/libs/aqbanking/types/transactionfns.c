/***************************************************************************
 $RCSfile$
 -------------------
 cvs         : $Id$
 begin       : Mon Mar 01 2004
 copyright   : (C) 2004 by Martin Preuss
 email       : martin@libchipcard.de

 ***************************************************************************
 *          Please see toplevel file COPYING for license details           *
 ***************************************************************************/

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "transaction_p.h"
#include <aqbanking/transactionfns.h>
#include <gwenhywfar/bio_buffer.h>
#include <gwenhywfar/debug.h>




int AB_Transaction_Compare(const AB_TRANSACTION *t1,
                           const AB_TRANSACTION *t0) {
  if (t1==t0)
    return 0;

  if (t1 && t0) {
    GWEN_DB_NODE *dbT;
    GWEN_BUFFER *buf1;
    GWEN_BUFFER *buf0;

    buf1=GWEN_Buffer_new(0, 256, 0, 1);
    buf0=GWEN_Buffer_new(0, 256, 0, 1);

    /* prepare first buffer */
    dbT=GWEN_DB_Group_new("transaction");
    if (AB_Transaction_toDb(t1, dbT)==0) {
      GWEN_BUFFEREDIO *bio;
      GWEN_ERRORCODE err;

      /* remove variables from comparison */
      GWEN_DB_DeleteVar(dbT, "status");

      bio=GWEN_BufferedIO_Buffer2_new(buf1, 0);
      GWEN_BufferedIO_SetWriteBuffer(bio, 0, 256);
      if (GWEN_DB_WriteToStream(dbT, bio, GWEN_DB_FLAGS_COMPACT)) {
        DBG_ERROR(AQBANKING_LOGDOMAIN,
                  "INTERNAL: Error writing DB to stream");
        GWEN_BufferedIO_free(bio);
        GWEN_Buffer_free(buf0);
        GWEN_Buffer_free(buf1);
        GWEN_DB_Group_free(dbT);
        return -1;
      }
      err=GWEN_BufferedIO_Close(bio);
      if (!GWEN_Error_IsOk(err)) {
        DBG_ERROR_ERR(AQBANKING_LOGDOMAIN, err);
        GWEN_BufferedIO_free(bio);
        GWEN_Buffer_free(buf0);
        GWEN_Buffer_free(buf1);
        GWEN_DB_Group_free(dbT);
        return -1;
      }
      GWEN_BufferedIO_free(bio);
    }
    GWEN_DB_Group_free(dbT);
  
    /* prepare second buffer */
    dbT=GWEN_DB_Group_new("transaction");
    if (AB_Transaction_toDb(t0, dbT)==0) {
      GWEN_BUFFEREDIO *bio;
      GWEN_ERRORCODE err;
  
      /* remove variables from comparison */
      GWEN_DB_DeleteVar(dbT, "status");

      bio=GWEN_BufferedIO_Buffer2_new(buf0, 0);
      GWEN_BufferedIO_SetWriteBuffer(bio, 0, 256);
      if (GWEN_DB_WriteToStream(dbT, bio, GWEN_DB_FLAGS_COMPACT)) {
        DBG_ERROR(AQBANKING_LOGDOMAIN,
                  "INTERNAL: Error writing DB to stream");
        GWEN_BufferedIO_free(bio);
        GWEN_Buffer_free(buf0);
        GWEN_Buffer_free(buf1);
        GWEN_DB_Group_free(dbT);
        return -1;
      }
      err=GWEN_BufferedIO_Close(bio);
      if (!GWEN_Error_IsOk(err)) {
        DBG_ERROR_ERR(AQBANKING_LOGDOMAIN, err);
        GWEN_BufferedIO_free(bio);
        GWEN_Buffer_free(buf0);
        GWEN_Buffer_free(buf1);
        GWEN_DB_Group_free(dbT);
        return -1;
      }
      GWEN_BufferedIO_free(bio);
    }
    GWEN_DB_Group_free(dbT);
  
    /* actually compare */
    if (strcasecmp(GWEN_Buffer_GetStart(buf1),
                   GWEN_Buffer_GetStart(buf0))==0) {
      GWEN_Buffer_free(buf0);
      GWEN_Buffer_free(buf1);
      return 0;
    }
    GWEN_Buffer_free(buf0);
    GWEN_Buffer_free(buf1);
  }

  return 1;
}







