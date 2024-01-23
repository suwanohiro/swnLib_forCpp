#pragma once

#include <string>

namespace swn {
	class string : public std::string
	{
	private:
		string __createPadding(int maxLength, const string& fillString);

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
		/// <returns>文字列の長さ</returns>
		size_t length() { return this->size(); }

		/// <summary>
		/// 改行を含めた文字データを取得する
		/// </summary>
		/// <returns>改行を含めた文字データ</returns>
		string addLine() { return *this + "\n"; }

		string padStart(int maxLength, const string& fillString);

		string padEnd(int maxLength, const string& fillString);

		string trim();
	};
}