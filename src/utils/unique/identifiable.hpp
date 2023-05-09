/// 
/// @file       identifiable.hpp
/// @author     Will Brandon (brandon.w@northeastern.edu)
/// @date       May 6, 2023
/// 
/// @brief      Header for a class that represents a uniquely identifiable object that cannot be
///             copied or moved in memory. This implies that it must be handled by a pointer. The
///             object has a UUID that identifies it.
/// 
/// @copyright  Copyright (c) 2023
/// 

#ifndef IDENTIFIABLE_H_HEADER_GUARD
#define IDENTIFIABLE_H_HEADER_GUARD

#include "uuid.hpp"
#include "unique.hpp"

namespace utl
{
    /// 
    /// @brief  Represents a uniquely identifiable object that cannot be copied or moved in memory.
    ///         This implies that it must be handled by a pointer. The object has a UUID that
    ///         identifies it.
    /// 
    class identifiable : public unique
    {
        private:
            /// 
            /// @brief  The 16-byte UUID that identifies the unique object.
            /// 
            const uuid_t m_uuid;
        
        public:
            /// 
            /// @brief  Constructs a new identifiable object and assigns it a random UUID.
            /// 
            inline identifiable(void) noexcept : m_uuid() {}

            /// 
            /// @brief  Determines the UUID of the unqiue object.
            /// 
            /// @return the UUID 
            /// 
            inline uuid_t uuid(void) const noexcept
            {
                // Return the UUID.
                return m_uuid;
            }
    };
}

#endif