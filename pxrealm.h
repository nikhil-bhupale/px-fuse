#ifndef _PXREALM_H_
#define _PXREALM_H_

#include "pxmgr.h"

typedef long pxrealm_index_t;

struct pxrealm_properties {
        pxrealm_index_t id;

        struct block_device *cdev;
        sector_t offset;   // begin sector offset
        sector_t end;      // end sector offset
        sector_t nsectors; // number of sectors in this realm

        pxrealm_hint_t hint;
        uint64_t origin_size;
        uint64_t volume_id;
        void *context;
};

struct block_device *pxrealm_cache_device(void);
sector_t pxrealm_sector_offset(pxrealm_index_t id);
sector_t pxrealm_sector_end(pxrealm_index_t id);
sector_t pxrealm_sector_size(pxrealm_index_t id);

pxrealm_index_t pxrealm_lookup(uint64_t vol);
int pxrealm_properties(pxrealm_index_t, struct pxrealm_properties *);

pxrealm_index_t pxrealm_alloc(uint64_t volumeId, uint64_t origin_size,
                              pxrealm_hint_t hint, void *context);
int pxrealm_free(pxrealm_index_t);

int pxrealm_init(const char *cdevpath);
void pxrealm_exit(void);

void pxrealm_debug_dump(void);
#endif /* _PXREALM_H_ */