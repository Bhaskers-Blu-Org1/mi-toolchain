/*!
 * Copyright (C) tkornuta, IBM Corporation 2015-2019
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
/*!
 * \file Log.hpp
 * \brief Contains definitions of main logger-related macros.
 * \author tkornuta
 * \date Dec 1, 2015
 */

#ifndef SRC_CONFIGURATION_LOG_HPP_
#define SRC_CONFIGURATION_LOG_HPP_



#include <logger/ScopeLogger.hpp>

/*!
 * \brief Macro returning logger instance.
 * \author tkornuta
 */
#define LOGGER mic::logger::Logger::getInstance()

/*!
 * \brief Macro for message printing.
 */
#define LOG(level) (mic::logger::ScopeLogger(LOGGER, __FILE__, __LINE__, level).get())

/*!
 * \brief Macro for checking conditions.
 * \author krocki
 */
#define CHECK(EXP) mic::logger::check(EXP, #EXP, __LINE__, __FILE__)

namespace mic {
namespace logger {

/*!
 * \brief Function checking whether condition is true - if not, logs LWARNING.
 * \author krocki
 */
static __inline__ void check(bool condition, const char* expression, int line, const char* file) {
    if (!(condition))
    	LOG(LWARNING) <<  "Oops! '"<< expression <<"' is FALSE, Line " << line << " of file " << file;
}

} /* namespace logger */
} /* namespace mic */

#endif /* SRC_CONFIGURATION_LOG_HPP_ */
