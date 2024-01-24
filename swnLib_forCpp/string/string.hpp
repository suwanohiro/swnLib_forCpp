#pragma once

#include <string>
#include <vector>
#include <regex>

namespace swn {
	class string : public std::string
	{
	private:
		string __createPadding(int maxLength, const string& fillString) const;

	public:
		string(): std::string() {}
		string(const std::string& str) : std::string(str) {}
		string(char* str) : std::string(str) {}
		string(const char* str) : std::string(str) {}
		string(int num) : std::string(std::to_string(num)) {}
		string(float num) : std::string(std::to_string(num)) {}
		string(double num) : std::string(std::to_string(num)) {}

		/// <summary>
		/// 文字列の長さを返す
		/// </summary>
		size_t length() const { return this->size(); }

		/// <summary>
		/// 改行を含めた文字データを取得する
		/// </summary>
		string addLine() const { return *this + "\n"; }

		/// <summary>
		/// 先頭に文字列を追加して指定した長さに変更する
		/// </summary>
		/// <param name="maxLength">文字列の長さ</param>
		/// <param name="fillString">埋め込む文字列</param>
		string padStart(int maxLength, const string& fillString) const;

		/// <summary>
		/// 末尾に文字列を追加して指定した長さに変更する
		/// </summary>
		/// <param name="maxLength">文字列の長さ</param>
		/// <param name="fillString">埋め込む文字列</param>
		string padEnd(int maxLength, const string& fillString) const;

		/// <summary>
		/// 文字列の前後の空白を削除する
		/// </summary>
		/// <returns></returns>
		string trim() const;

		std::vector<string> split(const string& splitter, int limit = 0) const;

		/// <summary>
		/// 文字列を置換する
		/// </summary>
		/// <param name="searchValue">置換対象文字列</param>
		/// <param name="replaceValue">置換文字列</param>
		/// <param name="isAll">置換対象全てを置換するか</param>
		string replace(const string& searchValue, const string& replaceValue, bool isAll = false) const;

		operator const char* () {
			return c_str();
		}

		operator char* () {
			return const_cast<char*>(c_str());
		}

		operator std::string() {
			return *this;
		}
	};
}