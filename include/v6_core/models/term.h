// This file will be Deprecated

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
//  File: Term
//  Project: V6
//  Created by Omar on 10/05/2025.
//  Description: Term class for managing terms and their posting lists.
//

#ifndef V6_CORE_MODELS_TERM_H_
#define V6_CORE_MODELS_TERM_H_

#include <ostream>
#include <vector>
#include <v6_core/models/document.h>
#include <v6_core/models/types.h>

namespace v6_core {

class Term {
 private:
  const TermId id_;
  const std::string term_;
  std::vector<DocumentId> posting_list_;

 public:
  Term(const int64_t &id, std::string term);

  [[nodiscard]] inline TermId Id() const;
  [[nodiscard]] inline const std::string &TermName() const;
  [[nodiscard]] inline size_t PostingListSize() const;
  [[nodiscard]] inline const std::vector<DocumentId> &PostingList() const;

  void AddToPostingList(const DocumentId &doc_id);
  void AddToPostingList(const auto &&doc_ids);

  std::vector<DocumentId>::iterator begin();
  std::vector<DocumentId>::iterator end();

  friend std::ostream &operator<<(std::ostream &os, const Term &term);
  bool operator==(const Term &other) const;
};

} // v6_core

#endif //V6_CORE_MODELS_TERM_H_
