//  Name: Jacob Bahn
//  Assignment number: 4
//  Assignment: Huffman Coding Tree
//  File name: huffman.cpp
//  Date last modified: 
//  Honor statement: I have neither given nor received any unauthorized help on this assignment. 
#include <string>
#include <iostream>
#include <map>
#include <queue>


class HuffmanNode {
public:
	int value;
	float percentage;
	char letter;
	HuffmanNode* left;
	HuffmanNode* right;
	HuffmanNode(float percentage, char letter, HuffmanNode* left, HuffmanNode* right) :
		percentage(percentage),  letter(letter), left(left), right(right){}
	/*HuffmanNode(int percentage, HuffmanNode* left, HuffmanNode* right) :
		percentage(percentage), left(left), right(right){}*/

	int get_value() const {
		return value;
	}
};

struct Comparer {
	bool operator()(HuffmanNode* h1, HuffmanNode* h2) {
		return h1->get_value() > h2->get_value();
	}
};


HuffmanNode* generateTree(std::map<char, int> freq, int total) {
	std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, Comparer> queue;
	for (auto pair = freq.cbegin(); pair != freq.cend(); pair++) {
		queue.push(new HuffmanNode((static_cast<float>((*pair).second) / total), (*pair).first, nullptr, nullptr));
	}

	while (queue.size() > 1) {
		HuffmanNode* left = queue.top();
		queue.pop();
		HuffmanNode* right = queue.top();
		queue.pop();

		HuffmanNode* node = new HuffmanNode((left->percentage + right->percentage), '\0' , left, right);
		//node->left = left;
		//node->right = right;
		queue.push(node);
	}
	return queue.top();
}

void tab(int n) {
	while (n-- > 0) {
		std::cout << "   ";
	}
}

void draw_tree(HuffmanNode* h, int depth, char link) {
	if (h) {
		draw_tree(h->right, depth + 1, '/');
		tab(depth);
		if (h->letter) {
			std::cout << link << ' ' << '(' << h->letter << ':' << h->percentage << ')' << '\n';
		}
		else {
			std::cout << link << ' ' << '('<< h->percentage << ')' << '\n';
		}
		
		draw_tree(h->left, depth + 1, '\\');
	}
}

void draw_tree(HuffmanNode* h) {
	draw_tree(h, 0, '-');
}

void printCode(HuffmanNode* h, std::string currentCode = "") {
	if (h) {
		printCode(h->right, currentCode + "1");
		if (h->letter) {
			std::cout << h->letter << " : " << currentCode << '\n';
		}
		printCode(h->left, currentCode + "0");
	}
}

std::string displayText() {
	std::string text, line;
	
	while (std::getline(std::cin, line)) {
		text += line + "\n";
	}
	std::cout << text << "\n";
	return text;
}

void displayFreq(std::map<char, int> freq, int total) {
	std::cout << "\n";
	for (auto pair = freq.cbegin(); pair != freq.cend(); pair++) {
		std::cout << (*pair).first << ": " << (*pair).second << "\n";
	}
	std::cout << "Total = " << total << "\n";
	std::cout << "\n" << "---------------------------------" << "\n";
}


std::map<char, int> getFrequency(std::string wholeText, int& total) {
	std::map<char, int> freq;
	std::string text = wholeText;
	std::cout << "Counts:" << "\n";
	std::cout << "-------";
	for (size_t i = 0; i < text.length(); i++) {
		if (isalpha(text[i])) {
			freq[toupper(text[i])]++;
			total++;
		}
	}
	return freq;
}

int main() {
	int total = 0;
	std::string text = displayText();
	std::map<char, int> freq = getFrequency(text, total);
	displayFreq(freq, total);
	
	HuffmanNode* tree = generateTree(freq, total);
	draw_tree(tree);
	printCode(tree);

	std::cout << "end";
}