#include <iostream>
#include <vector>
#include <string>
#include <cctype>

std::string ToLower(const std::string& word) {
	std::string lowercase_word;
	for (size_t i = 0; i < word.size(); ++i) {
		char ch = word[i];
		ch = static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
		lowercase_word += ch;
	}
	return lowercase_word;
}

bool IsContain(const std::string& low_word, const std::vector<std::string>& lowercase_words) {
	for (size_t i = 0; i < lowercase_words.size(); ++i) {
		if (low_word == lowercase_words[i]) {
			return 1;
		}
	}
	return 0;
}

std::string SeparateVector(const std::vector<std::string>& vect_words) {
	if (vect_words.empty()) return "";
	std::string final_str;
	for (size_t i = 0; i + 1 < vect_words.size(); ++i) {
		final_str += vect_words[i];
		final_str += ' ';
	}
	final_str += vect_words[vect_words.size() - 1];
	return final_str;
}

std::string CreateOutputStr(const std::string& text, const std::string& delimeters) {
	std::vector<std::string> unique_words;
	std::vector<std::string> lowercase_words;
	std::string::size_type beg_ind = text.find_first_not_of(delimeters, 0);
	std::string::size_type end_ind = text.find_first_of(delimeters, beg_ind);
	while (beg_ind != std::string::npos) {
		std::string word = text.substr(beg_ind, end_ind - beg_ind);
		if (!word.empty()) {
			std::string low_word = ToLower(word);
			if (!(IsContain(low_word, lowercase_words))) {
				unique_words.push_back(word);
				lowercase_words.push_back(low_word);
			}
		}
		beg_ind = text.find_first_not_of(delimeters, end_ind);
		end_ind = text.find_first_of(delimeters, beg_ind);
	}
	std::string output = SeparateVector(unique_words);
	return output;
}

int main() {
	setlocale(LC_ALL, "rus");
	std::string delimeters, input;
	std::cout << "Введите символы-разделители: ";
	getline(std::cin, delimeters);
	if (delimeters.empty()) {
		delimeters = " ,.!?/;()\"\\";
	}
	std::cout << "Введите строку: ";
	getline(std::cin, input);
	std::string output = CreateOutputStr(input, delimeters);
	std::cout << output;
	return 0;
}