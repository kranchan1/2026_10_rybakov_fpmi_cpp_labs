#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <fstream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <locale>

std::time_t Now() {
	auto now = std::chrono::system_clock::now();
	return std::chrono::system_clock::to_time_t(now);
}

auto FormatTime(time_t time, bool is_utc_format) {
#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable: 4996)
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

	return is_utc_format
		? std::put_time(std::gmtime(&time), "%x %X")
		: std::put_time(std::localtime(&time), "%x %X");

#if defined(_MSC_VER)
#pragma warning(pop)
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
}

bool IsEmptyFile(std::ifstream& fin) {
	return fin.peek() == std::fstream::traits_type::eof();
}

void CheckInputFile(std::ifstream& fin, const std::string& filename) {
	if (!fin.is_open()) {
		throw "Error: could not open file \"" + filename + "\"!!!!!";
	}
	if (IsEmptyFile(fin)) {
		throw "Error: file \"" + filename + "\" is empty!!!";
	}
}

void CheckOutputFile(std::ofstream& fout, const std::string& filename) {
	if (!fout.is_open()) {
		throw "Error: could not open file \"" + filename + "\"!!!!!";
	}
}
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
			return true;
		}
	}
	return false;
}

std::string CreateOutputStr(const std::string& text, const std::string& delimeters) {
	std::vector<std::string> lowercase_words;
	std::string output = text;
	std::string::size_type beg_ind = output.find_first_not_of(delimeters, 0);
	std::string::size_type end_ind = output.find_first_of(delimeters, beg_ind);

	while (beg_ind != std::string::npos) {
		std::string word = output.substr(beg_ind, end_ind - beg_ind);
		std::string low_word = ToLower(word);

		if (!(IsContain(low_word, lowercase_words))) {
			lowercase_words.push_back(low_word);
			beg_ind = output.find_first_not_of(delimeters, end_ind);
		}
		else {
			output.erase(beg_ind, end_ind - beg_ind);
			beg_ind = output.find_first_not_of(delimeters, beg_ind);
		}

		end_ind = output.find_first_of(delimeters, beg_ind);
	}
	return output;
}

int main() {
	std::cout.imbue(std::locale("ru_RU.UTF-8"));
	std::string delimeters = " ,.!?/;()\"\\";
	const std::string input_filename = "input.txt";
	const std::string output_filename = "output.txt";
	const std::string log_filename = "log.txt";

	std::ofstream flog{log_filename};
	if (!flog.is_open()) {
		std::cerr << "ERROR: could not open log file \"" << log_filename << "\"\n";
		return 1;
	}
	try {

		std::ifstream fin{input_filename};
		flog << FormatTime(Now(), false) << " | " << "opening file \"" << input_filename << "\"\n";
		CheckInputFile(fin, input_filename);
		flog << FormatTime(Now(), false) << " | " << "file \"" << input_filename << "\" has been opened successfully\n";

		std::ofstream fout{output_filename};
		flog << FormatTime(Now(), false) << " | " << "opening file \"" << output_filename << "\"\n";
		CheckOutputFile(fout, output_filename);
		flog << FormatTime(Now(), false) << " | " << "file \"" << output_filename << "\" has been opened successfully\n";

		std::string line;
		flog << FormatTime(Now(), false) << " | " << "reading lines from \"" << input_filename << "\"\n";
		while (std::getline(fin, line)) {
			flog << FormatTime(Now(), false) << " | " << "got line: \"" << line << "\"\n";
			flog << FormatTime(Now(), false) << " | " << "finding repeats in line and deleting them\n";
			std::string output = CreateOutputStr(line, delimeters);
			flog << FormatTime(Now(), false) << " | " << "redact line: \"" << output << "\"\n";
			flog << FormatTime(Now(), false) << " | " << "writing line to \"" << output_filename << "\"\n";
			fout << output << '\n';
			
		}

		fin.close();
		fout.close();
		flog << FormatTime(Now(), false) << " | " << "program has ended with code " << 0 << '\n';
	}
	catch (const std::string& msg) {
		flog << FormatTime(Now(), false) << " | " << msg << '\n';
		flog << FormatTime(Now(), false) << " | " << "program has ended with code " << 1 << '\n';
	}
}

//flog << FormatTime(Now(), false) << " | " << "\n";