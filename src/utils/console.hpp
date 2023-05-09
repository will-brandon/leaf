/// 
/// @file       console.hpp
/// @author     Will Brandon (brandon.w@northeastern.edu)
/// @date       February 6, 2023
/// 
/// @brief      Header for a class with static functionality to interact with the terminal console
///             through standard input and standard output.
/// 
/// @copyright  Copyright (c) 2023
/// 

#ifndef CONSOLE_H_HEADER_GUARD
#define CONSOLE_H_HEADER_GUARD

#include <iostream>

namespace utl
{
    /// 
    /// @brief  A class with static functionality to interact with the terminal console through
    ///         standard input and standard output.
    /// 
    class console
    {
        private:
            /// 
            /// @brief  Denotes whether console messages in standard output should contain ANSI
            ///         escape sequences for styling such as color, bold, italic, etc.
            /// 
            static bool f_ansi_style_enabled;

        public:
            /// 
            /// @brief  Determines whether console messages in standard output will contain ANSI
            ///         escape sequences for styling such as color, bold, italic, etc.
            /// 
            /// @return true if and only if ANSI style is enabled
            /// 
            static bool ansi_style_enabled(void) noexcept;

            /// 
            /// @brief  Sets whether console messages in standard output will contain ANSI escape
            ///         sequences for styling such as color, bold, italic, etc.
            /// 
            /// @param  true if and only if ANSI style should be enabled
            /// 
            static void set_ansi_style_enabled(bool enabled) noexcept;

            /// 
            /// @brief  Displays a formatted error message in standard output, then exits with the
            ///         given code.
            /// 
            /// @tparam T           the type of object to pipe into standard output as the message
            /// @param  obj         the object to pipe into standard output as the messsage
            /// @param  exit_code   the exit code
            /// 
            template<typename T> static void err(const T &obj, int exit_code) noexcept
            {
                // Print a styled message if ANSI style is enabled, print a clean message otherwise.
                if (f_ansi_style_enabled)
                {
                    std::cout << "\033[1;91mError:\033[0;1m " << obj << "\033[0m\n";
                }
                else
                {
                    std::cout << "Error: " << obj << "\n";
                }

                // Exit with the given exit code.
                std::exit(exit_code);
            }

            /// 
            /// @brief  Displays a formatted error message in standard output, then exits with code
            ///         1.
            /// 
            /// @tparam T   the type of object to pipe into standard output as the message
            /// @param  obj the object to pipe into standard output as the messsage
            /// 
            template<typename T> static void err(const T &obj) noexcept
            {
                // Delegate the task and use exit code 1.
                err(obj, EXIT_FAILURE);
            }

            /// 
            /// @brief  Displays a formatted error message from an exception in standard output,
            ///         then exits with the given code.
            /// 
            /// @param  exc         the exception object whose message will pipe into standard
            ///                     output
            /// @param  exit_code   the exit code
            /// 
            inline static void err(const std::exception &exc, int exit_code) noexcept
            {
                // Retreieve the message from the exception and deletage to the templated err
                // function.
                err(exc.what(), exit_code);
            }

            /// 
            /// @brief  Displays a formatted error message from an exception in standard output,
            ///         then exits with code 1.
            /// 
            /// @param  exc the exception object whose message will pipe into standard output
            /// 
            inline static void err(const std::exception &exc) noexcept
            {
                // Retreieve the message from the exception and deletage to the templated err
                // function. Use exit code 1.
                err(exc.what(), EXIT_FAILURE);
            }

            /// 
            /// @brief  Displays a formatted warning message in standard output.
            /// 
            /// @tparam T   the type of object to pipe into standard output as the message
            /// @param  obj the object to pipe into standard output as the messsage
            /// 
            template<typename T> static void warn(const T &obj) noexcept
            {
                // Print a styled message if ANSI style is enabled, print a clean message otherwise.
                if (f_ansi_style_enabled)
                {
                    std::cout << "\033[1;93mWarning:\033[0;1m " << obj << "\033[0m\n";
                }
                else
                {
                    std::cout << "Warning: " << obj << "\n";
                }
            }

            /// 
            /// @brief  Displays a formatted warning message from an exception in standard output.
            /// 
            /// @param  exc the exception object whose message will pipe into standard
            ///             output
            /// 
            inline static void warn(const std::exception &exc) noexcept
            {
                // Retreieve the message from the exception and deletage to the templated warn
                // function.
                warn(exc.what());
            }
    };

}

#endif