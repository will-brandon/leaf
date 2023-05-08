/**
 * @file    uuid.hpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    May 6, 2023
 * 
 * @brief   Header a structure for a that represents a UUID (universally unique identifier) that
 *          adheres to the RFC 4122 protocol.
 * 
 * @copyright Copyright (c) 2023
 */

#ifndef UUID_H_HEADER_GUARD
#define UUID_H_HEADER_GUARD

#include "../memory_types.hpp"
#include "../displayable.hpp"

/**
 * @brief   A UUID is 16 bytes long.
 */
#define UUID_LEN (size_t)16

/**
 * @brief   A UUID string is 37 characters long. This is composed of 32 hexidecimal digits, 4
 *          hyphens, and a terminating '\0' character.
 */
#define UUID_STRING_LEN (size_t)37

namespace utl
{
    /**
     * @brief   Represents a UUID (universally unique identifier) that adheres to the RFC 4122
     *          protocol.
     */
    typedef struct uuid : public displayable
    {
        /**
         * @brief   The 16-byte UUID value stores as individual bytes.
         */
        byte_t bytes[UUID_LEN];
        
        /**
         * @brief   Constructs a new random UUID structure according to the RFC 4122 protocol.
         */
        uuid(void) noexcept;

        /**
         * @brief   Constructs a new UUID from a set of 16 bytes.
         * 
         * @param   bytes   a pointer to a contiguous set of 16 bytes in memory
         * 
         * @warning It is assumed that 16 readable bytes reside at this location. If this is not
         *          the case a segmentation fault will likely occur.
         */
        uuid(const byte_t *bytes) noexcept;
        
        /**
         * @brief   Constructs a new UUID from a UUID string. The string must adhere to the RFC 4122
         *          UUID protocol. It should contain 32 hexadecimal characters separated by 3
         *          hyphens. It should be in the form xxxxxxxx-xxxx-Mxxx-Nxxx-xxxxxxxxxxxx. M and N
         *          hold special values according to the constraints of RFC 4122. M must be the
         *          digit '4', N can be either '8', '9', 'A', or 'B'.
         * 
         * @param   string   the UUID string to decode
         * 
         * @throw   runtime_error if the UUID string is invalid and could not be decoded
         */
        uuid(const std::string &string);

        /**
         * @brief   Determines whether the UUID structure is equal to another UUID structure. This 
         *          simply performs a byte-by-byte comparison.
         * 
         * @param   other   the other UUID structure to compare
         * 
         * @return  true if and only if all 16 bytes are a perfect match
         */
        bool operator==(const uuid &other) const noexcept;

         /**
         * @brief   Determines whether the UUID structure is not equal to another UUID structure.
         *          This simply performs a byte-by-byte comparison.
         * 
         * @param   other   the other UUID structure to compare
         * 
         * @return  true if and only if all 16 bytes are a perfect match
         */
        bool operator!=(const uuid &other) const noexcept;

        /**
         * @brief   Converts the UUID to a display string. The string adheres to the RFC 4122
         *          UUID protocol. It will contain 32 hexadecimal characters separated by 3
         *          hyphens. It will be in the form xxxxxxxx-xxxx-Mxxx-Nxxx-xxxxxxxxxxxx. M and N
         *          hold special values according to the constraints of RFC 4122. M must be the
         *          digit '4', N can be either '8', '9', 'A', or 'B'.
         * 
         * @example 3bac23a0-929e-4481-b5aa-973002a7bf1e
         * 
         * @return  string  the display string
         */
        virtual std::string to_string(void) const noexcept override;
            
    } uuid_t;
}

#endif