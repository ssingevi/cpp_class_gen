# *** NAME - CC - FLAGS ****************************************************** #

NAME					=	cpp_gen

CC						= 	c++

CFLAGS					= 	-Wall -Wextra -Werror -I includes/ -std=c++98\

# *** PROJECT HEADER ********************************************************* #

HDIR					=	$(addprefix -I, $(HEADER_DIR))

HEAD					=	$(addprefix $(HEADER_DIR), $(HEADER))

HEADER_DIR				=	\
							./includes/

HEADER							=	\
									StrReplace.hpp	\

# *** SRCS ******************************************************************* #

SRCS_DIR					=	./srcs/

SRCS_LIST				=	\
								StrReplace.cpp	\
								main.cpp	\

SRCS					=	$(addprefix $(SRCS_DIR), $(SRCS_LIST))

# *** OBJS ******************************************************************* #

OBJS_DIR				=	./objs/

OBJS_LIST				=	$(patsubst %.cpp, %.o, $(SRCS_LIST))

OBJS					=	$(addprefix $(OBJS_DIR), $(OBJS_LIST))

all: $(OBJS) $(SRCS) $(NAME)

$(NAME): $(OBJS) $(SRCS)
	@ $(CC) $(CFLAGS) $(HDIR) $(OBJS) -o $@

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $(HDIR) -c -o $@ $<

clean:
	rm -rf $(OBJS_DIR)

fclean:
	rm -f $(NAME)
	rm -rf $(OBJS_DIR)

re: fclean all

.PHONY: all clean fclean re
