#include "server.h"

#define OBJ_NO_FLAGS 0
#define OBJ_SET_NX (1 << 0)   /* Set if key not exists. */
#define OBJ_SET_XX (1 << 1)   /* Set if key exists. */
#define OBJ_EX (1 << 2)       /* Set if time in seconds is given */
#define OBJ_PX (1 << 3)       /* Set if time in ms in given */
#define OBJ_KEEPTTL (1 << 4)  /* Set and keep the ttl */
#define OBJ_SET_GET (1 << 5)  /* Set if want to get key before set */
#define OBJ_EXAT (1 << 6)     /* Set if timestamp in second is given */
#define OBJ_PXAT (1 << 7)     /* Set if timestamp in ms is given */
#define OBJ_PERSIST (1 << 8)  /* Set if we need to remove the ttl */
#define OBJ_IFEQ (1 << 9) /* Set if we need compare and set */
#define OBJ_ARGV3 (1 << 10)   /* Set if the value is at argv[3]; otherwise it's \
                               * at argv[2]. */

#define COMMAND_GET 0
#define COMMAND_SET 1
#define COMMAND_DEL 2

int parseExtendedStringArgumentsOrReply(client *c, int *flags, int *unit, robj **expire, robj **compare_val, int command_type);
