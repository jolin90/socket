TOPDIR		:= $(CURDIR)
OUT			:= out
SRC			:= src

# Cross compiler

#CROSS_COMPILE	?=
#CC			:= $(CROSS_COMPILE)gcc
#LD			:= $(CROSS_COMPILE)ld
#STRIP		:= $(CROSS_COMPILE)strip
#OBJCOPY		:= $(CROSS_COMPILE)objcopy
#OBJDUMP		:= $(CROSS_COMPILE)objdump

# $(info $(CC))
# $(info $(LD))

# Tools
RM			:= rm -f
RMDIR		:= rm -rf
MKDIR		:= mkdir -p
MV			:= mv -f
SED			:= sed

CPPFLAGS	:= -g -O2 -fno-strict-aliasing
CPPFLAGS	+= -I$(TOPDIR)/include
CFLAGS		+= -Wall -Wstrict-prototypes -std=c99 -fpic

GCCLIBDIR   := $(dir $(shell $(CC) -print-libgcc-file-name))
LDFLAGS     += -L$(GCCLIBDIR) -lgcc

CSRCS	:=
ASRCS	:=

OBJS	= $(patsubst %.c, $(OUT)/%.o, $(CSRCS))
APPS	= $(patsubst $(SRC)/%.c, $(OUT)/%, $(ASRCS))
LIBO	= $(OUT)/jolin.o

include $(SRC)/config.mk

$(OUT)/%.o: %.c
	$(Q) $(MKDIR) $(shell dirname $@)
	$(Q) echo "$< => $@"
	$(Q) $(COMPILE.c) -o $@ $<
	$(Q) $(CC) $(CPPFLAGS) -o $@.d -MM $<
	$(Q) $(MV) $@.d $@.d.tmp
	$(Q) sed -e 's|.*:|$(OUT)/$*.o:|' < $@.d.tmp > $@.d
	$(Q) sed -e 's/.*://' -e 's/\\$$//' < $@.d.tmp | fmt -1 | \
		sed -e 's/^ *//' -e 's/$$/:/' >> $@.d
	$(Q) $(RM) -f $@.d.tmp

$(OUT)/%: $(SRC)/%.c
	$(Q) $(MKDIR) $(shell dirname $@)
	$(Q) echo "$@ <= $^"
	$(Q) $(CC) -o $@ $< $(LIBO) $(CPPFLAGS) $(CFLAGS)

all: $(APPS)

$(APPS): $(LIBO)

$(LIBO): $(OBJS)
	$(Q) echo "$@ <= $^"
	$(Q) $(LD) -o $@ -r $^

-include $(OBJS:.o=.o.d))

.PHONY: clean
clean:
	$(Q) $(RM) $(OBJS) $(DEPS) $(APPS) $(LIBO)

.PHONY: distclean
distclean:
	$(Q) $(RMDIR) $(OUT)
