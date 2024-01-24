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
		/// ������̒�����Ԃ�
		/// </summary>
		size_t length() const { return this->size(); }

		/// <summary>
		/// ���s���܂߂������f�[�^���擾����
		/// </summary>
		string addLine() const { return *this + "\n"; }

		/// <summary>
		/// �擪�ɕ������ǉ����Ďw�肵�������ɕύX����
		/// </summary>
		/// <param name="maxLength">������̒���</param>
		/// <param name="fillString">���ߍ��ޕ�����</param>
		string padStart(int maxLength, const string& fillString) const;

		/// <summary>
		/// �����ɕ������ǉ����Ďw�肵�������ɕύX����
		/// </summary>
		/// <param name="maxLength">������̒���</param>
		/// <param name="fillString">���ߍ��ޕ�����</param>
		string padEnd(int maxLength, const string& fillString) const;

		/// <summary>
		/// ������̑O��̋󔒂��폜����
		/// </summary>
		/// <returns></returns>
		string trim() const;

		std::vector<string> split(const string& splitter, int limit = 0) const;

		/// <summary>
		/// �������u������
		/// </summary>
		/// <param name="searchValue">�u���Ώە�����</param>
		/// <param name="replaceValue">�u��������</param>
		/// <param name="isAll">�u���ΏۑS�Ă�u�����邩</param>
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