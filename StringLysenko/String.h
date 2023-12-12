#pragma once
#include <iostream>
#include <string>



class String {
private:
	std::string text;

public:
	String(const std::string& inputText) : text(inputText) {}
	String() {
		this->text = "";
	}
	std::string sortNumbers() {
		std::string digits = "";
		for (int i = 0; i < this->text.length(); i++) {
			if (int(this->text[i])>=48 && int(this->text[i]) <= 57) {
				digits += this->text[i];
			}
		}
		int dInd = 0;
		for (std::size_t i = 0; i < digits.size() - 1; ++i) {
			for (std::size_t j = 0; j < digits.size() - i - 1; ++j) {
				if (digits[j] > digits[j + 1]) {
					std::swap(digits[j], digits[j + 1]);
				}
			}
		}
		for (int i = 0; i < this->text.length(); i++) {
			if (int(this->text[i]) >= 48 && int(this->text[i]) <= 57) {
				this->text[i] = digits[dInd];
				dInd++;
			}
		}
		return this->text;
	}
	String& setString(std::string str) {
		this->text = str;
		return *this;
	}
	std::string getString() {
		return this->text;
	}
};
