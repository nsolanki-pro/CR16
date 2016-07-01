/* These are the first 16 entries of the default dispatch table as defined
   in the CompactRISC architecture:

Entry    Function
-----    --------
 0	NULL
 1	nmi
 2	NULL
 3	NULL
 4	NULL
 5	svc
 6	dvz
 7	flg
 8	bpt
 9	trc
10	und
11	NULL
12	iad
13	NULL
14	dbg
15	ise
*/

extern void (* const _dispatch_table[])(void);

/* Function prototypes */
void svc_handler(void);
void dvz_handler(void);
void flg_handler(void);
void und_handler(void);
void iad_handler(void);

