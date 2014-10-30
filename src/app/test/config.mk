LOCAL_DIR := src/app/test

LOCAL_SRCS := test.c 

ASRCS += $(addprefix $(LOCAL_DIR)/, $(LOCAL_SRCS))
