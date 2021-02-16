// SPDX-License-Identifier: GPL-3.0-only

#include <board/security.h>

static enum SecurityState security_state = SECURITY_STATE_LOCK;

enum SecurityState security_get(void) {
    return security_state;
}

void security_reset(void) {
    // Apply prepare states on CPU reset
    switch (security_state) {
        case SECURITY_STATE_PREPARE_LOCK:
            security_state = SECURITY_STATE_LOCK;
            break;
        case SECURITY_STATE_PREPARE_UNLOCK:
            security_state = SECURITY_STATE_UNLOCK;
            break;
    }
}

bool security_set(enum SecurityState state) {
    switch (state) {
        // Only allow setting the prepare states
        case SECURITY_STATE_PREPARE_LOCK:
        case SECURITY_STATE_PREPARE_UNLOCK:
            security_state = state;
            return true;
        // Any other states will be ignored
        default:
            return false;
    }
}
