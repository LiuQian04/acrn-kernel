// SPDX-License-Identifier: BSD-3-Clause OR GPL-2.0
/*
 * RPMB Key management: key retrieval
 *
 * Copyright (c) 2018 Intel Corporation. All rights reserved.
 */

#define pr_fmt(fmt) KBUILD_MODNAME ":%s: " fmt, __func__

#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

#include "key.h"
#include "key_sbl.h"
#include "key_abl.h"

static ulong sbl_params_addr;
static ulong abl_params_addr;

static int __init get_sbl_params_addr(char *str)
{
	if (kstrtoul(str, 16, &sbl_params_addr)) {
		pr_err("Failed to parse ImageBootParamsAddr\n");
		return -EINVAL;
	}

	return 0;
}
__setup("ImageBootParamsAddr=", get_sbl_params_addr);

static int __init get_abl_params_addr(char *str)
{
	if (kstrtoul(str, 16, &abl_params_addr)) {
		pr_err("Failed to parse dev_sec_info.param\n");
		return -EINVAL;
	}

	return 0;
}
__setup("dev_sec_info.param_addr=", get_abl_params_addr);

int rpmb_key_get(const u8 *dev_id, size_t dev_id_len,
		 size_t max_partition_num, u8 rpmb_key[][RPMB_KEY_LENGTH])
{
	int ret = -1;

	if (sbl_params_addr)
		ret = rpmb_key_sbl_get(sbl_params_addr, max_partition_num,
				       rpmb_key);
	else if (abl_params_addr)
		ret = rpmb_key_abl_get(abl_params_addr, dev_id, dev_id_len,
				       max_partition_num, rpmb_key);
	else
		pr_err("Failed to get boot_params from the command line!\n");

	return ret;
}
