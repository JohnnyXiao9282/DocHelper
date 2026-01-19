#pragma once
#include "Document.h"
#include <unordered_map>
#include <memory>
#include <vector>

namespace docstore {

class DocumentStore {
public:
    DocumentStore();
    int addDocument(const Document& doc);
    bool removeDocument(int id);
    Document* getDocument(int id);
    std::vector<Document*> searchByTag(const std::string& tag);
    std::vector<Document*> getAllDocuments();
private:
    std::unordered_map<int, std::unique_ptr<Document>> documents_;
    int nextId_ = 1;
};

} // namespace docstore
