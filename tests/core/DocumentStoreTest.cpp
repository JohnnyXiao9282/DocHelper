#include "core/DocumentStore.h"
#include <cassert>
#include <iostream>

using namespace docstore;

void testAddAndGet() {
    DocumentStore store;
    Document doc;
    doc.title = "Test Document";
    doc.content = "Hello, world!";
    int id = store.addDocument(doc);
    Document* fetched = store.getDocument(id);
    assert(fetched != nullptr);
    assert(fetched->title == "Test Document");
    assert(fetched->content == "Hello, world!");
    std::cout << "testAddAndGet passed\n";
}

void testRemove() {
    DocumentStore store;
    Document doc;
    int id = store.addDocument(doc);
    assert(store.getDocument(id) != nullptr);
    assert(store.removeDocument(id));
    assert(store.getDocument(id) == nullptr);
    std::cout << "testRemove passed\n";
}

void testSearchByTag() {
    DocumentStore store;
    Document doc1, doc2;
    doc1.tags = {"tag1", "tag2"};
    doc2.tags = {"tag2", "tag3"};
    int id1 = store.addDocument(doc1);
    int id2 = store.addDocument(doc2);
    auto results = store.searchByTag("tag2");
    assert(results.size() == 2);
    results = store.searchByTag("tag3");
    assert(results.size() == 1 && results[0]->id == id2);
    std::cout << "testSearchByTag passed\n";
}

void testGetAllDocuments() {
    DocumentStore store;
    Document doc1, doc2;
    store.addDocument(doc1);
    store.addDocument(doc2);
    auto allDocs = store.getAllDocuments();
    assert(allDocs.size() == 2);
    std::cout << "testGetAllDocuments passed\n";
}

int main() {
    testAddAndGet();
    testRemove();
    testSearchByTag();
    testGetAllDocuments();
    std::cout << "All DocumentStore tests passed!\n";
    return 0;
}
