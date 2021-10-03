cmake_minimum_required(VERSION 3.17)
project(minishell C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS_MINSIZEREL "-Wall -Wextra -Werror")
set(CMAKE_C_FLAGS_RELWITHDEBINFO "-Wall -Wextra -Werror")
set(CMAKE_C_FLAGS_RELEASE "-Wall -Wextra -Werror")
include_directories(libft includes gnl)
add_executable(minishell main.c libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c libft/ft_itoa.c
        libft/ft_memccpy.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar_fd.c libft/ft_putendl_fd.c
        libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c
        libft/ft_strmapi.c libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strtrim.c libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c libft/ft_split.c
        envp/env_finder.c build-in_functions/echo.c includes/build_in_functions.h build-in_functions/pwd.c exit_error_functions/exit_malloc.c includes/exit.h "build-in_functions/cd.c"
        envp/reallocate_envp.c libft/size_of_2d_array.c libft/clear_2d_arr.c envp/env_update.c libft/join_3_str.c build-in_functions/unset.c build-in_functions/export.c build-in_functions/env.c
        build-in_functions/exit.c exit_error_functions/exit_dup.c
        includes/exec.h includes/minishell.h envp/put_vars.c includes/all_structer.h signal/signal_main.c includes/signal_minishell.h
        parser/get_args.c parser/update_split.c exit_error_functions/error_funcs.c  parser/tokenizator.c parser/delete_quotes.c
        read/minishell_read.c libft/ft_atoi_ull.c build-in_functions/export_utils.c read/minishell_read_utils.c execution/single_command/make_file_fd.c parser/shell_counter.c parser/tokenizator_utils.c
        execution/pipe_commands/pipe_commands.c parser/check_valid_line/check_quotes.c parser/check_valid_line/check_reds.c
        parser/shell_parser.c parser/parser_utils.c parser/open_redirection.c parser/delete_quotes.c execution/pipe_commands/fd_helper.c
        execution/pipe_commands/pipe_commands.c execution/pipe_commands/pipe_exec.c execution/single_command/exec.c
        execution/single_command/exec_build_in.c execution/single_command/exec_utils.c execution/single_command/make_file_fd.c
        parser/put_error.c build-in_functions/wc.c build-in_functions/chmod.c build-in_functions/du.c build-in_functions/ls.c build-in_functions/ps.c)
