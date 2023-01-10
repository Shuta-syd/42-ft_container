NAME=ft_container
RM=rm -rf

CXX=c++
CXXFLAGS= -g -std=c++98#-Wall -Werror -Wextra -std=c++98 -pedantic
headerflags=-MMD -MP

INC = -I./containers -I./iterators

srcs += $(addprefix test/, \
    main.cpp vector.cpp\
)

objs_dir += test/
objs := $(srcs:%.cpp=objs/%.o)
objs_dir := $(addprefix objs/, $(objs_dir))

deps_dir += test/
deps := $(srcs:%.cpp=deps/%.d)
deps_dir := $(addprefix deps/, $(deps_dir))

############# basic rules ##############
.PHONY: all re clean fclean
all: $(NAME) $(objs)

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

run: all
	@./ft_container

RED = \033[31m
GRN = \033[32m
YEL = \033[33m
BLU = \033[34m
MGN = \033[35m
CYN = \033[36m
RES = \033[m
