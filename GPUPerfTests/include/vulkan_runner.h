// Copyright (c) 2021 - 2022, Nemes <nemes@nemez.net>
// SPDX-License-Identifier: MIT
// 
// MIT License
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software andassociated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, andto permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
// 
// The above copyright notice andthis permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef VULKAN_RUNNER_H
#define VULKAN_RUNNER_H

#ifdef __cplusplus
extern "C" {
#endif

typedef test_status(vulkan_test_main)(vulkan_physical_device *device, void *config_data);

typedef struct vulkan_runner_context_t {
    vulkan_test_main *entrypoint;
    void *config_data;
    uint32_t version;
    const char *name;
    bool graphical;
} vulkan_runner_context;

test_status VulkanRunnerRegisterTests();
test_status VulkanRunnerRegisterTest(vulkan_test_main *entrypoint, void *config_data, const char *const test_name, uint32_t test_version, bool graphical_context);

#ifdef __cplusplus
}
#endif
#endif