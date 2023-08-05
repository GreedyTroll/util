#include <string>
#include <sstream>
#include <vector>
#include <iterator>

/**
 * Splits the string into tokens with given delimiter
 * @param s string to be tokenized
 * @param delimiter character as the delimiter
 * @return vector of strings
*/

std::vector<std::string> split(const std::string& s, char delimiter) {
    std::istringstream iss(s);
    std::string item;
    std::vector<std::string> res;
    while(std::getline(iss, item, delimiter)) {
        if(item.size() > 0 && !(item.size() == 1 && item.at(0) == delimiter ))
            res.push_back(item);
    }
    return res;
}

/**
 * remove leading and tailing spaces of a string
 * @param s String reference to modify
*/
void removeSpaces(std::string& s) {
    if (s.size() == 0) return;
    int i = 0;
    while(i < s.size()) {
        if(s.at(i) == ' ') {
            i++;
        }
        else break;
        if(i == s.size()) {
            s = "";
            return;
        }
    }
    int j = s.size() - 1;
    while(j >= 0) {
        if(s.at(j) == ' ' || s.at(j) == 0x0D) { // remove end of string char
            j--;
        }
        else break;
    }
    if(i >= j) {
        s = "";
        return;
    }
    s = s.substr(i, j - i + 1);
}

const bool contains(const std::string& str, char c) {
	for(int i = 0; i < str.size(); ++i) {
		if(str.at(i) == c) return true;
	}
	return false;
}

std::vector<std::string> split(std::string str, std::string delims) {
	std::vector<std::string> v;
	std::vector<char> tmpString;
	for(int i = 0; i < str.size(); ++i) {
		char c = str.at(i);
		if(contains(delims, c)) {
			if(tmpString.size() > 0) {
				std::string token(tmpString.begin(), tmpString.end());
				v.push_back(token);
				tmpString.clear();
			}
		}
		else {
			tmpString.push_back(c);
		}
	}
	if(!tmpString.empty()) {
		std::string token(tmpString.begin(), tmpString.end());
		v.push_back(token);
	}
	return v;
}

