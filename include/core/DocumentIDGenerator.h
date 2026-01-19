#pragma once

namespace docstore {

class DocumentIDGenerator {
public:
    DocumentIDGenerator() : currentId_(1) {}
    int next() { return currentId_++; }
    void reset(int start = 1) { currentId_ = start; }
private:
    int currentId_;
};

} // namespace docstore
