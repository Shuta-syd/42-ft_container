NAME=ft_container
RM=rm -rf

CXX=c++
CXXFLAGS= -std=c++98#-Wall -Werror -Wextra -std=c++98 -pedantic
headerflags=-MMD -MP

INC = -I./containers -I./iterators

objs_dir += test/
deps_dir += test/
srcs += $(addprefix test/, \
    main.cpp vector.cpp\
)

objs := $(srcs:%.cpp=objs/%.o)
deps := $(srcs:%.cpp=deps/%.d)

objs_dir := $(addprefix objs/, $(objs_dir))

deps_dir := $(addprefix deps/, $(deps_dir))

############# basic rules ##############
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
	@$(CXX) $(CXXFLAGS)  $(INC) $(headerflags) -MF ./deps/$(*).d -c $< -o $@
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

.PHONY: all re clean fclean

RED = \033[31m
GRN = \033[32m
YEL = \033[33m
BLU = \033[34m
MGN = \033[35m
CYN = \033[36m
RES = \033[m
