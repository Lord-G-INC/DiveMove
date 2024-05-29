#include "syati.h"
#include "kamek/hooks.h"
bool isDive = false;

void checkIfDiveAllowed () {
    if (!MR::isOnGroundPlayer() && !isDive && MR::testSubPadTriggerC(0)) {
        MarioAccess::getPlayerActor()->mMario->trySquatJump();
        isDive = true;
    } else if (MR::isOnGroundPlayer() && isDive) 
        isDive = false; // Reset Dive
}
kmBranch(0x80388DA0, checkIfDiveAllowed);

// Change Camera Reset Button to D-Pad Down
kmWrite32(0x8011E058, 0x4BF0C319); // bl MR::testCorePadTriggerDown()