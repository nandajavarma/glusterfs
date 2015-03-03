/*
  Copyright (c) 2014 Red Hat, Inc. <http://www.redhat.com>
  This file is part of GlusterFS.

  This file is licensed to you under your choice of the GNU Lesser
  General Public License, version 3 or any later version (LGPLv3 or
  later), or the GNU General Public License, version 2 (GPLv2), in all
  cases as published by the Free Software Foundation.
*/

#ifndef _GLUSTERD_MESSAGES_H_
#define _GLUSTERD_MESSAGES_H_

#ifndef _CONFIG_H
#define _CONFIG_H
#include "config.h"
#endif

#include "glfs-message-id.h"

/*! \file glusterd-messages.h
 *  \brief Glusterd log-message IDs and their descriptions
 */

/* NOTE: Rules for message additions
 * 1) Each instance of a message is _better_ left with a unique message ID, even
 *    if the message format is the same. Reasoning is that, if the message
 *    format needs to change in one instance, the other instances are not
 *    impacted or the new change does not change the ID of the instance being
 *    modified.
 * 2) Addition of a message,
 *       - Should increment the GLFS_NUM_MESSAGES
 *       - Append to the list of messages defined, towards the end
 *       - Retain macro naming as glfs_msg_X (for redability across developers)
 * NOTE: Rules for message format modifications
 * 3) Check acorss the code if the message ID macro in question is reused
 *    anywhere. If reused then then the modifications should ensure correctness
 *    everywhere, or needs a new message ID as (1) above was not adhered to. If
 *    not used anywhere, proceed with the required modification.
 * NOTE: Rules for message deletion
 * 4) Check (3) and if used anywhere else, then cannot be deleted. If not used
 *    anywhere, then can be deleted, but will leave a hole by design, as
 *    addition rules specify modification to the end of the list and not filling
 *    holes.
 */

#define GLUSTERD_COMP_BASE      GLFS_MSGID_GLUSTERD
#define GLFS_NUM_MESSAGES       93
#define GLFS_MSGID_END          (GLUSTERD_COMP_BASE + GLFS_NUM_MESSAGES + 1)
/* Messaged with message IDs */
#define glfs_msg_start_x GLFS_COMP_BASE, "Invalid: Start of messages"
/*------------*/

/*!
 * @messageid 106001
 * @diagnosis Operation could not be performed because the server quorum was not
 *            met
 * @recommendedaction Ensure that other peer nodes are online and reachable from
 *                    the local peer node
 */
#define GD_MSG_SERVER_QUORUM_NOT_MET (GLUSTERD_COMP_BASE + 1)

/*!
 * @messageid 106002
 * @diagnosis The local bricks belonging to the volume were killed because
 *            the server-quorum was not met
 * @recommendedaction Ensure that other peer nodes are online and reachable from
 *                    the local peer node
 */
#define GD_MSG_SERVER_QUORUM_LOST_STOPPING_BRICKS (GLUSTERD_COMP_BASE + 2)

/*!
 * @messageid 106003
 * @diagnosis The local bricks belonging to the named volume were (re)started
 *            because the server-quorum was met
 * @recommendedaction  None
 */
#define GD_MSG_SERVER_QUORUM_MET_STARTING_BRICKS (GLUSTERD_COMP_BASE + 3)

/*!
 * @messageid 106004
 * @diagnosis Glusterd on the peer might be down or unreachable
 * @recommendedaction  Check if glusterd is running on the peer node or if
 *                     the firewall rules are not blocking port 24007
 */
#define GD_MSG_PEER_DISCONNECTED (GLUSTERD_COMP_BASE + 4)

/*!
 * @messageid 106005
 * @diagnosis Brick process might be down
 * @recommendedaction Check brick log files to get more information on the cause
 *                    for the brick's offline status. To bring the brick back
 *                    online,run gluster volume start <VOLNAME> force
 */
#define GD_MSG_BRICK_DISCONNECTED (GLUSTERD_COMP_BASE + 5)

/*!
 * @messageid 106006
 * @diagnosis NFS Server or Self-heal daemon might be down
 * @recommendedaction Check nfs or self-heal daemon log files to get more
 *                    information on the cause for the brick's offline status.
 *                    To bring the brick back online, run gluster volume
 *                    start <VOLNAME> force
 */
#define GD_MSG_NODE_DISCONNECTED (GLUSTERD_COMP_BASE + 6)

/*!
 * @messageid 106007
 * @diagnosis Rebalance process might be down
 * @recommendedaction None
 */
#define GD_MSG_REBALANCE_DISCONNECTED (GLUSTERD_COMP_BASE + 7)

/*!
 * @messageid 106008
 * @diagnosis Volume cleanup failed
 * @recommendedaction None
 */
#define GD_MSG_VOL_CLEANUP_FAIL (GLUSTERD_COMP_BASE + 8)

/*!
 * @messageid 106009
 * @diagnosis Volume version mismatch while adding a peer
 * @recommendedaction None
 */
#define GD_MSG_VOL_VERS_MISMATCH (GLUSTERD_COMP_BASE + 9)

/*!
 * @messageid 106010
 * @diagnosis Volume checksum mismatch while adding a peer
 * @recommendedaction Check for which node the checksum mismatch happens
 *                    and delete the volume configuration files from it andi
 *                    restart glusterd
 */
#define GD_MSG_CKSUM_VERS_MISMATCH (GLUSTERD_COMP_BASE + 10)

/*!
 * @messageid 106011
 * @diagnosis A volume quota-conf version mismatch occured while adding a peer
 * @recommendedaction None
 */
#define GD_MSG_QUOTA_CONFIG_VERS_MISMATCH (GLUSTERD_COMP_BASE + 11)

/*!
 * @messageid 106012
 * @diagnosis A quota-conf checksum mismatch occured while adding a peer
 * @recommendedaction Check for which node the checksum mismatch happens
 *                    and delete the volume configuration files from it and
 *                    restart glusterd
 */
#define GD_MSG_QUOTA_CONFIG_CKSUM_MISMATCH (GLUSTERD_COMP_BASE + 12)

/*!
 * @messageid 106013
 * @diagnosis Brick process could not be terminated
 * @recommendedaction Find the pid of the brick process from the log file and
 *                    manually kill it
 */
#define GD_MSG_BRICK_STOP_FAIL (GLUSTERD_COMP_BASE + 13)

/*!
 * @messageid 106014
 * @diagnosis One of the listed services:NFS Server, Quota Daemon, Self Heal
 *            Daemon, or brick process could not be brought offline
 * @recommendedaction Find the pid of the process from the log file and
 *                    manually kill it
 */
#define GD_MSG_SVC_KILL_FAIL (GLUSTERD_COMP_BASE + 14)

/*!
 * @messageid 106015
 * @diagnosis The process could not be killed with the specified PID
 * @recommendedaction None
 */
#define GD_MSG_PID_KILL_FAIL (GLUSTERD_COMP_BASE + 15)

/*!
 * @messageid 106016
 * @diagnosis Rebalance socket file is not found
 * @recommendedaction Rebalance failed as the socket file for rebalance is
 *                    missing. Restart the rebalance process
 */
#define GD_MSG_REBAL_NO_SOCK_FILE (GLUSTERD_COMP_BASE + 16)

/*!
 * @messageid 106017
 * @diagnosis Unix options could not be set
 * @recommendedaction Server is out of memory and needs a restart
 */
#define GD_MSG_UNIX_OP_BUILD_FAIL (GLUSTERD_COMP_BASE + 17)

/*!
 * @messageid 106018
 * @diagnosis RPC creation failed
 * @recommendedaction Rebalance failed as glusterd could not establish an RPC
 *                    connection. Check the log file for the exact reason of the
 *                    failure and then restart the rebalance process
 */
#define GD_MSG_RPC_CREATE_FAIL (GLUSTERD_COMP_BASE + 18)

/*!
 * @messageid 106019
 * @diagnosis The default options on volume could not be set with the volume
 *            create and volume reset commands
 * @recommendedaction Check glusterd log files to see the exact reason for
 *                    failure to set default options
 */
#define GD_MSG_FAIL_DEFAULT_OPT_SET (GLUSTERD_COMP_BASE + 19)

/*!
 * @messageid 106020
 * @diagnosis Failed to release cluster wide lock for one of the peer
 * @recommendedaction Restart the glusterd service on the node where the command
 * was issued
 */
#define GD_MSG_CLUSTER_UNLOCK_FAILED (GLUSTERD_COMP_BASE + 20)

/*!
 * @messageid 106021
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_NO_MEMORY    (GLUSTERD_COMP_BASE + 21)

/*!
 * @messageid 106022
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_UNSUPPORTED_VERSION    (GLUSTERD_COMP_BASE + 22)

/*!
 * @messageid 106023
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_COMMAND_NOT_FOUND    (GLUSTERD_COMP_BASE + 23)

/*!
 * @messageid 106024
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_SNAPSHOT_OP_FAILED    (GLUSTERD_COMP_BASE + 24)

/*!
 * @messageid 106025
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_INVALID_ENTRY    (GLUSTERD_COMP_BASE + 25)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_VOL_NOT_FOUND    (GLUSTERD_COMP_BASE + 27)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_REG_COMPILE_FAILED    (GLUSTERD_COMP_BASE + 28)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_FILE_OP_FAILED    (GLUSTERD_COMP_BASE + 29)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_SNAP_CREATION_FAIL (GLUSTERD_COMP_BASE + 30)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_VOL_OP_FAILED    (GLUSTERD_COMP_BASE + 31)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_CREATE_DIR_FAILED (GLUSTERD_COMP_BASE + 32)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_DIR_OP_FAILED    (GLUSTERD_COMP_BASE + 33)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_VOL_STOP_FAILED    (GLUSTERD_COMP_BASE + 34)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_NO_CLI_RESP    (GLUSTERD_COMP_BASE + 35)


/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_LOCK_INIT_FAILED    (GLUSTERD_COMP_BASE + 36)


/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_SNAP_LIST_GET_FAIL   (GLUSTERD_COMP_BASE + 37)


/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_UNOUNT_FAILED    (GLUSTERD_COMP_BASE + 38)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_LOCK_DESTROY_FAILED    (GLUSTERD_COMP_BASE + 39)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_SNAP_CLEANUP_FAIL (GLUSTERD_COMP_BASE + 40)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_SNAP_ACTIVATE_FAIL (GLUSTERD_COMP_BASE + 41)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_SNAP_DEACTIVATE_FAIL (GLUSTERD_COMP_BASE + 42)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_SNAP_RESTORE_FAIL (GLUSTERD_COMP_BASE + 43)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_SNAP_REMOVE_FAIL (GLUSTERD_COMP_BASE + 44)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_SNAP_CONFIG_FAIL (GLUSTERD_COMP_BASE + 45)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_SNAP_STATUS_FAIL (GLUSTERD_COMP_BASE + 46)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_SNAP_INIT_FAIL (GLUSTERD_COMP_BASE + 47)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_VOLINFO_SET_FAIL (GLUSTERD_COMP_BASE + 48)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_VOLINFO_GET_FAIL (GLUSTERD_COMP_BASE + 49)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_BRICK_CREATION_FAIL (GLUSTERD_COMP_BASE + 50)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_BRICK_GET_INFO_FAIL (GLUSTERD_COMP_BASE + 51)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_BRICK_NEW_INFO_FAIL (GLUSTERD_COMP_BASE + 52)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_LVS_FAIL (GLUSTERD_COMP_BASE + 53)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_SETXATTR_FAIL (GLUSTERD_COMP_BASE + 54)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_UMOUNTING_SNAP_BRICK (GLUSTERD_COMP_BASE + 55)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_OP_UNSUPPORTED (GLUSTERD_COMP_BASE + 56)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_SNAP_NOT_FOUND (GLUSTERD_COMP_BASE + 57)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_FS_LABEL_UPDATE_FAIL (GLUSTERD_COMP_BASE + 58)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_LVM_MOUNT_FAILED (GLUSTERD_COMP_BASE + 59)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_DICT_SET_FAILED (GLUSTERD_COMP_BASE + 60)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_CANONICALIZE_FAIL (GLUSTERD_COMP_BASE + 61)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_DICT_GET_FAILED (GLUSTERD_COMP_BASE + 62)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_SNAP_INFO_FAIL   (GLUSTERD_COMP_BASE + 63)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_SNAP_VOL_CONFIG_FAIL     (GLUSTERD_COMP_BASE + 64)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_SNAP_OBJECT_STORE_FAIL   (GLUSTERD_COMP_BASE + 65)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_DICT_UNSERIALIZE_FAIL    (GLUSTERD_COMP_BASE + 66)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_SNAP_RESTORE_REVERT_FAIL        (GLUSTERD_COMP_BASE + 67)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_SNAP_LIST_SET_FAIL       (GLUSTERD_COMP_BASE + 68)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_VOLFILE_CREATE_FAIL      (GLUSTERD_COMP_BASE + 69)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_VOLINFO_REMOVE_FAIL      (GLUSTERD_COMP_BASE + 70)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_VOL_DELETE_FAIL          (GLUSTERD_COMP_BASE + 71)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_SNAPSHOT_PENDING         (GLUSTERD_COMP_BASE + 72)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_BRICK_PATH_UNMOUNTED         (GLUSTERD_COMP_BASE + 73)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_BRICK_ADD_FAIL           (GLUSTERD_COMP_BASE + 74)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_BRICK_SET_INFO_FAIL      (GLUSTERD_COMP_BASE + 75)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_LVCREATE_FAIL            (GLUSTERD_COMP_BASE + 76)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_VG_GET_FAIL      (GLUSTERD_COMP_BASE + 77)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_TPOOL_GET_FAIL          (GLUSTERD_COMP_BASE + 78)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_LVM_REMOVE_FAILED        (GLUSTERD_COMP_BASE + 79)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_MISSEDSNAP_INFO_SET_FAIL         (GLUSTERD_COMP_BASE + 80)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_BRK_MOUNTOPTS_FAIL      (GLUSTERD_COMP_BASE + 81)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_MISSED_SNAP_LIST_STORE_FAIL        (GLUSTERD_COMP_BASE + 82)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_INVALID_MISSED_SNAP_ENTRY        (GLUSTERD_COMP_BASE + 83)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_MISSED_SNAP_GET_FAIL         (GLUSTERD_COMP_BASE + 84)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_MISSED_SNAP_CREATE_FAIL          (GLUSTERD_COMP_BASE + 85)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_DUP_ENTRY         (GLUSTERD_COMP_BASE + 86)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_MISSED_SNAP_STATUS_DONE          (GLUSTERD_COMP_BASE + 87)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_NO_EXEC_PERMS            (GLUSTERD_COMP_BASE + 88)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_GLOBAL_OP_VERSION_SET_FAIL       (GLUSTERD_COMP_BASE + 89)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_HARD_LIMIT_SET_FAIL      (GLUSTERD_COMP_BASE + 90)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_SNAPSHOT_OP_SUCCESS      (GLUSTERD_COMP_BASE + 91)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_STORE_FAIL       (GLUSTERD_COMP_BASE + 92)

/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
#define GD_MSG_GLOBAL_OP_VERSION_GET_FAIL       (GLUSTERD_COMP_BASE + 93)

/*------------*/
#define glfs_msg_end_x GLFS_MSGID_END, "Invalid: End of messages"

#endif /* !_GLUSTERD_MESSAGES_H_ */
