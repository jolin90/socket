LOCAL_DIR := src/app

LOCAL_SRCS := dhcp.c net_monitor.c

LOCAL_SUBDIRS	:= test

ASRCS += $(addprefix $(LOCAL_DIR)/, $(LOCAL_SRCS))

include $(patsubst %, $(LOCAL_DIR)/%/config.mk, $(LOCAL_SUBDIRS))
