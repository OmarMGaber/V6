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

#include "v6_core/models/document.h"

namespace fs = std::filesystem;

namespace v6_core {

Document::Document(int64_t id, std::string abs_path)
    : id_(id), abs_path_(std::move(abs_path)) {}

double Document::TF(TermId term_id) const {
  auto it = terms_.find(term_id);
  if (it != terms_.end()) {
    return (double)it->second / (double)num_terms_;
  }
  return 0.0;
}

void Document::AddTerm(TermId term_id, int64_t term_freq) {
  terms_[term_id] += term_freq;
  num_terms_ += term_freq;
}
DocumentId Document::Id() const {
    return id_;
}

const std::unordered_map<TermId, int64_t> &Document::Terms() const {
  return terms_;
}

std::string Document::Name() const {
  return fs::path(abs_path_).filename().string();
}

std::string Document::AbsPath() const {
  return fs::path(abs_path_).string();
}

} // v6_core