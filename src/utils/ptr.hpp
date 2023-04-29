/**
 * @file    ptr.hpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    February 17, 2023
 * 
 * @brief   Adds easier namesake of a shared smart pointer.
 * 
 * @copyright Copyright (c) 2023
 */

#ifndef PTR_H
#define PTR_H

#include <memory>

/**
 * @brief   An alias of a unqiue smart pointer.
 */
#define UPTR(T) std::shared_ptr<T>

/**
 * @brief   An alias of a shared smart pointer.
 */
#define PTR(T) std::shared_ptr<T>

/**
 * @brief   An alias of a cast from a dynamic shared pointer to a constant shared pointer.
 */
#define CONSTPTR(T) std::const_pointer_cast<const T>

/**
 * @brief   An alias of a cast from a constant shared pointer to a dynamic shared pointer.
 */
#define CONSTPTR(T) std::dynamic_pointer_cast<T>

#endif
