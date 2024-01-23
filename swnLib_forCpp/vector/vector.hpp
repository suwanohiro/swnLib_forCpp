#pragma once

#include <vector>

namespace swn {

	template <typename T>
	class vector : public std::vector<T>
	{
	public:
		vector() : std::vector<T>() {};

		/// <summary>
		/// �z��̗v�f����Ԃ�
		/// </summary>
		/// <returns>�z��̗v�f��</returns>
		int length() { return (int)this->size(); };

		operator std::string() const {
			return this;
		}
	};
}