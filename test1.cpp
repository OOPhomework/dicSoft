#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

class single_word
{
public:
	single_word(){ }
	friend ostream& operator<< (ostream &os,const single_word& T);
	~single_word(){ }
	string name;
	string phonetic_symbol;//yinbiao
	std::string part_of_speech;
	//vector<string> part_of_speech; //cixing
	//vector<string> paraphrase;//shiyi
	vector<string> eg;
};
ostream& operator<< (ostream &os,const single_word& T)
	os <<T.name
		<<" [\\"<<T.phonetic_symbol<<"\\]"
		<<" : "<<endl;
	/*for (int i = 0;i < T.part_of_speech.size();i++)
	{
		os <<i+1<<"."
			<<T.part_of_speech[i]<<" : "
			<<T.paraphrase[i]<<endl;
	}*/
	os <<T.part_of_speech<<endl;
	os<<"eg:\n";
	for (int i = 0;i < T.eg.size()-1;i++)
		os <<T.eg[i]<<endl;
	}
	os <<T.eg[T.eg.size()-1];
	return os;
}
string check_bracket(std::string line,int& i)
	while(line[i] != '[')
    {
        i++;
    }
    int start = ++i;
    int num = 0;
    while(line[i] != ']')
        i++;num++;
    string s = line.substr(start,num);//string's function substr(int a,int b)
                                    //starting get the string's character from index a ,extract b chars
    return s;
single_word print_to_single_word(string line)
	/*single_word the_word;
	int count = 0;
	the_word.name = check_bracket(line,count);
	the_word.phonetic_symbol = check_bracket(line,count);
	string s = check_bracket(line,count);
	//int size = 0;
	the_word.part_of_speech = s;
	
	int index = 0;
	while(line[++count] != '}')
		the_word.eg.push_back(check_bracket(line,count));
		for (int i = 0;i < the_word.eg[index].size();i++)
		{
			if (the_word.eg[index][i] == '|')
				the_word.eg[index][i] = ' ';
		}
		index += 1;
	cout <<"***"<<endl;
	return the_word;*/
	single_word the_word;
		index++;
	return the_word;
int main()
	single_word word;
	word.name = "dkfejif";
	word.phonetic_symbol = "ˌeɪˈem";
	word.part_of_speech = "vt.count,get thisadj.paraphrase2";
	/*word.part_of_speech.push_back("vt");
	word.part_of_speech.push_back("adj");
	word.paraphrase.push_back("count,get this");
	word.paraphrase.push_back("paraphrase2");*/
	word.eg.push_back("this is the first example sentence.");
	word.eg.push_back("this is the second example sentence.");
	cout <<word<<endl;
	single_word wo;
	string s = "{[abrasion][əˈbreɪʒn][n.磨减,磨损,磨损之处][An|implement|with|cutting|edges|or|a|pointed|end|for|boring|holes|in|hard|materials,|usually|by|a|rotating|abrasion|or|repeated|blows;|a|bit.][钻带切割刃或尖端的工具，用于在坚硬材料上钻孔，一般靠旋转磨损或反复击打实现钻孔][A|minor|scratch|or|abrasion.][擦伤一个轻微的擦伤或磨损]}";
	//cout <<s<<endl;
	wo = print_to_single_word(s);
	//cout <<wo.name<<endl;
	cout <<wo<<endl;
	return 0;