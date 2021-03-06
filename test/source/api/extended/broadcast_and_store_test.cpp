//
// MIT License
//
// Copyright (c) 2017-2018 Thibault Martinez and Simon Ninon
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
//

#include <gtest/gtest.h>

#include <iota/api/extended.hpp>
#include <iota/errors/bad_request.hpp>
#include <test/utils/configuration.hpp>
#include <test/utils/constants.hpp>
#include <test/utils/expect_exception.hpp>

TEST(Extended, BroadcastAndStoreTransactionsEmpty) {
  IOTA::API::Extended api(get_proxy_host(), get_proxy_port());

  IOTA::API::Responses::Base res;
  EXPECT_EXCEPTION(res = api.broadcastAndStore({ "" }), IOTA::Errors::BadRequest,
                   "Invalid trytes input")
  EXPECT_GE(res.getDuration(), 0);
}

TEST(Extended, BroadcastAndStoreTransactionsInvalidTrytes) {
  IOTA::API::Extended api(get_proxy_host(), get_proxy_port());

  IOTA::API::Responses::Base res;
  EXPECT_EXCEPTION(res = api.broadcastAndStore({ "INVALIDTRYTES" }), IOTA::Errors::BadRequest,
                   "Invalid trytes input")
  EXPECT_GE(res.getDuration(), 0);
}

TEST(Extended, BroadcastAndStoreTransactionsAlmostInvalidTrytes) {
  IOTA::API::Extended api(get_proxy_host(), get_proxy_port());

  auto tx   = BUNDLE_1_TRX_1_TRYTES;
  tx.back() = '9';
  IOTA::API::Responses::Base res;
  EXPECT_EXCEPTION(res = api.broadcastAndStore({ "INVALIDTRYTES" }), IOTA::Errors::BadRequest,
                   "Invalid trytes input")
  EXPECT_GE(res.getDuration(), 0);
}

TEST(Extended, BroadcastAndStoreTransactionsValidTrytes) {
  IOTA::API::Extended api(get_proxy_host(), get_proxy_port());

  IOTA::API::Responses::Base res;
  EXPECT_NO_THROW(res = api.broadcastAndStore({ BUNDLE_1_TRX_1_TRYTES }));
  EXPECT_GE(res.getDuration(), 0);
}

TEST(Extended, BroadcastAndStoreTransactionsValidMultiTrytes) {
  IOTA::API::Extended api(get_proxy_host(), get_proxy_port());

  IOTA::API::Responses::Base res;
  EXPECT_NO_THROW(res = api.broadcastAndStore({ BUNDLE_1_TRX_1_TRYTES, BUNDLE_1_TRX_2_TRYTES,
                                                BUNDLE_1_TRX_3_TRYTES, BUNDLE_1_TRX_4_TRYTES }));
  EXPECT_GE(res.getDuration(), 0);
}
