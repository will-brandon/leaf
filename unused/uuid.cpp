/// 
/// @file       uuid.cpp
/// @author     Will Brandon (brandon.w@northeastern.edu)
/// @date       May 6, 2023
/// 
/// @brief      Implementation for a structure that represents a UUID (universally unique
///             identifier) that adheres to the RFC 4122 protocol.
/// 
/// @copyright  Copyright (c) 2023
/// 

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

    uuid::uuid(const string &string)
    {
        // Attempt to decode the UUID string. If the decode fails, throw an error.
        if (uuid_parse(string.c_str(), bytes))
        {
            throw runtime_error("Failed to create UUID. (Given string representation was invalid)");
        }

        // Using bit-manipulation, ensure that the 4 most significat bits of the 7th byte are 0100
        // in compliance with RFC 4122.
        if ((bytes[6] & 0xF0) - 0b01000000)
        {
            throw runtime_error(
                "Failed to create UUID. (The 4 most significant bits of byte 7 must be 0100'B.)");
        }

        // Using bit-manipulation, ensure that the 2 most significat bits of the 9th byte are 10
        // in compliance with RFC 4122.
        if ((bytes[8] & 0xC0) - 0b10000000)
        {
            throw runtime_error(
                "Failed to create UUID. (The 2 most significant bits of byte 9 must be 10'B.)");
        }
    }

    bool uuid::operator==(const uuid &other) const noexcept
    {
        // Compare the memory of the 16 bytes that compose the UUID of each structure. 0 indicates
        // equality so treat this as a boolean and negate it.
        return !uuid_compare(bytes, other.bytes);
    }

    bool uuid::operator!=(const uuid &other) const noexcept
    {
        // Compare the memory of the 16 bytes that compose the UUID of each structure. 0 indicates
        // equality so treat this as a boolean.
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
