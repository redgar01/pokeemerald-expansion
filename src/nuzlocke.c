#if NUZLOCKE == TRUE
#include "global.h"
#include "nuzlocke.h"
#include "pokemon.h"

void initializeNuzlockSettings() {
    NUZLOCKE_SETTINGS.permadeath = TRUE;
    NUZLOCKE_SETTINGS.onlyFirstEncounter = TRUE;
    NUZLOCKE_SETTINGS.noItemsInBattle = TRUE;
    NUZLOCKE_SETTINGS.levelCaps = TRUE;
    NUZLOCKE_SETTINGS.noDuplicatesClause = TRUE;
    NUZLOCKE_SETTINGS.eggsAreEncounters = FALSE;
    NUZLOCKE_SETTINGS.giftedMonsAreEncounters = FALSE;
    NUZLOCKE_SETTINGS.autorelease = FALSE;
}

void setDeadFlag(void *pokemonPtr){

    if (NUZLOCKE_SETTINGS.permadeath){
        u8 fainted = TRUE;
        SetMonData((struct Pokemon*)pokemonPtr, MON_DATA_DEAD, &fainted);
    }
}

void setDeadFlagOnFeintedMons(){
    u8 i;
    if (NUZLOCKE_SETTINGS.permadeath){  
        for (i = 0; i < gPlayerPartyCount; i++){  
            if (GetMonData(&gPlayerParty[i], MON_DATA_HP, NULL) == 0){
                u8 fainted = TRUE;
                SetMonData(&gPlayerParty[i], MON_DATA_DEAD, &fainted);
            }
        }
    }
}

// u8 *getMapSecIdPointer(u8 mapSecId){
//     if (mapSecId > MAPSEC_NONE)
//         return NULL;
//     else 
//         return &gSaveBlock1Ptr->caughtLocationFlags[mapSecId / 8];
// }

// void setCaught(u8 mapSecId){
//     u8 *ptr = getMapSecIdPointer(mapSecId);
//     if (ptr)
//         *ptr |= 1 << (mapSecId & 7);
//     return;
// }

// void clearcaught(u8 mapSecId){
//     u8 *ptr = getMapSecIdPointer(mapSecId);
//     if (ptr)
//         *ptr &= ~(1 << (mapSecId & 7));
//     return;
// }

// u8 alreadyCaught(u8 mapSecId){
//     u8 *ptr = getMapSecIdPointer(mapSecId);

//     if (!ptr)
//         return FALSE;

//     if (!(((*ptr) >> (mapSecId & 7)) & 1))
//         return FALSE;

//     return TRUE;
// }

#endif

