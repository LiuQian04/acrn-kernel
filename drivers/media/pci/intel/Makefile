# SPDX-License-Identifier: GPL-2.0
# Copyright (c) 2010 - 2018, Intel Corporation.
#
#
# Makefile for the IPU3 cio2, ImGU and IPU4 drivers
#

obj-y	+= ipu3/

# force check the compile warning to make sure zero warnings
# note we may have build issue when gcc upgraded.
subdir-ccflags-y := -Wall -Wextra
subdir-ccflags-y += $(call cc-disable-warning, unused-parameter)
subdir-ccflags-y += $(call cc-disable-warning, implicit-fallthrough)
subdir-ccflags-y += $(call cc-disable-warning, missing-field-initializers)
subdir-ccflags-$(CONFIG_VIDEO_INTEL_IPU_WERROR) += -Werror

ifndef CONFIG_VIDEO_INTEL_ICI
obj-$(CONFIG_VIDEO_INTEL_IPU4)  += ipu4/
obj-$(CONFIG_VIDEO_INTEL_IPU4P)	+= ipu4/
endif
obj-$(CONFIG_VIDEO_INTEL_ICI)   += ici/
obj-$(CONFIG_VIDEO_INTEL_IPU_ACRN)      += virtio/
