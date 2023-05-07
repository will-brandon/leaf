/**
 * @file    uuid.hpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    May 6, 2023
 * 
 * @brief   Implementation for a structure that represents a UUID (universally unique identifier)
 *          that adheres to the RFC 4122 protocol.
 * 
 * @copyright Copyright (c) 2023
 */

#include <uuid/uuid.h>
#include "uuid.hpp"

using namespace std;

namespace utl
{
    uuid::uuid(void) noexcept
    {
        // Use the C UUID library to generate a random UUID.
        uuid_generate_random(bytes);
    }

    uuid::uuid(const byte_t *bytes) noexcept
    {
        // Copy the 16 bytes from the given buffer into the value of the UUID structure.
        uuid_copy(this->bytes, bytes);
    }

    bool uuid::operator==(const uuid &other) const noexcept
    {
        // Compare the memory of the 16 bytes that compose the UUID of each structure.
        return uuid_compare(bytes, other.bytes);
    }

    string uuid::to_string(void) const noexcept
    {
        // Create a character buffer to hold the unparsed UUID display string.
        char char_buffer[UUID_STRING_LEN];

        // Unparse (stringify) the UUID bytes.
        uuid_unparse(bytes, char_buffer);

        // Return the character buffer autocasted into a string object.
        return char_buffer;
    }
}
