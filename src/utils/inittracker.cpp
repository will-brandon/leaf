/**
 * @file    inittracker.cpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    February 6, 2023
 * 
 * @brief   Implementation for a class that produces an object with functionality to track whether
 *          something was initialized. This functionality is typically used in a composition design
 *          pattern, i.e. classes will contain an Initiable object to track whether they have been
 *          initialized.
 * 
 * @copyright Copyright (c) 2023
 */

#include <stdexcept>
#include "inittracker.hpp"

using namespace std;

namespace utl
{
    // By default, the tracker is set to an uninitialized state.
    init_tracker::init_tracker(const string &subject_name) noexcept
        : m_subject_name(subject_name), m_did_init(false) {}

    bool init_tracker::did_init(void) const noexcept
    {
        // Return the initialization flag.
        return m_did_init;
    }

    void init_tracker::register_init(void) noexcept
    {
        // Mark the initialization flag true.
        m_did_init = true;
    }

    void init_tracker::register_deinit(void) noexcept
    {
        // Mark the initialization flag false.
        m_did_init = false;
    }

    void init_tracker::assert_init(const string &operation) const
    {
        // If the tracker is not in an initialized state, throw an appropriate error that includes
        // the subject and function name.
        if (!m_did_init)
        {
            throw runtime_error("Failed to " + operation + ". (" + m_subject_name
                + " was never initialized)");
        }
    }
}
