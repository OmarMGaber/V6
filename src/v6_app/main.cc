#include "v6_core/index.h"
#include "v6_core/loader/file_system_loader.h"
#include "v6_core/vocab_store.h"
#include <bits/stdc++.h>

using namespace std;

int main(void) {
  cout << "Starting the index..." << "\n";

  v6_core::FileSystemLoader loader("corpus");
  v6_core::VocabStore store;

  v6_core::Index index(store);
  index.AddDocuments(loader);

  cout << "Indexing completed." << "\n";

  string s;
  while (true) {
    cout << ">> ";
    getline(cin, s);
    if (s == "exit") {
      break;
    }
    auto results = index.Query(s);
    if (results.Size() == 0) {
        std::cerr << "No documents found" << std::endl;
    } else {
      for (auto &ret : results) {
        cout << "Document ID: " << ret.first.Id() << ", Name: " << ret.first.Name() << ", cosine similarity: "
             << ret.second << "\n";
      }
      cout << "Query: " << s << ", Total documents found: " << results.Size() << "\n";
    }
    cout << "\n";
  }
}