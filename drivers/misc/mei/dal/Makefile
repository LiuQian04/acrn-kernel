# SPDX-License-Identifier: GPL-2.0

ccflags-y += -D__CHECK_ENDIAN__

obj-$(CONFIG_INTEL_MEI_DAL) += mei_dal.o
mei_dal-objs := dal_class.o
mei_dal-objs += acp_parser.o
mei_dal-objs += bh_external.o
mei_dal-objs += bh_internal.o
mei_dal-objs += dal_cdev.o
mei_dal-objs += dal_kdi.o
mei_dal-objs += dal_ta_access.o

obj-$(CONFIG_INTEL_MEI_DAL_TEST) += dal_test.o
