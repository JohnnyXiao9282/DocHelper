#include "core/DocumentSerializer.h"
#include <sstream>
#include <algorithm>

namespace docstore {

// Simple plain text serialization: id|title|path|tags(comma-separated)|created|content
std::string DocumentSerializer::serialize(const Document& doc) {
    std::ostringstream oss;
    oss << doc.id << "|" << doc.title << "|" << doc.path << "|";
    for (size_t i = 0; i < doc.tags.size(); ++i) {
        oss << doc.tags[i];
        if (i + 1 < doc.tags.size()) oss << ",";
    }
    oss << "|" << doc.created << "|" << doc.content;
    return oss.str();
}

Document DocumentSerializer::deserialize(const std::string& data) {
    std::istringstream iss(data);
    Document doc;
    std::string tagsStr;
    std::string field;
    // id
    std::getline(iss, field, '|');
    doc.id = std::stoi(field);
    // title
    std::getline(iss, doc.title, '|');
    // path
    std::getline(iss, doc.path, '|');
    // tags
    std::getline(iss, tagsStr, '|');
    std::istringstream tagsStream(tagsStr);
    std::string tag;
    while (std::getline(tagsStream, tag, ',')) {
        if (!tag.empty()) doc.tags.push_back(tag);
    }
    // created
    std::getline(iss, field, '|');
    doc.created = static_cast<std::time_t>(std::stoll(field));
    // content
    std::getline(iss, doc.content);
    return doc;
}

} // namespace docstore
