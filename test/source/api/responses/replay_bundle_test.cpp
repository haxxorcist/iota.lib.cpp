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

#include <iota/api/responses/replay_bundle.hpp>

TEST(ReplayBundleResponse, DefaultCtorShouldInitFields) {
  const IOTA::API::Responses::ReplayBundle res{};

  EXPECT_EQ(res.getSuccessfully(), std::vector<bool>{});
  EXPECT_EQ(res.getDuration(), 0);
}

TEST(ReplayBundleResponse, CtorShouldInitFields) {
  const IOTA::API::Responses::ReplayBundle res({ true, false, true }, 42);

  EXPECT_EQ(res.getSuccessfully(), std::vector<bool>({ true, false, true }));
  EXPECT_EQ(res.getDuration(), 42);
}

TEST(ReplayBundleResponse, GetSuccessfullyNonConst) {
  IOTA::API::Responses::ReplayBundle res;

  res.getSuccessfully().push_back(true);

  EXPECT_EQ(res.getSuccessfully(), std::vector<bool>({ true }));
  EXPECT_EQ(res.getDuration(), 0);
}

TEST(ReplayBundleResponse, SetSuccessfully) {
  IOTA::API::Responses::ReplayBundle res;

  std::vector<bool> successful = res.getSuccessfully();
  successful.push_back(true);
  res.setSuccessfully(successful);

  EXPECT_EQ(res.getSuccessfully(), std::vector<bool>({ true }));
  EXPECT_EQ(res.getDuration(), 0);
}
