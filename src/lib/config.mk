LOCAL_DIR := src/lib

LOCAL_SRCS := ether.c ip.c tcp.c udp.c

CSRCS += $(addprefix $(LOCAL_DIR)/, $(LOCAL_SRCS))
