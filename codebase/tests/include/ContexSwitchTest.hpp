/**
 * @file      ContexSwitchTest.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2023, Sergey Baigudin, Baigudin Software
 *
 * @brief Tests of contex switch.
 */
#ifndef TST_CONTEXSWITCHTEST_HPP_
#define TST_CONTEXSWITCHTEST_HPP_
 
#include "Types.hpp"

namespace eoos
{

/**
 * @brief Tests thread contex switch correctly.
 *
 * This function won't return and will break all CPU registers and C/C++ ABI.
 * This test must be checked visually on the appropriate break points.
 */
void testContexSwitch();

} // namespace eoos

#endif // TST_CONTEXSWITCHTEST_HPP_

