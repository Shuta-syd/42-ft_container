NAME := ft_container
CXX := c++
RM := rm -rf

objs_dir += test/
deps_dir += test/

srcs += $(addprefix test/, \
  	main.cpp utils.cpp tester_vector.cpp \
		tester_map.cpp tester_stack.cpp\
    )

objs := $(srcs:%.cpp=objs/%.o)
deps := $(srcs:%.cpp=deps/%.d)

objs_dir := $(addprefix objs/, $(objs_dir))
objs_dir := $(addsuffix .keep, $(objs_dir))

deps_dir := $(addprefix deps/, $(deps_dir))
deps_dir := $(addsuffix .keep, $(deps_dir))

debugflags := -g3 -fsanitize=address
headerflags := -MMD -MP
CXXFLAGS := -g -Wall -Werror -Wextra -std=c++98
INC = -I./containers -I./iterators -I./type_traits -I./algorithm -I./utility

############# basic rules ##############
.PHONY: all clean fclean re
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
	$(RM) $(objs)
	$(RM) $(deps)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(objs_dir)
	$(RM) $(deps_dir)

re: fclean all

############## convenient rules ##############
.PHONY: debug leak
debug: CXXFLAGS += $(debugflags)
debug: re

test: all
	@./$(NAME) test
vector: all
	@./$(NAME) vector
map: all
	@./$(NAME) map
stack: all
	@./$(NAME) stack
subject:
	@$(CXX) $(CXXFLAGS) $(INC) main.cpp

leaks: $(NAME)
	@leaks -q --atExit -- ./$(NAME) test


RED = \033[31m
GRN = \033[32m
YEL = \033[33m
BLU = \033[34m
MGN = \033[35m
CYN = \033[36m
RES = \033[m
