CC = clang

SRC_DIR	=	src/
INC_DIR	=	include/
LFT_DIR	=	libft/
CACHE_DIR = cache/
OBJ_DIR	=	$(CACHE_DIR)objs/
LFT_VER = e9f828b6741b1061a21729b6d44a5c0989c24474
_LIB_FT	=	$(LFT_DIR)libft.a

SANITIZE = -fsanitize=undefined -fsanitize=address
DEBUG = -g

CFLAGS = -Wall -Wextra -Werror -Wpedantic -std=c17 $(DEBUG) -O3 \
         -I$(INC_DIR) -I$(LFT_DIR)include -I$(LFT_DIR) $(SANITIZE) \
         -MMD
LDFLAGS = $(SANITIZE)

MOLD_LINKER := $(shell command -v mold 2> /dev/null)
LLD_LINKER := $(shell command -v ld.lld 2> /dev/null)

ifneq ($(MOLD_LINKER),)
	LDFLAGS += -fuse-ld=mold
else ifneq ($(LLD_LINKER),)
	LDFLAGS += -fuse-ld=lld
endif

ifneq ($(MOLD_LINKER)$(LLD_LINKER),)
	LIB_FLAGS = -L$(LFT_DIR) -lft
else
	LIB_FLAGS = -Wl,--whole-archive $(_LIB_FT) -Wl,--no-whole-archive
endif

NAME = push_swap

SRC = \
	$(SRC_DIR)data/init.c \
	$(SRC_DIR)data/stack.c \
	$(SRC_DIR)data/split.c \
	$(SRC_DIR)data/envp.c \
	$(SRC_DIR)data/list.c \
	$(SRC_DIR)cmd/arc_rotate.c \
	$(SRC_DIR)cmd/push.c \
	$(SRC_DIR)cmd/rotate.c \
	$(SRC_DIR)cmd/swap.c \
	$(SRC_DIR)job/quicksort.c \
	$(SRC_DIR)job/stack.c \
	$(SRC_DIR)job/bitshift.c \
	$(SRC_DIR)job/smol.c \
	$(SRC_DIR)$(NAME).c

OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)/push_swap/%.o, $(SRC))
DEPFILES = $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(_LIB_FT) $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJ) $(LIB_FLAGS)
	@if [ -n "$(MOLD_LINKER)" ]; then \
		echo "Linked $@ using mold"; \
	elif [ -n "$(LLD_LINKER)" ]; then \
		echo "Linked $@ using lld"; \
	else \
		echo "Linked $@ using default linker"; \
	fi

$(_LIB_FT):
	@if [ ! -d "$(LFT_DIR)" ]; then \
		git clone https://github.com/cliftontoaster-reid/libft $(LFT_DIR); \
	fi
	@cd $(LFT_DIR) && \
		current_commit=$$(git rev-parse HEAD); \
		if [ "$$current_commit" != "$(LFT_VER)" ]; then \
			git fetch origin && git checkout $(LFT_VER); \
		fi
	$(MAKE) -C $(LFT_DIR) OBJ_DIR=$(abspath $(OBJ_DIR))/libft

$(OBJ_DIR)/push_swap/%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<
	@echo "Compiled $<"

-include $(DEPFILES)

shared: $(_LIB_FT) $(OBJ)
	ar rcs $(OBJ_DIR)$(NAME).a $(OBJ)

test: shared
	$(MAKE) -C tests OBJ_DIR=$(abspath $(OBJ_DIR))/tests LFT_DIR=$(abspath $(LFT_DIR)) \
		INC_DIR=$(abspath $(INC_DIR)) EXT_OBJ=$(abspath $(OBJ_DIR)$(NAME).a) \
		LFT_VER=$(LFT_VER) CACHE_DIR=$(abspath $(CACHE_DIR))
	./tests/swapush

clean:
	rm -rf $(OBJ_DIR)

nclean: clean
	rm -f $(NAME)
	$(MAKE) -C tests nclean

fclean: nclean
	rm -rf $(LFT_DIR) $(CACHE_DIR)

re: fclean all

qre: nclean all

.PHONY: all clean nclean fclean re qre shared test

.DELETE_ON_ERROR: