CC = clang

SRC_DIR	=	src/
OBJ_DIR	=	target/
INC_DIR	=	include/
LFT_DIR	=	libft/
LFT_VER = e9f828b6741b1061a21729b6d44a5c0989c24474
_LIB_FT	=	$(LFT_DIR)libft.a

CFLAGS = -Wall -Wextra -Werror -Wpedantic -std=c17 -g -O3 \
				-I$(INC_DIR) -I$(LFT_DIR)include -I$(LFT_DIR) -fsanitize=undefined -fsanitize=address
LDFLAGS = -g -fsanitize=undefined -fsanitize=address

# Check if mold linker exists
MOLD_LINKER := $(shell command -v mold 2> /dev/null)
# Check if lld linker exists
LLD_LINKER := $(shell command -v ld.lld 2> /dev/null)

# Use mold as linker if available, otherwise use lld, otherwise use default
INC_LBFT = $(_LIB_FT)
ifneq ($(MOLD_LINKER),)
	LDFLAGS += -fuse-ld=mold
else ifneq ($(LLD_LINKER),)
	LDFLAGS += -fuse-ld=lld
else
	INC_LBFT = -Wl,--whole-archive $(_LIB_FT) -Wl,--no-whole-archive
endif

NAME = push_swap

SRC = \
	$(SRC_DIR)data.c \
	$(SRC_DIR)utils.c \
	 \
	$(SRC_DIR)nbr/list_search.c \
	$(SRC_DIR)nbr/math_list.c \
	$(SRC_DIR)nbr/math_list_2.c \
	 \
	$(SRC_DIR)ope/enum.c \
	$(SRC_DIR)ope/push.c \
	$(SRC_DIR)ope/rizz_rotate.c \
	$(SRC_DIR)ope/rotate.c \
	$(SRC_DIR)ope/swap.c \
	 \
	$(SRC_DIR)str/find_lst.c \
	 \
	$(SRC_DIR)sort/brot_push.c \
	$(SRC_DIR)sort/sort.c \
	 \
	$(SRC_DIR)infinite_pretzel/pretzel.c \

OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)/push_swap/%.o, $(SRC))

all: $(NAME)

$(NAME): $(_LIB_FT) $(OBJ) $(OBJ_DIR)/push_swap/$(NAME).o
	@$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJ) $(SRC_DIR)$(NAME).c \
        $(INC_LBFT)
ifneq ($(MOLD_LINKER),)
	@echo "Linking $@ using the mold linker"
else ifneq ($(LLD_LINKER),)
	@echo "Linking $@ using the lld linker"
else
	@echo "Linking $@ using the default linker"
endif

$(_LIB_FT):
	@if [ ! -d $(LFT_DIR) ]; then git clone https://github.com/cliftontoaster-reid/libft $(LFT_DIR); fi
	@cd libft && git checkout $(LFT_VER) && cd ..
	$(MAKE) -C $(LFT_DIR) OBJ_DIR=$(abspath $(OBJ_DIR))/libft

$(OBJ_DIR)/push_swap/%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo "Compiled $<"

shared: $(_LIB_FT) $(OBJ)
	ar rcs $(OBJ_DIR)$(NAME).a $(OBJ)

test: shared
	@$(MAKE) -C tests OBJ_DIR=$(abspath $(OBJ_DIR))/tests LFT_DIR=$(abspath $(LFT_DIR)) INC_DIR=$(abspath $(INC_DIR)) \
		EXT_OBJ=$(abspath $(OBJ_DIR)$(NAME).a) LFT_VER=$(LFT_VER)
	@./tests/swapush

clean:
	rm -rf $(OBJ_DIR)
nclean: clean
	rm -f $(NAME)
fclean: nclean
	rm -rf $(LFT_DIR)

re: fclean all
qre: nclean all

.PHONY: all clean nclean fclean re qre shared test