#include "core/DocumentSerializer.h"
#include <cassert>
#include <iostream>

using namespace docstore;

void testSerializeDeserialize() {
    Document doc;
    doc.id = 42;
    doc.title = "Sample";
    doc.path = "/tmp/sample.txt";
    doc.tags = {"alpha", "beta"};
    doc.created = 1234567890;
    doc.content = "Hello, serialization!";

    std::string serialized = DocumentSerializer::serialize(doc);
    Document deserialized = DocumentSerializer::deserialize(serialized);

    assert(deserialized.id == doc.id);
    assert(deserialized.title == doc.title);
    assert(deserialized.path == doc.path);
    assert(deserialized.tags == doc.tags);
    assert(deserialized.created == doc.created);
    assert(deserialized.content == doc.content);
    std::cout << "testSerializeDeserialize passed\n";
}

int main() {
    testSerializeDeserialize();
    std::cout << "All DocumentSerializer tests passed!\n";
    return 0;
}
