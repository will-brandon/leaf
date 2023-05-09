/// 
/// @file       release_types.hpp
/// @author     Will Brandon (brandon.w@northeastern.edu)
/// @date       May 7, 2023
/// 
/// @brief      Header for type definitions for software releases.
/// 
/// @copyright  Copyright (c) 2023
/// 

#ifndef LEAF_UTIL_SRC_RELEASE_TYPES_HEADER_GUARD
#define LEAF_UTIL_SRC_RELEASE_TYPES_HEADER_GUARD

#include "memory_types.hpp"
#include "displayable.hpp"

namespace utl
{
    /// 
    /// @brief  Represents a software release version.
    /// 
    typedef struct release_version : public displayable
    {
        /// 
        /// @brief  Represents the major component of the release. The major component is
        ///         incremented when a software release involves breaking the API of older releases,
        ///         i.e. it is not backward compatible with the older release.
        /// 
        byte_t major;

        /// 
        /// @brief  Represents the minor component of the release. The minor component is
        ///         incremented when a software release involves expanding upon the functionality of
        ///         the older release while maintaining backward compatibility.
        /// 
        byte_t minor;

        /// 
        /// @brief  Represents the patch component of the release. The patch component is
        ///         incremented when a software release involves fixing bugs. No new notable
        ///         features are added to the API and it remains backward compatible with the older
        ///         release.
        /// 
        byte_t patch;

        /// 
        /// @brief  Constructs a new release version object given major, minor, and patch
        ///         components.
        /// 
        /// @param  major   the major component
        /// @param  minor   the minor component
        /// @param  patch   the patch component
        /// 
        release_version(byte_t major, byte_t minor, byte_t patch) noexcept;

        /// 
        /// @brief  Returns a display string for the SDL version.
        /// 
        /// @return the display string
        /// 
        virtual std::string to_string(void) const noexcept override;

    } release_version_t;
}

#endif