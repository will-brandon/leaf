/**
 * @file    unqique.hpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    May 6, 2023
 * 
 * @brief   Header for a class that represents a unique object that cannot be copied or moved in
 *          memory. This implies that it must be handled by a pointer.
 * 
 * @copyright Copyright (c) 2023
 */

#ifndef UNIQUE_H_HEADER_GUARD
#define UNIQUE_H_HEADER_GUARD

namespace utl
{
    /**
     * @brief   Represents a unique object that cannot be copied or moved in memory. This implies
     *          that it must be handled by a pointer.
     */
    class unique
    {
        public:
            /**
             * @brief   A unqiue object can be constructed, but it cannot be copied or moved
             *          thereafter.
             */
            unique(void) noexcept = default;

            /**
             * @brief   A unique object cannot be copied. Therefore, this functionality is deleted.
             * 
             * @param   other   a separate object
             */
            unique(const unique &other) noexcept = delete;

            /**
             * @brief   A unqique object cannot be moved. Therefore, this functionality is deleted.
             * 
             * @param   other   a separate window object
             */
            unique(unique &&other) noexcept = delete;

            /**
             * @brief   A unique object cannot be copied. Therefore, this functionality is deleted.
             * 
             * @param   other   a separate window object
             */
            unique &operator=(const unique &other) noexcept = delete;

            /**
             * @brief   A unqique object cannot be moved. Therefore, this functionality is deleted.
             * 
             * @param   other   a separate window object
             */
            unique &operator=(unique &&other) noexcept = delete; 
    };
}

#endif