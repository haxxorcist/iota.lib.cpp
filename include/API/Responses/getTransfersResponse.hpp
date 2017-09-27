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

#pragma once

#include <vector>

#include <API/Responses/genericResponse.hpp>
#include <Model/Bundle.hpp>
#include <Type/Trinary.hpp>

/*
 * getTransfer API call response.
 */
class getTransfersResponse : public genericResponse {
public:
  /**
   * default ctor
   */
  getTransfersResponse() = default;

  /**
   * full init ctor
   */
  getTransfersResponse(const std::vector<Bundle>& transferBundle, long duration);

  /**
   * default dtor
   */
  ~getTransfersResponse() = default;

public:
  /**
   * @return The transfers.
   */
  const std::vector<Bundle>& getTransfers() const;

  /**
   * @return The transfers (non const version).
   */
  std::vector<Bundle>& getTransfers();

  /**
   * @param transfers new vector of transfers for getTransfers
   */
  void setTransfers(const std::vector<Bundle>& transfers);

private:
  std::vector<Bundle> transferBundle_;
};
