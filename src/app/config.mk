LOCAL_DIR := src/app

LOCAL_SRCS := dhcp.c             \
			net_monitor.c        \
			net_monitor_all.c    \
			net_monitor.c        \
			net_monitor_ip.c     \

ASRCS += $(addprefix $(LOCAL_DIR)/, $(LOCAL_SRCS))
