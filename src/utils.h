//This is a part of tct, tct is a tool for counting text file.
//Copyright (C) 2016  Harry Leong(https://github.com/HarryLeong/tct)

//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

//You should have received a copy of the GNU General Public License
//along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef TCT_utils
#define TCT_utils

#include <stdio.h>
#include <string>

namespace tct {
	
	bool isAlpha(char c);

	bool starts_with(std::string const &a, std::string const &b);

	struct AutoClose
	{
		~AutoClose();
		AutoClose(FILE *f) : fFile(nullptr) { setFile(f); }
		AutoClose() : fFile(nullptr) { setFile(nullptr); }
		void setFile(FILE *f) { fFile =f; }
	private:
		FILE *fFile;
	};

	template< class I>
	struct Range {
		Range(I b, I e) { _begin = b, _end = e; }		
		I begin() { return _begin; }		
		I end() { return _end; }
	private:
		I _begin;
		I _end;
	};

	template< class I>
	Range<I> range(I begin, I end)
	{
		return Range<I>(begin, end);
	}

	template<class R, class T >
	bool contain(R const &range, T const &val)
	{
		return std::find(range.begin(), range.end(), val) != range.end();
	}

}

#endif
