#include <iostream>
#include<fstream>
#include<string>
#include <sstream>
using namespace std;

class node{
    string     charstring;
    string code;
    int prob;
    node* left;
    node* right;
    node* next;
    node* head;

    public:
    node(string c, int x){
        left=NULL;
        right=NULL;
        next=NULL;
        charstring=c;
        prob=x;}
    node(int x){
        next=NULL;
        prob=x;
	}
	string getcode(){return code;}
	node* setcode(string c){code=c;	} 
    node* getnext(){return next;}
    node* getleft(){return left;}
    node* getright(){return right;}
    node* setleft(node* l){left = l;}
    node* setright(node* r){right=r;}
    void setnext(node* n){next = n;}
    string getcharstring(){return charstring;}
    void setcharstring(string s){charstring=s;}
    int getprob(){return prob;}
    void setprob(int x){prob=x;}
};
class LinkedList{
	public:			
		LinkedList(){};
void insertionSort(node *x,node *input){
	if(x->getnext()==NULL){
	   x->setnext(input);}
	else {
	   while(x->getnext()->getnext()!=NULL && input->getprob()>(x->getnext()->getprob()))
		 x=x->getnext();
	   if(input->getprob()<=(x->getnext()->getprob())){
		  input->setnext(x->getnext());
	      x->setnext(input);
	}else{
		x->getnext()->setnext(input);
	 }
	}
}

void print(node *x){
    node* next=x;
    next=next->getnext();
    while(next!=NULL){
        cout<<"("<<next->getcharstring()<<","<<next->getprob()<<")->";
        next=next->getnext();
    }
    cout<<"null";
    }    	
};	
    void printNode(node *node){
       if (node->getleft()!=NULL)
       cout<<"Current at ("<<node->getcharstring()<<", "<<node->getprob()<<", \""<<node->getcode()<<"\"):: left ("   <<(node->getleft())->getcharstring()<<", "<<(node->getleft())->getprob()<<"):: right ("<<(node->getright())->getcharstring()<<", "<<(node->getright())->getprob()<<") "<<endl;
       else
       cout<<"("<<node->getcharstring()<<", "<<node->getprob()<<", \""<<node->getcode()<<"\"):: left (NULL) :: right (NULL) "<<endl;    
 	}
void tree(node *n,LinkedList list){
	while(n->getnext()->getnext()!=NULL){
		node *left=n->getnext();
		node *right=left->getnext();
		string s=left->getcharstring()+right->getcharstring();
		int p=left->getprob()+right->getprob();
		node *x=new node(s,p); 
		n->setnext(n->getnext()->getnext()->getnext());
		x->setleft(left);
		x->setright(right);
		printNode(x);
		right->setnext(NULL);
		left->setnext(NULL);
		list.print(n);
		cout<<endl;
	    list.insertionSort(n,x);
		list.print(n);
		cout<<""<<endl;
	}
}
void printer(string str){
	int length=7-str.size();
	cout<<"|   "<<str;
	for(int x=0;x<length;x++){
	cout<<" ";
	}
}
string conver(int number){
	ostringstream convert;
	convert<<number;
	return convert.str();
}
void table(node *tree){
	printer(tree->getcharstring());
	printer(conver(tree->getprob()));
	printer(tree->getcode());
	printer(conver(tree->getcode().size()));
	printer(conver(tree->getprob()*(tree->getcode().size())));
	cout<<"   |\n";
	
}

void huffmanTree(node *node,string c){

	if (node->getleft()==NULL){
		node->setcode(c);
		printNode(node);
		return;}
	else{
		printNode(node);
		cout<<"Traverse to the left..."<<endl;
		huffmanTree(node->getleft(),c+"0");
		printNode(node);
		cout<<"Traverse to the right..."<<endl;
		huffmanTree(node->getright(),c+"1");
	}
}
int printTable(node *node, int total){

	if (node->getleft()==NULL){
		table(node);
		return (node->getprob())*(node->getcode().size())+total;
	}
	else{
		total=printTable(node->getleft(),total);
		total=printTable(node->getright(),total);
		return total;
	}
}


int main(){
	int totalEntropy=0;
    LinkedList list;
    string c="";
    node *h = new node(-1);     
    ifstream myfile;
    myfile.open("Project5.txt");
    while(!myfile.eof()){
        int n;
        string s;
        myfile>>s>>n;
        node *newNode = new node(s,n);
        list.insertionSort(h,newNode);
	}
    cout<<"List: ";
    list.print(h);
    cout<<endl;      
    cout<<"Constructing the tree: "<<endl;
    tree(h,list);
    cout<<endl;
    cout<<"Traversing the tree..."<<endl;
    huffmanTree(h->getnext(), c);
    cout<<"|   Char   |   Prob   |   Code   |   #bit   |   Entropy   |"<<endl;
	totalEntropy=printTable(h->getnext(),totalEntropy);
	cout<<endl;

	cout<<"Total Entropy: "<<totalEntropy<<"% = "<<double(totalEntropy)/100<<endl;
    myfile.close();
}
