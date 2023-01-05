NAME=ft_container
RM=rm -rf

CXX=c++
CXXFLAGS=-Wall -Werror -Wextra -std=c++98 -pedantic
headerflags=-MMD -MP

inc= containers iterators

.PHONY: all re clean fclean

RED = \033[31m
GRN = \033[32m
YEL = \033[33m
BLU = \033[34m
MGN = \033[35m
CYN = \033[36m
RES = \033[m
