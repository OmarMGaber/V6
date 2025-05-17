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

#include "v6_core/models/term.h"

namespace std {
template<>
struct hash<v6_core::Term> {
  size_t operator()(const v6_core::Term &term) const {
    return hash<v6_core::TermId>()(term.Id());
  }
};
}

namespace v6_core {

Term::Term(const int64_t &id, std::string term)
    : id_(id), term_(std::move(term)) {}

const std::string &Term::TermName() const {
  return term_;
}

TermId Term::Id() const {
  return id_;
}

size_t Term::PostingListSize() const {
  return posting_list_.size();
}

const std::vector<DocumentId> &Term::PostingList() const {
  return posting_list_;
}

// A lazy reminder
[[warning("Insert Sorted and neglect duplicates")]] // assuming sorted posting list
void Term::AddToPostingList(const DocumentId &doc_id) {
  posting_list_.push_back(doc_id);
}

[[warning("Insert Sorted and neglect duplicates")]]
void Term::AddToPostingList(const auto &&doc_ids) {
  posting_list_.insert(posting_list_.end(), doc_ids.begin(), doc_ids.end());
}

std::vector<DocumentId>::iterator Term::begin() {
  return posting_list_.begin();
}

std::vector<DocumentId>::iterator Term::end() {
  return posting_list_.end();
}

std::ostream &operator<<(std::ostream &os, const Term &term) {
  os << "Term ID: " << term.id_ << ", Term: " << term.term_ << ", Posting List Size: " << term.posting_list_.size();
  os << ", Posting List: [ ";
  for (const auto &doc_id : term.posting_list_) {
    os << doc_id << " ";
  }
  os << "]\n";
  return os;
}

bool Term::operator==(const Term &other) const {
  return id_ == other.id_ && term_ == other.term_;
}
} // v6_core