/**
 * @file    console.hpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    February 6, 2023
 * 
 * @brief   Header for a class with static functionality to interact with the terminal console
 *          through standard input and standard output.
 * 
 * @copyright Copyright (c) 2023
 */

#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>

using namespace std;

namespace utl
{
    /**
     * @brief   A class with static functionality to interact with the terminal console through
     *          standard input and standard output.
     */
    class console
    {
        private:
            /**
             * @brief   Denotes whether console messages in standard output should contain ANSI
             *          escape sequences for styling such as color, bold, italic, etc..
             */
            static bool f_ansi_style_enabled;

        public:
            /**
             * @brief   Determines whether console messages in standard output will contain ANSI
             *          escape sequences for styling such as color, bold, italic, etc..
             * 
             * @return  true if and only if ANSI style is enabled
             */
            static bool ansi_style_enabled(void) noexcept;

            /**
             * @brief   Sets whether console messages in standard output will contain ANSI escape
             *          sequences for styling such as color, bold, italic, etc..
             * 
             * @param   true if and only if ANSI style should be enabled
             */
            static void set_ansi_style_enabled(bool enabled) noexcept;

            /**
             * @brief   Displays a formatted error message in standard output, then exits with code
             *          1.
             * 
             * @tparam  T   the type of object to pipe into standard output as the message
             * @param   obj the object to pipe into standard output as the messsage
             * 
             * @throw   exception if the the object of type T is not insertable into an output
             *          stream
             */
            template<typename T> static void err(const T &obj)
            {
                // Delegate the task and use error code 1.
                err(obj, EXIT_FAILURE);
            }

            /**
             * @brief   Displays a formatted error message in standard output, then exits with the
             *          given code.
             * 
             * @tparam  T           the type of object to pipe into standard output as the message
             * @param   obj         the object to pipe into standard output as the messsage
             * @param   exit_code   the exit code
             * 
             * @throw   exception if the the object of type T is not insertable into an output
             *          stream
             */
            template<typename T> static void err(const T &obj, int exit_code)
            {
                // Print a styled message if ANSI style is enabled, print a clean message otherwise.
                if (f_ansi_style_enabled)
                {
                    cout << "\033[1;91mError:\033[0;1m " << obj << "\033[0m\n";
                }
                else
                {
                    cout << "Error: " << obj << "\n";
                }

                // Exit with the given exit code.
                exit(exit_code);
            }

            /**
             * @brief   Displays a formatted warning message in standard output.
             * 
             * @tparam  T   the type of object to pipe into standard output as the message
             * @param   obj the object to pipe into standard output as the messsage
             * 
             * @throw   exception if the the object of type T is not insertable into an output
             *          stream
             */
            template<typename T> static void warn(const T &obj)
            {
                // Print a styled message if ANSI style is enabled, print a clean message otherwise.
                if (f_ansi_style_enabled)
                {
                    cout << "\033[1;93mWarning:\033[0;1m " << obj << "\033[0m\n";
                }
                else
                {
                    cout << "Warning: " << obj << "\n";
                }
            }
    };

}

#endif