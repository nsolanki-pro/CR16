# Tools used in this makefile
RM	= rm -f
CP	= cp
CC	= cr16-elf-gcc
LIB	= cr16-elf-ar
AS	= cr16-elf-gcc
MAKE	= make 
MKDIR	= mkdir
# Objects
LOBJ	=	start.o intable.o  \
		svc_hndl.o dvz_hndl.o flg_hndl.o und_hndl.o iad_hndl.o
BUILD_PATH ?= ./
OUT_OBJ =	$(addprefix $(BUILD_PATH)./,$(LOBJ) )
SRC_PATH = $(shell pwd)

# Compilation tools flags

CR16C_CFLAGS	= -mcr16cplus

CR16CP_CFLAGS	= -mcr16cplus

CFLAGS  = $(ARCH_FLAG) -c  $(DEFS) \
		-I. $(OPT_FLAG) $(DEFAULT_FLAGS) -nostdlib 
ASFLAGS = $(ARCH_FLAG) -c  $(DEFS)  -nostdlib

# Suffixes
.SUFFIXES: .sp

ifneq ($(V),1)
.SILENT:
endif

# Targets

all: $(BUILD_PATH)./libstart.a

$(BUILD_PATH)./libstart.a: $(OUT_OBJ)
	$(LIB) r $(BUILD_PATH)./libstart.a $(OUT_OBJ)

$(BUILD_PATH)./libstart16c:
	$(MAKE) $(BUILD_PATH)./libstart.a ARCH_FLAG="$(CR16C_CFLAGS)"

$(BUILD_PATH)./libstart16cp:
	$(MAKE) $(BUILD_PATH)./libstart.a ARCH_FLAG="$(CR16CP_CFLAGS)"

$(BUILD_PATH)./libstart16cp_far:
	$(MAKE) $(BUILD_PATH)./libstart.a ARCH_FLAG="-mdata-model=far $(CR16CP_CFLAGS)"


$(OUT_OBJ) : $(LOBJ) 


%.o : %.s  $(BUILD_PATH)./
	$(CC) $(CFLAGS) $<  -o $(BUILD_PATH)./$@

$(BUILD_PATH)./ :
	$(MKDIR) -p  $(BUILD_PATH)./

%.o : %.c
	$(CC) $(CFLAGS) $<  -o $(BUILD_PATH)./$@

clobber: clean

clean:
	$(RM) $(BUILD_PATH)./libstart.a $(OUT_OBJ)
	$(RM) $(LOBJ)
