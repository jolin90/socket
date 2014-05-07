Q = @
RM = rm -rf

APP_PATH=app
LIB_PATH=lib
OUT_PATH=out
INCLUDE_PATH=include

LIB_SRC_FILES=$(wildcard $(LIB_PATH)/*.c)
LIB_OBJ_FILES=$(patsubst %.c, $(OUT_PATH)/%.o, $(LIB_SRC_FILES))
JOLIN_O=$(OUT_PATH)/$(LIB_PATH)/jolin.o

APP_SRC_FILES=$(wildcard $(APP_PATH)/*.c)
APP_OUT_BIN=$(patsubst %.c, $(OUT_PATH)/%, $(APP_SRC_FILES))

CFLAGS = -I ./$(INCLUDE_PATH) -fPIC -Wall
LIBS = -l pthread

all : $(JOLIN_O) $(APP_OUT_BIN)
	$(Q) echo "DONE"
	$(Q) echo ""

lib : $(JOLIN_O)

$(JOLIN_O) : $(LIB_OBJ_FILES)
	$(Q) echo "[LD] $@ <= $^"
	$(Q) ld -o $@ -r $^
	$(Q) echo ""

$(OUT_PATH)/$(LIB_PATH)/%.o: $(LIB_PATH)/%.c
	$(Q) echo "[CC] $^ => $@"
	$(Q) mkdir -p $(OUT_PATH)/$(LIB_PATH)
	$(Q) gcc -c $^ $(CFLAGS) -o $@

$(OUT_PATH)/$(APP_PATH)/%:$(OUT_PATH)/$(APP_PATH)/%.o
	$(Q) echo "[LD] $^ => $@"
	$(Q) mkdir -p ${OUT_PATH}/$(APP_PATH)
	$(Q) gcc -o $@ $^ $(JOLIN_O) $(LIBS)
	$(Q) strip -s $@

$(OUT_PATH)/$(APP_PATH)/%.o:$(APP_PATH)/%.c
	$(Q) echo "[CC] $^ => $@"
	$(Q) mkdir -p $(OUT_PATH)/$(APP_PATH)
	$(Q) gcc -o $@ $(CFLAGS) -c $^

clean:
	$(Q) $(RM) $(OUT_PATH)

clean-app:
	$(Q) $(RM) $(APP_OUT_BIN)
