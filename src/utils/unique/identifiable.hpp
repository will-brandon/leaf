/**
 * @file    identifiable.hpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    May 6, 2023
 * 
 * @brief   Header for a class that represents a uniquely identifiable object that cannot be copied
 *          or moved in memory. This implies that it must be handled by a pointer. The object has
 *          a UUID that identifies it.
 * 
 * @copyright Copyright (c) 2023
 */

#ifndef IDENTIFIABLE_H_HEADER_GUARD
#define IDENTIFIABLE_H_HEADER_GUARD

#include "uuid.hpp"
#include "unique.hpp"

using namespace std;

namespace utl
{
    /**
     * @brief   Represents a uniquely identifiable object that cannot be copied or moved in memory.
     *          This implies that it must be handled by a pointer. The object has a UUID that
     *          identifies it.
     */
    class identifiable : public unique
    {
        private:
            /**
             * @brief   The 16-byte UUID that identifies the unique object.
             */
            const uuid m_uuid;
        
        public:
            /**
             * @brief   Determines the UUID of the unqiue object.
             * 
             * @return uuid_t 
             */
            uuid uuid(void) const noexcept;
    };
}

#endif