#include "string.hpp"

using namespace swn;

string swn::string::__createPadding(int maxLength, const string& fillString)
{
    if (length() > maxLength) return *this;

    std::string padding = "";
    while (padding.length() + length() < maxLength) {
        padding += fillString;
    }
    return padding.substr(0, maxLength - length());
}

string string::padStart(int maxLength, const string& fillString)
{
    // Ši”[‚³‚ê‚Ä‚¢‚é•¶Žš”‚ªÅ‘å•¶Žš”ˆÈã‚È‚ç‚Îˆ—‚¹‚¸‚»‚Ì‚Ü‚Ü•Ô‚·
    if (length() >= maxLength) return *this;

    const string padding = __createPadding(maxLength, fillString);

    return padding + *this;
}

string swn::string::padEnd(int maxLength, const string& fillString)
{
    // Ši”[‚³‚ê‚Ä‚¢‚é•¶Žš”‚ªÅ‘å•¶Žš”ˆÈã‚È‚ç‚Îˆ—‚¹‚¸‚»‚Ì‚Ü‚Ü•Ô‚·
    if (length() >= maxLength) return *this;

    const string padding = __createPadding(maxLength, fillString);

    return *this + padding;
}

string swn::string::trim()
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
