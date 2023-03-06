#ifndef GUARD_NUZLOCKE_H
#define GUARD_NUZLOCKE_H

#include "constants/region_map_sections.h"
#include "global.h"

#define NUZLOCKE_BLOCK gSaveBlock2Ptr->nuzlockeBlock
#define NUZLOCKE_SETTINGS NUZLOCKE_BLOCK.settings

// Settings Flags
struct NuzlockeSettings{
    // Basic Nuzlocke Rules
    u8 permadeath:1;
    u8 onlyFirstEncounter:1;
    
    // Hardcore Nuzlocke Rules
    u8 noItemsInBattle:1;
    u8 levelCaps:1;

    // Clauses & Configs
    u8 noDuplicatesClause:1;
    u8 eggsAreEncounters:1;
    u8 giftedMonsAreEncounters:1;
    u8 autorelease:1;
};

struct NuzlockeBlock{
    struct NuzlockeSettings settings;
    u8 firstEncounterFlags[ROUND_BITS_TO_BYTES(MAPSEC_NONE)];
};

// u8 LevelcapHandicap;
// u8 StatEqualizationLevel;

// Macros



// Functions
void initializeNuzlockSettings();
void setDeadFlag(void *pokemonPtr);
void setDeadFlagOnFeintedMons();

// u8 *getMapSecIdPointer(u8 mapSecId);
// void setCaught(u8 mapSecId);
// void clearcaught(u8 mapSecId);
// u8 alreadyCaught(u8 mapSecId);


#endif // GUARD_NUZLOCKE_H