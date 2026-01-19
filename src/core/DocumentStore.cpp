#include "core/DocumentStore.h"
#include <algorithm>

namespace docstore {

DocumentStore::DocumentStore() {}

int DocumentStore::addDocument(const Document& doc) {
    int id = nextId_++;
    documents_[id] = std::make_unique<Document>(doc);
    documents_[id]->id = id;
    return id;
}

bool DocumentStore::removeDocument(int id) {
    return documents_.erase(id) > 0;
}

Document* DocumentStore::getDocument(int id) {
    auto it = documents_.find(id);
    if (it != documents_.end()) {
        return it->second.get();
    }
    return nullptr;
}

std::vector<Document*> DocumentStore::searchByTag(const std::string& tag) {
    std::vector<Document*> result;
    for (auto& [id, docPtr] : documents_) {
        if (std::find(docPtr->tags.begin(), docPtr->tags.end(), tag) != docPtr->tags.end()) {
            result.push_back(docPtr.get());
        }
    }
    return result;
}

std::vector<Document*> DocumentStore::getAllDocuments() {
    std::vector<Document*> result;
    for (auto& [id, docPtr] : documents_) {
        result.push_back(docPtr.get());
    }
    return result;
}

} // namespace docstore
