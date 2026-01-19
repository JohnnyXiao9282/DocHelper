#pragma once
#include "Document.h"
#include <string>

namespace docstore {

class DocumentSerializer {
public:
    static std::string serialize(const Document& doc);
    static Document deserialize(const std::string& data);
};

} // namespace docstore
