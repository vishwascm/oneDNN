/*******************************************************************************
* Copyright 2021-2025 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

// Default macro settings (if any) can be defined here.
#ifndef GPU_INTEL_JIT_CONFIG_NGEN_CONFIG_HPP
#define GPU_INTEL_JIT_CONFIG_NGEN_CONFIG_HPP

#include "common/bfloat16.hpp"
#include "common/float16.hpp"

#define NGEN_NAMESPACE ngen
#define NGEN_CPP11
#define NGEN_SAFE
#define NGEN_NEO_INTERFACE
#define NGEN_NO_OP_NAMES
#define NGEN_WINDOWS_COMPAT

#ifdef DNNL_DEV_MODE
#define NGEN_ASM
#endif

namespace NGEN_NAMESPACE {
using bfloat16 = dnnl::impl::bfloat16_t;
using half = dnnl::impl::float16_t;
} // namespace NGEN_NAMESPACE

#define NGEN_BFLOAT16_TYPE
#define NGEN_HALF_TYPE

#if (!defined(NDEBUG) || defined(DNNL_DEV_MODE)) \
        && (__cplusplus >= 202002L \
                || (defined(_MSVC_LANG) && _MSVC_LANG >= 202002L))
#if __has_include(<version>)
#include <version>
#if defined(__cpp_lib_source_location) && __cpp_lib_source_location >= 201907L
#define NGEN_ENABLE_SOURCE_LOCATION true
#endif
#endif
#endif

#endif /* header guard */
