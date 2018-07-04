/**
   ciphersuites.c


   Copyright (C) 1999-2000 RTFM, Inc.
   All Rights Reserved

   This package is a SSLv3/TLS protocol analyzer written by Eric Rescorla
   <ekr@rtfm.com> and licensed by RTFM, Inc.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:
   1. Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
   2. Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
   3. All advertising materials mentioning features or use of this software
      must display the following acknowledgement:
   
      This product includes software developed by Eric Rescorla for
      RTFM, Inc.

   4. Neither the name of RTFM, Inc. nor the name of Eric Rescorla may be
      used to endorse or promote products derived from this
      software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY ERIC RESCORLA AND RTFM, INC. ``AS IS'' AND
   ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
   FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
   DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
   OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
   HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
   OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY SUCH DAMAGE.

   $Id: ciphersuites.c,v 1.3 2002/08/17 01:33:17 ekr Exp $


   ekr@rtfm.com  Tue Mar 30 17:19:56 1999
 */


static char *RCSSTRING="$Id: ciphersuites.c,v 1.3 2002/08/17 01:33:17 ekr Exp $";

#include <r_common.h>

#include "sslciphers.h"

static SSL_CipherSuite CipherSuites[]={
     {1,KEX_RSA,SIG_RSA,ENC_NULL,0,0,0,DIG_MD5,16,0},
     {2,KEX_RSA,SIG_RSA,ENC_NULL,0,0,0,DIG_SHA,20,0},
     {3,KEX_RSA,SIG_RSA,ENC_RC4,1,128,40,DIG_MD5,16,1},
     {4,KEX_RSA,SIG_RSA,ENC_RC4,1,128,128,DIG_MD5,16,0},
     {5,KEX_RSA,SIG_RSA,ENC_RC4,1,128,128,DIG_SHA,20,0},
     {6,KEX_RSA,SIG_RSA,ENC_RC2,8,128,40,DIG_SHA,20,1},
     {7,KEX_RSA,SIG_RSA,ENC_IDEA,8,128,128,DIG_SHA,20,0},
     {8,KEX_RSA,SIG_RSA,ENC_DES,8,64,40,DIG_SHA,20,1},
     {9,KEX_RSA,SIG_RSA,ENC_DES,8,64,64,DIG_SHA,20,0},
     {10,KEX_RSA,SIG_RSA,ENC_3DES,8,192,192,DIG_SHA,20,0},
     {11,KEX_DH,SIG_DSS,ENC_DES,8,64,40,DIG_SHA,20,1},
     {12,KEX_DH,SIG_DSS,ENC_DES,8,64,64,DIG_SHA,20,0},
     {13,KEX_DH,SIG_DSS,ENC_3DES,8,192,192,DIG_SHA,20,0},
     {14,KEX_DH,SIG_RSA,ENC_DES,8,64,40,DIG_SHA,20,1},
     {15,KEX_DH,SIG_RSA,ENC_DES,8,64,64,DIG_SHA,20,0},
     {16,KEX_DH,SIG_RSA,ENC_3DES,8,192,192,DIG_SHA,20,0},
     {17,KEX_DH,SIG_DSS,ENC_DES,8,64,40,DIG_SHA,20,1},
     {18,KEX_DH,SIG_DSS,ENC_DES,8,64,64,DIG_SHA,20,0},
     {19,KEX_DH,SIG_DSS,ENC_3DES,8,192,192,DIG_SHA,20,0},
     {20,KEX_DH,SIG_RSA,ENC_DES,8,64,40,DIG_SHA,20,1},
     {21,KEX_DH,SIG_RSA,ENC_DES,8,64,64,DIG_SHA,20,0},
     {22,KEX_DH,SIG_RSA,ENC_3DES,8,192,192,DIG_SHA,20,0},
     {23,KEX_DH,SIG_NONE,ENC_RC4,1,128,40,DIG_MD5,16,1},
     {24,KEX_DH,SIG_NONE,ENC_RC4,1,128,128,DIG_MD5,16,0},
     {25,KEX_DH,SIG_NONE,ENC_DES,8,64,40,DIG_MD5,16,1},
     {26,KEX_DH,SIG_NONE,ENC_DES,8,64,64,DIG_MD5,16,0},
     {27,KEX_DH,SIG_NONE,ENC_3DES,8,192,192,DIG_MD5,16,0},
     // Missing: 44-46
     {47,KEX_RSA,SIG_RSA,ENC_AES128,16,128,128,DIG_SHA,20,0},
     {48,KEX_DH,SIG_DSS,ENC_AES128,16,128,128,DIG_SHA,20,0},
     {49,KEX_DH,SIG_RSA,ENC_AES128,16,128,128,DIG_SHA,20,0},
     {50,KEX_DH,SIG_DSS,ENC_AES128,16,128,128,DIG_SHA,20,0},
     {51,KEX_DH,SIG_RSA,ENC_AES128,16,128,128,DIG_SHA,20,0},
     {52,KEX_DH,SIG_NONE,ENC_AES128,16,128,128,DIG_SHA,20,0},
     {53,KEX_RSA,SIG_RSA,ENC_AES256,16,256,256,DIG_SHA,20,0},
     {54,KEX_DH,SIG_DSS,ENC_AES256,16,256,256,DIG_SHA,20,0},
     {55,KEX_DH,SIG_RSA,ENC_AES256,16,256,256,DIG_SHA,20,0},
     {56,KEX_DH,SIG_DSS,ENC_AES256,16,256,256,DIG_SHA,20,0},
     {57,KEX_DH,SIG_RSA,ENC_AES256,16,256,256,DIG_SHA,20,0},
     {58,KEX_DH,SIG_NONE,ENC_AES256,16,256,256,DIG_SHA,20,0},
     {59,KEX_RSA,SIG_RSA,ENC_NULL,0,0,0,DIG_SHA256,32,0},
     {60,KEX_RSA,SIG_RSA,ENC_AES128,16,128,128,DIG_SHA256,32,0},
     {61,KEX_RSA,SIG_RSA,ENC_AES256,16,256,256,DIG_SHA256,32,0},
     {62,KEX_DH,SIG_DSS,ENC_AES128,16,128,128,DIG_SHA256,32,0},
     {63,KEX_DH,SIG_RSA,ENC_AES128,16,128,128,DIG_SHA256,32,0},
     {64,KEX_DH,SIG_DSS,ENC_AES128,16,128,128,DIG_SHA256,32,0},
     {65,KEX_RSA,SIG_RSA,ENC_CAMELLIA128,16,128,128,DIG_SHA,20,0},
     {66,KEX_DH,SIG_DSS,ENC_CAMELLIA128,16,128,128,DIG_SHA,20,0},
     {67,KEX_DH,SIG_RSA,ENC_CAMELLIA128,16,128,128,DIG_SHA,20,0},
     {68,KEX_DH,SIG_DSS,ENC_CAMELLIA128,16,128,128,DIG_SHA,20,0},
     {69,KEX_DH,SIG_RSA,ENC_CAMELLIA128,16,128,128,DIG_SHA,20,0},
     {70,KEX_DH,SIG_NONE,ENC_CAMELLIA128,16,128,128,DIG_SHA,20,0},
     {96,KEX_RSA,SIG_RSA,ENC_RC4,1,128,56,DIG_MD5,16,1},
     {97,KEX_RSA,SIG_RSA,ENC_RC2,1,128,56,DIG_MD5,16,1},
     {98,KEX_RSA,SIG_RSA,ENC_DES,8,64,64,DIG_SHA,20,1},
     {99,KEX_DH,SIG_DSS,ENC_DES,8,64,64,DIG_SHA,20,1},
     {100,KEX_RSA,SIG_RSA,ENC_RC4,1,128,56,DIG_SHA,20,1},
     {101,KEX_DH,SIG_DSS,ENC_RC4,1,128,56,DIG_SHA,20,1},
     {102,KEX_DH,SIG_DSS,ENC_RC4,1,128,128,DIG_SHA,20,0},
     {103,KEX_DH,SIG_RSA,ENC_AES128,16,128,128,DIG_SHA256,32,0},
     {104,KEX_DH,SIG_DSS,ENC_AES256,16,256,256,DIG_SHA256,32,0},
     {105,KEX_DH,SIG_RSA,ENC_AES256,16,256,256,DIG_SHA256,32,0},
     {106,KEX_DH,SIG_DSS,ENC_AES256,16,256,256,DIG_SHA256,32,0},
     {107,KEX_DH,SIG_RSA,ENC_AES256,16,256,256,DIG_SHA256,32,0},
     {108,KEX_DH,SIG_NONE,ENC_AES128,16,128,128,DIG_SHA256,32,0},
     {109,KEX_DH,SIG_NONE,ENC_AES256,16,256,256,DIG_SHA256,32,0},
     {132,KEX_RSA,SIG_RSA,ENC_CAMELLIA256,16,256,256,DIG_SHA,20,0},
     {133,KEX_DH,SIG_DSS,ENC_CAMELLIA256,16,256,256,DIG_SHA,20,0},
     {134,KEX_DH,SIG_RSA,ENC_CAMELLIA256,16,256,256,DIG_SHA,20,0},
     {135,KEX_DH,SIG_DSS,ENC_CAMELLIA256,16,256,256,DIG_SHA,20,0},
     {136,KEX_DH,SIG_RSA,ENC_CAMELLIA256,16,256,256,DIG_SHA,20,0},
     {137,KEX_DH,SIG_NONE,ENC_CAMELLIA256,16,256,256,DIG_SHA,20,0},
     // Missing: 138-149
     {150,KEX_RSA,SIG_RSA,ENC_SEED,16,128,128,DIG_SHA,20,0},
     {151,KEX_DH,SIG_DSS,ENC_SEED,16,128,128,DIG_SHA,20,0},
     {152,KEX_DH,SIG_RSA,ENC_SEED,16,128,128,DIG_SHA,20,0},
     {153,KEX_DH,SIG_DSS,ENC_SEED,16,128,128,DIG_SHA,20,0},
     {154,KEX_DH,SIG_RSA,ENC_SEED,16,128,128,DIG_SHA,20,0},
     {155,KEX_DH,SIG_NONE,ENC_SEED,16,128,128,DIG_SHA,20,0},
     {156,KEX_RSA,SIG_RSA,ENC_AES128_GCM,4,128,128,DIG_SHA256,32,0},
     {157,KEX_RSA,SIG_RSA,ENC_AES256_GCM,4,256,256,DIG_SHA384,48,0},
     {158,KEX_DH,SIG_RSA,ENC_AES128_GCM,4,128,128,DIG_SHA256,32,0},
     {159,KEX_DH,SIG_RSA,ENC_AES256_GCM,4,256,256,DIG_SHA384,48,0},
     {160,KEX_DH,SIG_RSA,ENC_AES128_GCM,4,128,128,DIG_SHA256,32,0},
     {161,KEX_DH,SIG_RSA,ENC_AES256_GCM,4,256,256,DIG_SHA384,48,0},
     {162,KEX_DH,SIG_DSS,ENC_AES128_GCM,4,128,128,DIG_SHA256,32,0},
     {163,KEX_DH,SIG_DSS,ENC_AES256_GCM,4,256,256,DIG_SHA384,48,0},
     {164,KEX_DH,SIG_DSS,ENC_AES128_GCM,4,128,128,DIG_SHA256,32,0},
     {165,KEX_DH,SIG_DSS,ENC_AES256_GCM,4,256,256,DIG_SHA384,48,0},
     {166,KEX_DH,SIG_NONE,ENC_AES128_GCM,4,128,128,DIG_SHA256,32,0},
     {167,KEX_DH,SIG_NONE,ENC_AES256_GCM,4,256,256,DIG_SHA384,48,0},
     // Missing: 168-185
     {186,KEX_RSA,SIG_RSA,ENC_CAMELLIA128,16,128,128,DIG_SHA256,32,0},
     {187,KEX_DH,SIG_DSS,ENC_CAMELLIA128,16,128,128,DIG_SHA256,32,0},
     {188,KEX_DH,SIG_RSA,ENC_CAMELLIA128,16,128,128,DIG_SHA256,32,0},
     {189,KEX_DH,SIG_DSS,ENC_CAMELLIA128,16,128,128,DIG_SHA256,32,0},
     {190,KEX_DH,SIG_RSA,ENC_CAMELLIA128,16,128,128,DIG_SHA256,32,0},
     {191,KEX_DH,SIG_NONE,ENC_CAMELLIA128,16,128,128,DIG_SHA256,32,0},
     {192,KEX_RSA,SIG_RSA,ENC_CAMELLIA256,16,256,256,DIG_SHA256,32,0},
     {193,KEX_DH,SIG_DSS,ENC_CAMELLIA256,16,256,256,DIG_SHA256,32,0},
     {194,KEX_DH,SIG_RSA,ENC_CAMELLIA256,16,256,256,DIG_SHA256,32,0},
     {195,KEX_DH,SIG_DSS,ENC_CAMELLIA256,16,256,256,DIG_SHA256,32,0},
     {196,KEX_DH,SIG_RSA,ENC_CAMELLIA256,16,256,256,DIG_SHA256,32,0},
     {197,KEX_DH,SIG_NONE,ENC_CAMELLIA256,16,256,256,DIG_SHA256,32,0},
     {49153,KEX_DH,SIG_DSS,ENC_NULL,0,0,0,DIG_SHA,20,0},
     {49154,KEX_DH,SIG_DSS,ENC_RC4,1,128,128,DIG_SHA,20,0},
     {49155,KEX_DH,SIG_DSS,ENC_3DES,8,192,192,DIG_SHA,20,0},
     {49156,KEX_DH,SIG_DSS,ENC_AES128,16,128,128,DIG_SHA,20,0},
     {49157,KEX_DH,SIG_DSS,ENC_AES256,16,256,256,DIG_SHA,20,0},
     {49158,KEX_DH,SIG_DSS,ENC_NULL,0,0,0,DIG_SHA,20,0},
     {49159,KEX_DH,SIG_DSS,ENC_RC4,1,128,128,DIG_SHA,20,0},
     {49160,KEX_DH,SIG_DSS,ENC_3DES,8,192,192,DIG_SHA,20,0},
     {49161,KEX_DH,SIG_DSS,ENC_AES128,16,128,128,DIG_SHA,20,0},
     {49162,KEX_DH,SIG_DSS,ENC_AES256,16,256,256,DIG_SHA,20,0},
     {49163,KEX_DH,SIG_RSA,ENC_NULL,0,0,0,DIG_SHA,20,0},
     {49164,KEX_DH,SIG_RSA,ENC_RC4,1,128,128,DIG_SHA,20,0},
     {49165,KEX_DH,SIG_RSA,ENC_3DES,8,192,192,DIG_SHA,20,0},
     {49166,KEX_DH,SIG_RSA,ENC_AES128,16,128,128,DIG_SHA,20,0},
     {49167,KEX_DH,SIG_RSA,ENC_AES256,16,256,256,DIG_SHA,20,0},
     {49168,KEX_DH,SIG_RSA,ENC_NULL,0,0,0,DIG_SHA,20,0},
     {49169,KEX_DH,SIG_RSA,ENC_RC4,1,128,128,DIG_SHA,20,0},
     {49170,KEX_DH,SIG_RSA,ENC_3DES,8,192,192,DIG_SHA,20,0},
     {49171,KEX_DH,SIG_RSA,ENC_AES128,16,128,128,DIG_SHA,20,0},
     {49172,KEX_DH,SIG_RSA,ENC_AES256,16,256,256,DIG_SHA,20,0},
     {49173,KEX_DH,SIG_NONE,ENC_NULL,0,0,0,DIG_SHA,20,0},
     {49174,KEX_DH,SIG_NONE,ENC_RC4,1,128,128,DIG_SHA,20,0},
     {49175,KEX_DH,SIG_NONE,ENC_3DES,8,192,192,DIG_SHA,20,0},
     {49176,KEX_DH,SIG_NONE,ENC_AES128,16,128,128,DIG_SHA,20,0},
     {49177,KEX_DH,SIG_NONE,ENC_AES256,16,256,256,DIG_SHA,20,0},
     {49187,KEX_DH,SIG_DSS,ENC_AES128,16,128,128,DIG_SHA256,32,0},
     {49188,KEX_DH,SIG_DSS,ENC_AES256,16,256,256,DIG_SHA384,48,0},
     {49189,KEX_DH,SIG_DSS,ENC_AES128,16,128,128,DIG_SHA256,32,0},
     {49190,KEX_DH,SIG_DSS,ENC_AES256,16,256,256,DIG_SHA384,48,0},
     {49191,KEX_DH,SIG_RSA,ENC_AES128,16,128,128,DIG_SHA256,32,0},
     {49192,KEX_DH,SIG_RSA,ENC_AES256,16,256,256,DIG_SHA384,48,0},
     {49193,KEX_DH,SIG_RSA,ENC_AES128,16,128,128,DIG_SHA256,32,0},
     {49194,KEX_DH,SIG_RSA,ENC_AES256,16,256,256,DIG_SHA384,48,0},
     {49195,KEX_DH,SIG_DSS,ENC_AES128_GCM,4,128,128,DIG_SHA256,32,0},
     {49196,KEX_DH,SIG_DSS,ENC_AES256_GCM,4,256,256,DIG_SHA384,48,0},
     {49197,KEX_DH,SIG_DSS,ENC_AES128_GCM,4,128,128,DIG_SHA256,32,0},
     {49198,KEX_DH,SIG_DSS,ENC_AES256_GCM,4,256,256,DIG_SHA384,48,0},
     {49199,KEX_DH,SIG_RSA,ENC_AES128_GCM,4,128,128,DIG_SHA256,32,0},
     {49200,KEX_DH,SIG_RSA,ENC_AES256_GCM,4,256,256,DIG_SHA384,48,0},
     {49201,KEX_DH,SIG_RSA,ENC_AES128_GCM,4,128,128,DIG_SHA256,32,0},
     {49202,KEX_DH,SIG_RSA,ENC_AES256_GCM,4,256,256,DIG_SHA384,48,0},
     // Missing: 49203-49211
     {49266,KEX_DH,SIG_DSS,ENC_CAMELLIA128,16,128,128,DIG_SHA256,32,0},
     {49267,KEX_DH,SIG_DSS,ENC_CAMELLIA256,16,256,256,DIG_SHA256,48,0},
     {49268,KEX_DH,SIG_DSS,ENC_CAMELLIA128,16,128,128,DIG_SHA256,32,0},
     {49269,KEX_DH,SIG_DSS,ENC_CAMELLIA256,16,256,256,DIG_SHA256,48,0},
     {49270,KEX_DH,SIG_RSA,ENC_CAMELLIA128,16,128,128,DIG_SHA256,32,0},
     {49271,KEX_DH,SIG_RSA,ENC_CAMELLIA256,16,256,256,DIG_SHA256,48,0},
     {49272,KEX_DH,SIG_RSA,ENC_CAMELLIA128,16,128,128,DIG_SHA256,32,0},
     {49273,KEX_DH,SIG_RSA,ENC_CAMELLIA256,16,256,256,DIG_SHA256,48,0},
     {49274,KEX_RSA,SIG_RSA,ENC_CAMELLIA128,4,128,128,DIG_SHA256,32,0},
     {49275,KEX_RSA,SIG_RSA,ENC_CAMELLIA256,4,256,256,DIG_SHA384,48,0},
     {49276,KEX_DH,SIG_RSA,ENC_CAMELLIA128,4,128,128,DIG_SHA256,32,0},
     {49277,KEX_DH,SIG_RSA,ENC_CAMELLIA256,4,256,256,DIG_SHA384,48,0},
     {49278,KEX_DH,SIG_RSA,ENC_CAMELLIA128,4,128,128,DIG_SHA256,32,0},
     {49279,KEX_DH,SIG_RSA,ENC_CAMELLIA256,4,256,256,DIG_SHA384,48,0},
     {49280,KEX_DH,SIG_DSS,ENC_CAMELLIA128,4,128,128,DIG_SHA256,32,0},
     {49281,KEX_DH,SIG_DSS,ENC_CAMELLIA256,4,256,256,DIG_SHA384,48,0},
     {49282,KEX_DH,SIG_DSS,ENC_CAMELLIA128,4,128,128,DIG_SHA256,32,0},
     {49283,KEX_DH,SIG_DSS,ENC_CAMELLIA256,4,256,256,DIG_SHA384,48,0},
     {49284,KEX_DH,SIG_NONE,ENC_CAMELLIA128,4,128,128,DIG_SHA256,32,0},
     {49285,KEX_DH,SIG_NONE,ENC_CAMELLIA256,4,256,256,DIG_SHA384,48,0},
     {49286,KEX_DH,SIG_DSS,ENC_CAMELLIA128,4,128,128,DIG_SHA256,32,0},
     {49287,KEX_DH,SIG_DSS,ENC_CAMELLIA256,4,256,256,DIG_SHA384,48,0},
     {49288,KEX_DH,SIG_DSS,ENC_CAMELLIA128,4,128,128,DIG_SHA256,32,0},
     {49289,KEX_DH,SIG_DSS,ENC_CAMELLIA256,4,256,256,DIG_SHA384,48,0},
     {49290,KEX_DH,SIG_RSA,ENC_CAMELLIA128,4,128,128,DIG_SHA256,32,0},
     {49291,KEX_DH,SIG_RSA,ENC_CAMELLIA256,4,256,256,DIG_SHA384,48,0},
     {49292,KEX_DH,SIG_RSA,ENC_CAMELLIA128,4,128,128,DIG_SHA256,32,0},
     {49293,KEX_DH,SIG_RSA,ENC_CAMELLIA256,4,256,256,DIG_SHA384,48,0},
     // Missing: 49294-49307
     {-1}
};

int ssl_find_cipher(num,cs)
  int num;
  SSL_CipherSuite **cs;
  {
    SSL_CipherSuite *c;

    for(c=CipherSuites;c->number!=-1;c++){
      if(c->number==num){
	*cs=c;
	return(0);
      }
    }

    ERETURN(R_NOT_FOUND);
  }
  
     
