/*---------------------------------------------------------------------
 * Copyright (c) 2002 by National Semiconductor Corporation
 * All rights reserved.
 *<<<------------------------------------------------------------------
 * This file contains the default dispatch table definition.
 *---------------------------------------------------------------->>> */

#include "libstart.h"

#define NULL ((void*)0)

void (* const _dispatch_table[32])(void)=
{
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  svc_handler,
  dvz_handler,
  flg_handler,
  NULL,
  NULL,
  und_handler,
  NULL,
  iad_handler,
  NULL,
  NULL,
  NULL
};
