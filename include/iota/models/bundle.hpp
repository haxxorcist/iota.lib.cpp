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

#pragma once

#include <memory>
#include <vector>

#include <iota/crypto/i_sponge.hpp>
#include <iota/models/transaction.hpp>
#include <iota/types/trytes.hpp>

namespace IOTA {

namespace Models {

/**
 * Bundle model.
 */
class Bundle {
public:
  /**
   * Default ctor.
   */
  Bundle() = default;
  /**
   * Default dtor.
   */
  ~Bundle() = default;

  /**
   * Initializes a new instance of the Bundle class with a list of transactions.
   *
   * @param transactions transactions belonging to the same bundle.
   */
  explicit Bundle(const std::vector<Models::Transaction>& transactions);

public:
  /**
   * @return Bundle transactions.
   */
  const std::vector<Models::Transaction>& getTransactions() const;

  /**
   * Non-const getTransactions.
   *
   * @return Bundle transactions.
   */
  std::vector<Models::Transaction>& getTransactions();

  /**
   * @return The length of the bundle.
   */
  std::size_t getLength() const;

  /**
   * @return whether the bundle is empty or not.
   */
  bool empty() const;

public:
  /**
   * Adds a bundle entry.
   *
   * @param signatureMessageLength Length of the signature message.
   * @param address                The address.
   * @param value                  The value.
   * @param tag                    The tag.
   * @param timestamp              The timestamp.
   */
  void addTransaction(int32_t signatureMessageLength, const Types::Trytes& address, int64_t value,
                      const Types::Trytes& tag, int64_t timestamp);

  /**
   * Adds a bundle entry.
   *
   * @param transaction Transaction to be added to the bundle.
   */
  void addTransaction(const Transaction& transaction);

  /**
   * Finalizes the bundle using the specified curl implementation.
   *
   * @param customSponge The custom sponge.
   */
  void finalize(const std::shared_ptr<IOTA::Crypto::ISponge>& customSponge = nullptr);

  /**
   * Adds the trytes.
   *
   * @param signatureFragments The signature fragments.
   */
  void addTrytes(const std::vector<Types::Trytes>& signatureFragments);

  /**
   * Normalized the bundle.
   *
   * @param bundleHash The bundle hash.
   * @return normalizedBundle A normalized bundle hash.
   */
  std::vector<int8_t> normalizedBundle(const Types::Trytes& bundleHash);

public:
  /**
   * @param rhs An object to compare with this object.
   * @return whether the current bundle occured before the given one.
   */
  bool operator<(const Bundle& rhs) const;

  /**
   * @param rhs An object to compare with this object.
   * @return whether the current bundle occured after the given one.
   */
  bool operator>(const Bundle& rhs) const;

  /**
   * @param rhs An object to compare with this object.
   * @return whether the current bundle is the same as the given one.
   */
  bool operator==(const Bundle& rhs) const;

  /**
   * @param rhs An object to compare with this object.
   * @return whether the current bundle is different from the given one.
   */
  bool operator!=(const Bundle& rhs) const;

private:
  /**
   * Bundle's transactions.
   */
  std::vector<Models::Transaction> transactions_;
};

}  // namespace Models

}  // namespace IOTA
