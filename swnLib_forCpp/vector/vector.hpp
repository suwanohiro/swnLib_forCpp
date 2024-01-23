#pragma once

#include <vector>

namespace swn {

	template <typename T>
	class vector : public std::vector<T>
	{
	public:
		vector() : std::vector<T>() {};

		/// <summary>
		/// 配列の要素数を返す
		/// </summary>
		/// <returns>配列の要素数</returns>
		int length() { return (int)this->size(); };

		operator std::string() const {
			return this;
		}
	};
}