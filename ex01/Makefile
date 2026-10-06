NAME = phonebook

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
MAKE_FLAGS = --silent --no-print-directory

SRCS_DIR = src
HEADERS_DIR = include
OBJS_DIR = obj

SRCS = $(SRCS_DIR)/main.cpp \
	   $(SRCS_DIR)/Contact.cpp \
	   $(SRCS_DIR)/PhoneBook.cpp

HEADERS = $(HEADERS_DIR)/Contact.hpp \
		  $(HEADERS_DIR)/PhoneBook.hpp \

OBJS = $(SRCS:$(SRCS_DIR)/%.cpp=$(OBJS_DIR)/%.o)

# Colors
GREEN	= \033[38;5;84m
YELLOW	= \033[38;5;227m
RED		= \033[38;5;9m
BLUE	= \033[38;5;75m
BOLD	= \033[1m
RESET   = \033[0m
UP		= "\033[A""\033[K"

all: $(NAME)
	echo "$(GREEN) ✨ $(NAME) is up to date!$(RESET)"

$(NAME): $(OBJS_DIR) $(OBJS)
	echo "$(YELLOW) 🔧 Compiling ... $(NAME)$(RESET)"
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	printf $(UP)
	echo "$(GREEN) ✅ Built $(NAME)$(RESET)"

$(OBJS_DIR):
	echo "$(YELLOW) 📁 Creating $(OBJS_DIR)...$(RESET)"
	mkdir -p $(OBJS_DIR)
	printf $(UP)
	echo "$(GREEN) 📁 Created $(OBJS_DIR) ✅$(RESET)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp $(HEADERS)
	echo "$(YELLOW) 🔧 Compiling ... $<$(RESET)"
	$(CXX) $(CXXFLAGS) -I$(HEADERS_DIR) -c $< -o $@
	printf $(UP)

clean:
	echo "$(RED) 🧹 Cleaning object files ...$(RESET)"
	rm -f $(OBJS)
	printf $(UP)
	echo "$(GREEN) 🗑️✨ Removed all object files$(RESET)"

fclean:
	echo "$(RED) 🧹 Deep cleaning project ...$(RESET)"
	rm -rf $(OBJS_DIR)
	rm -f $(NAME)
	printf $(UP)
	echo "$(GREEN) 🧽 Deep cleaning is complete$(RESET)"

re:
	echo "$(BLUE) 🔄 Rebuilding everything ...$(RESET)"
	make $(MAKE_FLAGS) fclean
	printf $(UP)
	make $(MAKE_FLAGS) all

.SILENT:
.PHONY: all clean fclean re
