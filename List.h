#include <iostream>

template <typename T>
class List{
		private:
		
	public:
	struct Node{
			T val;
			Node* pre;
			Node* next;
			Node(T d){
				val = d;
				pre = nullptr;
				next = nullptr;
			}
			Node(){
				pre = nullptr;
				next = nullptr;
				val = nullptr;
			}
		};
		int size;
		Node* head;
		List<T>()
		{
			head = nullptr;
			size = 0;
		}
		
		/*List(const List<T>& m){}*/
		
		/*List(List<T>&& m){}*/
		
		void deleteList(){
			Node* current = head;
			Node* temp;
			while(current!= nullptr){
				temp = current->next;
				deleteNode(current);
				Node* current = temp;
			}
		}
		
		void deleteNode(Node* a){
			delete a;
		}
		
		~List<T>(){
			deleteList();
			size = 0;
		}
		
		List<T> & operator +=(T data){
			insert(data);
			return *this;
		}
		
		/*List<T> operator =(List<T>& a){
			
		}*/
		
		
		

		T& operator [](int index){
			T* current ;
			Node* temp = head; 
			if((index>=size)||(index<0)){
				std::cerr << "BAD INDEX" <<std::endl;
				exit(1);
			}
			else{
				for(int i = 0; i<index; ++i){
					current = temp->val;
					temp = temp->next;
				}
			}
			return *current;
		}
		
		void insert(T& data){
			Node* current;
			Node* temp;
			if(head == nullptr){//head insert 
				head->val = data;
				++size;
			}
			else{
				current = head;
				while((data > current->val)&&(current->next != nullptr)){
					if(data = current->val)
					return;
					current = current->next;
				}
				if((current == head)&&(head->val > data)){// before head insert
					temp = head;
					head = new Node(data);
					head->next = temp;
					temp->pre = head;
					++size;
				}
				else{
					if(current->next == nullptr){// insert in tail
						temp = new Node(data);
						temp->pre = current;
						current->next = temp;
						++size;
					}
					else{//insert in middle
						temp = current->pre;
						Node* new_node = new Node(data);
						new_node->pre = temp;
						temp->next = new_node;
						current->pre = new_node;
						new_node->next = current;
						++size;
					}	
				}
			}
		}
		
		template <typename U>
		friend std::ostream & operator <<(std::ostream& out,const List<U>& a);
};

template <typename U>
std::ostream & operator <<(std::ostream& out,const List<U>& a){
	int i = 0;
	List<U>::Node* temp = a.head;
	while(i<a.size){
		out << temp->val << std::endl;
		temp = temp->next;
		++i;
	}
	return out;
}
