NAME = ft_container
CC = g++
CXXFLAGS = -std=c++98 #-Wall -Wextra -Werror
RM = rm -rf

headerflags=-MMD -MP
srcs = $(wildcard test/*.cpp)
objs = $(addprefix objs/, $(srcs:.cpp=.o))
INC = -I./containers -I./iterators -I./type_traits -I./algorithm

objs_dir = objs/test/
deps_dir = deps/test/

############# basic rules ##############
.PHONY: all re clean fclean
all: $(NAME)

-include $(deps)

$(NAME): $(objs)
	@$(CXX) $(CXXFLAGS) $(objs) -o $(NAME)
	@echo "$(CYN)\n=====link=====$(RES)"
	@echo "$(YEL)Objects$(RES): $(objs)\n"
	@echo "$(YEL)Flags$(RES): $(CXXFLAGS)\n"
	@echo "     $(MGN)--->$(RES) $(GRN)$(NAME)$(RES)"
	@echo "$(CYN)==============$(RES)"

./objs/%.o: %.cpp $(objs_dir) $(deps_dir)
	@$(CXX) $(CXXFLAGS) $(INC) $(headerflags) -MF deps/$(*).d -c $< -o $@
	@echo "$< =========> $(GRN) $@ $(RES)"

$(objs_dir):
	@mkdir -p $@

$(deps_dir):
	@mkdir -p $@

clean:
	$(RM) ./objs
	$(RM) ./deps

fclean: clean
	$(RM) $(NAME)

re: fclean all

run:
	@./ft_container

leaks: $(NAME)
	leaks -q --atExit -- ./$(NAME)

RED = \033[31m
GRN = \033[32m
YEL = \033[33m
BLU = \033[34m
MGN = \033[35m
CYN = \033[36m
RES = \033[m
