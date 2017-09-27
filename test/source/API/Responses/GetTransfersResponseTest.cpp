//
// MIT License
//
// Copyright (c) 2017 Thibault Martinez
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

#include <API/Responses/getTransfersResponse.hpp>

TEST(GetTransfersResponse, DefaultCtorShouldInitFields) {
  const getTransfersResponse res{};

  EXPECT_EQ(res.getTransfers(), std::vector<Bundle>{});
  EXPECT_EQ(res.getDuration(), 0);
}

TEST(GetTransfersResponse, CtorShouldInitFields) {
  const getTransfersResponse res({ Bundle({ { "addr_trx1", 1, "tag_trx1", 1 } }),
                                   Bundle({ { "addr_trx2", 2, "tag_trx2", 2 } }),
                                   Bundle({ { "addr_trx3", 3, "tag_trx3", 3 } }) },
                                 42);

  EXPECT_EQ(res.getTransfers(),
            std::vector<Bundle>({ Bundle({ { "addr_trx1", 1, "tag_trx1", 1 } }),
                                  Bundle({ { "addr_trx2", 2, "tag_trx2", 2 } }),
                                  Bundle({ { "addr_trx3", 3, "tag_trx3", 3 } }) }));
  EXPECT_EQ(res.getDuration(), 42);
}

TEST(GetTransfersResponse, GetTransfersNonConst) {
  getTransfersResponse res;

  res.getTransfers().push_back(Bundle({ { "addr_trx1", 1, "tag_trx1", 1 } }));

  EXPECT_EQ(res.getTransfers(),
            std::vector<Bundle>({ Bundle({ { "addr_trx1", 1, "tag_trx1", 1 } }) }));
  EXPECT_EQ(res.getDuration(), 0);
}

TEST(GetTransfersResponse, SetTransfers) {
  getTransfersResponse res;

  std::vector<Bundle> transfers = res.getTransfers();
  transfers.push_back(Bundle({ { "addr_trx1", 1, "tag_trx1", 1 } }));
  res.setTransfers(transfers);

  EXPECT_EQ(res.getTransfers(),
            std::vector<Bundle>({ Bundle({ { "addr_trx1", 1, "tag_trx1", 1 } }) }));
  EXPECT_EQ(res.getDuration(), 0);
}
