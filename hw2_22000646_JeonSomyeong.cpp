#include <iostream>

using namespace std;

class weight{
  public:
    int kg, gram;
    void set_weight(int kg, int gram){
      this->kg=kg;
      this->gram=gram;
    }
    weight add_weight(weight w1, weight w2);
    int get_weight(){
      return kg*1000+gram;
    }
    bool less_than(weight w1, weight w2);
};

weight add_weight(weight w1, weight w2){
      weight rst;
      rst.kg = w1.kg+w2.kg+(w1.gram+w2.gram)/1000;
      rst.gram = (w1.gram+w2.gram)%1000;
      return rst;
}

bool less_than(weight w1, weight w2){
      if(w1.get_weight()<w2.get_weight()) return true;
      else return false;
}

int main(){

  weight  w1, w2, w3;  // weight라는 class object 3개 생성

  w1.set_weight(3, 400);  // w1을 3kg 400 g으로 
  w2.set_weight(2, 700);  // w2을 2kg 700 g으로 
  w3 = add_weight(w1, w2); 
  cout << w3.get_weight() << "grams\n" ;
  if (less_than(w1, w2))  cout << "yes.\n"; 
  else cout << "no. \n";
}