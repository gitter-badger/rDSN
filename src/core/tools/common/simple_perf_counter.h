/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 Microsoft Corporation
 * 
 * -=- Robust Distributed System Nucleus (rDSN) -=- 
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/*
 * Description:
 *     Header of performance counter ver.simple
 *
 * Revision history:
 *     2015-08-17, zjc95, first version
 *     2015-11-24, zjc95, revised the decription
 *
 */

#pragma once

# include <dsn/tool_api.h>

namespace dsn {
    namespace tools {

        class simple_perf_counter : public perf_counter
        {
        public:
            simple_perf_counter(const char *section, const char *name, dsn_perf_counter_type_t type, const char *dsptr);
            ~simple_perf_counter(void);

            virtual void   increment() { _counter_impl->increment(); }
            virtual void   decrement() { _counter_impl->decrement(); }
            virtual void   add(uint64_t val) { _counter_impl->add(val); }
            virtual void   set(uint64_t val) { _counter_impl->set(val); }
            virtual double get_value() { return _counter_impl->get_value(); }
            virtual double get_percentile(dsn_perf_counter_percentile_type_t type) { return _counter_impl->get_percentile(type); }
            virtual uint64_t* get_samples(/*out*/ int& sample_count) const { return _counter_impl->get_samples(sample_count); }
            virtual uint64_t get_current_sample() const { return _counter_impl->get_current_sample(); }

        private:
            perf_counter *_counter_impl;
        };

    }
}

