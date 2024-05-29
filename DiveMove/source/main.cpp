#include "syati.h"
#include "kamek/hooks.h"
#include "DiveMove.h"
bool isDive = false;

void checkIfDiveAllowed () {
    if (!MR::isOnGroundPlayer() && !isDive && MR::testSubPadTriggerC(0)) {
        MarioAccess::getPlayerActor()->mMario->trySquatJump();
        isDive = true;
    } else if (MR::isOnGroundPlayer() && isDive) 
        isDive = false; // Reset Dive
}

// Change Camera Reset Button to D-Pad Down
kmWrite32(0x8011E058, 0x4BF0C319); // bl MR::testCorePadTriggerDown()