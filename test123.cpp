#include <iostream>
#include <algorithm>
#include <string>

struct student {
    std::string name;
    int score;	
};

bool mycompare(student s1, student s2){
   return s1.score > s2.score;
}

int main() {
    student st[4];
    st[0].name = "bob";
    st[0].score = 70;
    st[1].name = "cindy";
    st[1].score = 66;
    st[2].name = "alice";
    st[2].score = 77;
    st[3].name = "alice";
    st[3].score = 76;
    
    std::sort(st, st+4, mycompare);
    std::cout << "sort struct (decreasing):" << std::endl;
    for (student s : st) {
        std::cout << s.name << " " << s.score << std::endl;
    }
    std::cout << std::endl;

    return 0;
}