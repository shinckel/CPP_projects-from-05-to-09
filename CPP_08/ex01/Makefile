# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/26 21:27:04 by shinckel          #+#    #+#              #
#    Updated: 2025/01/07 11:15:46 by shinckel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = span

SRCS =	srcs/main.cpp \
				srcs/Span.cpp

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

# Define the directory for object files
OBJDIR = objs

# Update OBJS to place object files in the OBJDIR directory
OBJS = $(SRCS:srcs/%.cpp=$(OBJDIR)/%.o)

# Define colors
RED = \033[1;41m
GREEN = \033[1;42m
RESET = \033[0m

all: $(NAME)

# Rule to compile .cpp files to .o files in the OBJDIR directory
$(OBJDIR)/%.o: srcs/%.cpp
		@mkdir -p $(OBJDIR)  # Create the OBJDIR directory if it doesn't exist
		$(CXX) $(CXXFLAGS) -c $< -o $@

# Link the object files to create the final executable
$(NAME): $(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
		@echo "$(GREEN) Ready to CPP_08-01 $(RESET)"

clean:
		@rm -f $(OBJS)
		@echo "$(RED) Remove object files $(RESET)"

fclean: clean
		@rm -f $(NAME)
		@rm -rf $(OBJDIR)
		@echo "$(RED) Remove $(NAME) $(RESET)"

re: fclean all

.PHONY: all clean fclean re
