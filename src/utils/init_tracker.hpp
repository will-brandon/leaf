/**
 * @file    init_tracker.hpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    February 6, 2023
 * 
 * @brief   Header for a class that produces an object with functionality to track whether something
 *          was initialized. This functionality is typically used in a composition design pattern,
 *          i.e. classes will contain an Initiable object to track whether they have been
 *          initialized.
 * 
 * @copyright Copyright (c) 2023
 */

#ifndef INIT_TRACKER_H_HEADER_GUARD
#define INIT_TRACKER_H_HEADER_GUARD

#include <string>

using namespace std;

namespace utl
{
    /**
     * @brief   A class that produces an object with functionality to track whether something was
     *          initialized. This functionality is typically used in a composition design pattern,
     *          i.e. classes will contain an Initiable object to track whether they have been
     *          initialized.
     */
    class init_tracker
    {
        private:
            /**
             * @brief   The name of the subject (often a class) that the initialization tracker is
             *          actively tracking.
             */
            const string m_subject_name;

            /**
             * @brief   A flag denoting whether the tracker is in an initialzied state. It will
             *          yield false upon construction, true when an initialization is registered,
             *          then false again when the a deinitialization is registered.
             */
            bool m_did_init;

        public:
            /**
             * @brief   Construct a new initialization tracker object and assumes that no
             *          initialization event has occurred.
             * 
             * @param   subject_name    the name of the subject (often a class) that the
             *                          initialization tracker is actively tracking
             */
            init_tracker(const string &subject_name) noexcept;

            /**
             * @brief   Destroys initialization tracker object. The method is set to default because
             *          there are no resources to free, but it is explicitly declared as virtual
             *          because inheritance is supported.
             */
            virtual ~init_tracker() noexcept = default;

            /**
             * @brief   Returns whether the tracker has registered an initialization since the start
             *          of the program or since the last deinitialization.
             * 
             * @return  true if and only if the class is in an initialized state
             */
            bool did_init(void) const noexcept;

            /**
             * @brief   Informs the tracker that an initialization event has been completed.
             */
            void register_init(void) noexcept;

            /**
             * @brief   Informs the tracker that a deinitialization event has been completed.
             */
            void register_deinit(void) noexcept;

            /**
             * @brief   Throws a runtime_error if an initialization has not yet been registered
             *          since construction or since the last deinit.
             * 
             * @param   operation   the name of the operation that was attempted
             * 
             * @throw   runtime_error if initialization has not yet been registered
             */
            void assert_init(const string &operation) const;
    };
}

#endif
