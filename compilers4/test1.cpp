void ok(){}
class A {
	public:
		int hello;
		void k();
};
void A::k(){}
int main(){
	A e;
	e.hello = 2;
	e.k();
	return 0;
}
