/*
 * (C) 2022, Cornell University
 * All rights reserved.
 */

/* Author: Yunhao Zhang
 * Description: the inode_store for accessing the physical disk
 */

#include "egos.h"
#include "disk.h"
#include "inode.h"

static int disk_getsize() { return FS_DISK_SIZE / BLOCK_SIZE; }

static int disk_setsize() { FATAL("disk: cannot set the size"); }

static int disk_read(inode_intf bs, int ino, block_no offset, block_t *block) {
    return earth->disk_read(GRASS_FS_START + offset, 1, block->bytes);
}

static int disk_write(inode_intf bs, int ino, block_no offset, block_t *block) {
    return earth->disk_write(GRASS_FS_START + offset, 1, block->bytes);
}

static inode_store_t disk;

inode_intf fs_disk_init() {
    disk.read = (void*)disk_read;
    disk.write = (void*)disk_write;
    disk.getsize = (void*)disk_getsize;
    disk.setsize = (void*)disk_setsize;

    return &disk;
}
