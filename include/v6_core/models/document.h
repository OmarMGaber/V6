// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
//  File: document
//  Project: V6
//  Created by Omar on 06/05/2025.
//  Description: A model for a document in the V6 search engine.
//

#ifndef V6_CORE_MODELS_DOCUMENT_H_
#define V6_CORE_MODELS_DOCUMENT_H_

#include <filesystem>
#include <string>
#include <unordered_map>
#include <v6_core/models/term.h>
#include <v6_core/models/types.h>

namespace v6_core {

class Document {
 private:
  const DocumentId id_;
  const std::string abs_path_;
  std::unordered_map<TermId, int64_t> terms_; // term_id -> term frequency
  int64_t num_terms_ = 0;
 public:
  explicit Document(int64_t id, std::string abs_path);

  [[nodiscard]]  std::string Name() const ;
  [[nodiscard]]  std::string AbsPath() const ;
  [[nodiscard]]  DocumentId Id() const;
  [[nodiscard]] double TF(TermId term_id) const; // TF(term_id, this_doc)
  [[nodiscard]] const std::unordered_map<TermId, int64_t> &Terms() const;

  void AddTerm(TermId term_id, int64_t term_freq);
};

} // v6_core

#endif //V6_CORE_MODELS_DOCUMENT_H_
