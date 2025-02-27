# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/26 21:27:04 by shinckel          #+#    #+#              #
#    Updated: 2025/02/27 10:40:45 by shinckel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

SRCS =	srcs/main.cpp \
				srcs/PmergeMe..cpp

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

OBJDIR = objs

OBJS = $(SRCS:srcs/%.cpp=$(OBJDIR)/%.o)

RED = \033[1;41m
GREEN = \033[1;42m
RESET = \033[0m

all: $(NAME)

$(OBJDIR)/%.o: srcs/%.cpp
		@mkdir -p $(OBJDIR)  # Create the OBJDIR directory if it doesn't exist
		$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
		@echo "$(GREEN) Ready to CPP_09-02 $(RESET)"

clean:
		@rm -f $(OBJS)
		@echo "$(RED) Remove object files $(RESET)"

fclean: clean
		@rm -f $(NAME)
		@rm -rf $(OBJDIR)
		@echo "$(RED) Remove $(NAME) $(RESET)"

re: fclean all

.PHONY: all clean fclean re
