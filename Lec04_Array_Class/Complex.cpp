#include "Complex.h"

void main() 
{
    Complex a, b, c;//complex라는 class로 a,b,c,라는 설계도면을 만들어냄. a(real,imag), b(real,imag).... c()다 add print 있는사왕

    a.read("A =");
    b.read("B =");
    c.add(a, b);//c에잇는 add라는 method를 호출
    //c,set(2.5, 10.2); c라는 객체에 set2.5, 10.2 real image 넣어라. 이 realimage는 c의 realimage  
    //c.real =2.5 xx이거 안됨. 
    //c.real =2.5이 되려면 public으로 놔야한다. c를 private로 놓은다는게 뭐지?

    // cpp파일은 많이 잇어도 되;는데 main 함수는 하나 있어야한다.---------------------------26.03.31, 중단점에 대해서 F9 디버그 F5 한줄싱행 F10
    b.print(" B = ");
    c.print(" A+B = ");


  //  return 0; void 는 아무것도 반환하지 않겠다.
}