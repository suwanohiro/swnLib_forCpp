#include "string.hpp"

using namespace swn;

string swn::string::__createPadding(int maxLength, const string& fillString) const
{
    if (length() > maxLength) return *this;

    std::string padding = "";
    while (padding.length() + length() < maxLength) {
        padding += fillString;
    }
    return padding.substr(0, maxLength - length());
}

string string::padStart(int maxLength, const string& fillString) const
{
    // Ši”[‚³‚ê‚Ä‚¢‚é•¶Žš”‚ªÅ‘å•¶Žš”ˆÈã‚È‚ç‚Îˆ—‚¹‚¸‚»‚Ì‚Ü‚Ü•Ô‚·
    if (length() >= maxLength) return *this;

    const string padding = __createPadding(maxLength, fillString);

    return padding + *this;
}

string swn::string::padEnd(int maxLength, const string& fillString) const
{
    // Ši”[‚³‚ê‚Ä‚¢‚é•¶Žš”‚ªÅ‘å•¶Žš”ˆÈã‚È‚ç‚Îˆ—‚¹‚¸‚»‚Ì‚Ü‚Ü•Ô‚·
    if (length() >= maxLength) return *this;

    const string padding = __createPadding(maxLength, fillString);

    return *this + padding;
}

string swn::string::trim() const
{
    // ¶‘¤‚Ì‹ó”’‚ðíœ
    auto left_trimmed = this->find_first_not_of(" \t\r\n");
    left_trimmed = (left_trimmed == std::string::npos) ? 0 : left_trimmed;

    // ‰E‘¤‚Ì‹ó”’‚ðíœ
    auto right_trimmed = this->find_last_not_of(" \t\r\n");
    right_trimmed = (right_trimmed == std::string::npos) ? this->length() - 1 : right_trimmed;

    // Œ‹‰Ê‚ð•Ô‚·
    return this->substr(left_trimmed, right_trimmed - left_trimmed + 1);
}

std::vector<string> swn::string::split(const string& splitter, int limit) const
{
    std::vector<string> result;

    size_t start = 0;
    size_t end = this->find(splitter);
    bool hasSplitter = (end != std::string::npos);

    while (hasSplitter && (limit == std::string::npos || result.size() < limit - 1)) {
        result.push_back(this->substr(start, end - start));
        start = end + splitter.length();
        end = this->find(splitter, start);

        hasSplitter = (end != std::string::npos);
    }

    end = this->find(splitter, start);
    result.push_back(this->substr(start, end - start));

    return result;
}

string swn::string::replace(const string& searchValue, const string& replaceValue, bool isAll) const
{
    std::regex pattern(searchValue);

    auto type = (isAll) ? std::regex_constants::format_default : std::regex_constants::format_first_only;

    return std::regex_replace(*this, pattern, replaceValue, type);
}
