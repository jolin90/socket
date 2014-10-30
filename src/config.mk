LOCAL_DIR	:= src

LOCAL_SUBDIRS	:= lib app

CSRCS += $(addprefix $(LOCAL_DIR)/, $(LOCAL_SRCS))

include $(patsubst %, $(LOCAL_DIR)/%/config.mk, $(LOCAL_SUBDIRS))
