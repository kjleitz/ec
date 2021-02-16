
// SPDX-License-Identifier: GPL-3.0-only

#ifndef _BOARD_SECURITY_H
#define _BOARD_SECURITY_H

#include <stdbool.h>
#include <common/command.h>

enum SecurityState security_get(void);
void security_reset(void);
bool security_set(enum SecurityState state);

#endif // _BOARD_SECURITY_H
